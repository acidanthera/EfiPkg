#------------------------------------------------------------------------------
#
# Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>
# This program and the accompanying materials
# are licensed and made available under the terms and conditions of the BSD License
# which accompanies this distribution.  The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php.
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
# Module Name:
#
#   DivU64x64Remainder.S
#
# Abstract:
#
#   Calculate the quotient of a 64-bit integer by a 64-bit integer and returns
#   both the quotient and the remainder
#
#------------------------------------------------------------------------------

ASM_GLOBAL ASM_PFX(InternalMathDivU64x32), ASM_PFX(InternalMathDivU64x64)

#------------------------------------------------------------------------------
#/**
#  Divides a 64-bit unsigned integer by a 32-bit unsigned integer and generates
#  a 64-bit unsigned result.
#
#  This function divides the 64-bit unsigned value Dividend by the 32-bit
#  unsigned value Divisor and generates a 64-bit unsigned quotient.
#  This function returns the 64-bit unsigned quotient.
#
#  @param  Dividend  A 64-bit unsigned value.
#  @param  Divisor   A 32-bit unsigned value.
#
#  @return  Dividend / Divisor.
#**/
# UINT64
# EFIAPI
# InternalMathDivU64x32 (
#   IN UINT64  Dividend,
#   IN UINT32  Divisor
#   );
#------------------------------------------------------------------------------
ASM_PFX(InternalMathDivU64x32):
    movl    8(%esp), %eax
    movl    12(%esp), %ecx
    xorl    %edx, %edx
    divl    %ecx
    push    %eax                    # save quotient on stack
    movl    8(%esp), %eax
    divl    %ecx
    pop     %edx                    # restore high-order dword of the quotient
    ret

#------------------------------------------------------------------------------
#/**
#  Divides a 64-bit unsigned integer by a 64-bit unsigned integer and generates
#  a 64-bit unsigned result.
#
#  This function divides the 64-bit unsigned value Dividend by the 64-bit
#  unsigned value Divisor and generates a 64-bit unsigned quotient.
#  This function returns the 64-bit unsigned quotient.
#
#  @param[in]  Dividend  A 64-bit unsigned value.
#  @param[out] Divisor   A 64-bit unsigned value.
#
#  @return  Dividend / Divisor.
#**/
# UINT64
# EFIAPI
# InternalMathDivU64x64 (
#   IN  UINT64 Dividend,
#   IN  UINT64 Divisor,
#   OUT UINT64 *Remainder OPTIONAL
#   );
#------------------------------------------------------------------------------
ASM_PFX(InternalMathDivU64x64):
    movl    16(%esp), %ecx              # ecx <- divisor[32..63]
    testl   %ecx, %ecx
    jnz     Hard                        # call _@DivRemU64x64 if Divisor > 2^32
    movl    20(%esp), %ecx
    jecxz   L1
    andl     $0, 4(%ecx)                # zero high dword of remainder
    movl    %ecx, 16(%esp)              # set up stack frame to match DivRemU64x32
L1:
    jmp     ASM_PFX(InternalMathDivU64x32)
Hard:
    push    %ebx
    push    %esi
    push    %edi
    mov     20(%esp), %edx
    mov     16(%esp), %eax              # edx:eax <- dividend
    movl    %edx, %edi
    movl    %eax, %esi                  # edi:esi <- dividend
    mov     24(%esp), %ebx              # ecx:ebx <- divisor
L2:
    shrl    %edx
    rcrl    $1, %eax
    shrdl   $1, %ecx, %ebx
    shrl    %ecx
    jnz     L2
    divl    %ebx
    movl    %eax, %ebx                  # ebx <- quotient                     
    movl    28(%esp), %ecx              # ecx <- high dword of divisor        
    mull    24(%esp)                    # edx:eax <- quotient * divisor[0..31]
    imull   %ebx, %ecx                  # ecx <- quotient * divisor[32..63]   
    addl    %ecx, %edx                  # edx <- (quotient * divisor)[32..63]         
    jc      TooLarge                    # product > 2^64                      
    cmpl    %edx, %edi                  # compare high 32 bits                
    ja      Return                                                           
    jb      TooLarge                    # product > dividend                  
    cmpl    %eax, %esi                                                        
    jae     Return                     # product <= dividend                 
TooLarge:
    decl    %ebx                        # adjust quotient by -1              
Return:
    movl    %ebx, %eax                  # eax <- quotient         
    xorl    %edx, %edx                  # quotient is 32 bits long
    pop     %edi
    pop     %esi
    pop     %ebx
    ret
