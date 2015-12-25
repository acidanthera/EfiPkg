;------------------------------------------------------------------------------
;
; Copyright (c) 2006, Intel Corporation. All rights reserved.<BR>
; This program and the accompanying materials
; are licensed and made available under the terms and conditions of the BSD License
; which accompanies this distribution.  The full text of the license may be found at
; http://opensource.org/licenses/bsd-license.php.
;
; THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
; WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
;
; Module Name:
;
;   DivU64x64Remainder.asm
;
; Abstract:
;
;   Calculate the quotient of a 64-bit integer by a 64-bit integer and returns
;   both the quotient and the remainder
;
;------------------------------------------------------------------------------

    .386
    .model  flat,C
    .code

;------------------------------------------------------------------------------
; UINT64
; EFIAPI
; InternalMathDivU64x32 (
;   IN UINT64  Dividend,
;   IN UINT32  Divisor
;   );
;------------------------------------------------------------------------------
InternalMathDivU64x32   PROC
    mov     eax, [esp + 8]
    mov     ecx, [esp + 12]
    xor     edx, edx
    div     ecx
    push    eax                     ; save quotient on stack
    mov     eax, [esp + 8]
    div     ecx
    pop     edx                     ; restore high-order dword of the quotient
    ret
InternalMathDivU64x32   ENDP

;------------------------------------------------------------------------------
; UINT64
; EFIAPI
; InternalMathDivU64x64 (
;   IN UINT64  Dividend,
;   IN UINT64  Divisor
;   );
;------------------------------------------------------------------------------
InternalMathDivU64x64    PROC
    mov     ecx, [esp + 16]             ; ecx <- divisor[32..63]
    test    ecx, ecx
    jnz     _@DivU64x64                 ; call _@DivU64x64 if Divisor > 2^32
    mov     ecx, [esp + 20]
    jecxz   @F
    mov     [esp + 16], ecx             ; set up stack frame to match DivU64x32
@@:
    jmp     InternalMathDivU64x32
InternalMathDivU64x64    ENDP

_@DivU64x64  PROC    USES    ebx esi edi
    mov     edx, dword ptr [esp + 20]
    mov     eax, dword ptr [esp + 16]   ; edx:eax <- dividend
    mov     edi, edx
    mov     esi, eax                    ; edi:esi <- dividend
    mov     ebx, dword ptr [esp + 24]   ; ecx:ebx <- divisor
@@:
    shr     edx, 1
    rcr     eax, 1
    shrd    ebx, ecx, 1
    shr     ecx, 1
    jnz     @B
    div     ebx
    mov     ebx, eax                    ; ebx <- quotient
    mov     ecx, [esp + 28]             ; ecx <- high dword of divisor
    mul     dword ptr [esp + 24]        ; edx:eax <- quotient * divisor[0..31]
    imul    ecx, ebx                    ; ecx <- quotient * divisor[32..63]
    add     edx, ecx                    ; edx <- (quotient * divisor)[32..63]
    jc      @TooLarge                   ; product > 2^64
    cmp     edi, edx                    ; compare high 32 bits
    ja      @Return
    jb      @TooLarge                   ; product > dividend
    cmp     esi, eax
    jae     @Return                     ; product <= dividend
@TooLarge:
    dec     ebx                         ; adjust quotient by -1
@Return:
    mov     eax, ebx                    ; eax <- quotient
    xor     edx, edx                    ; quotient is 32 bits long
    ret
_@DivU64x64  ENDP

    END
