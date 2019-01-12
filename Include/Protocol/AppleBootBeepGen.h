/** @file
Copyright (C) 2014 - 2016, Download-Fritz.  All rights reserved.<BR>
This program and the accompanying materials are licensed and made available
under the terms and conditions of the BSD License which accompanies this
distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef APPLE_BOOT_BEEP_GEN_H
#define APPLE_BOOT_BEEP_GEN_H

// APPLE_BOOT_BEEP_GEN_PROTOCOL_GUID
#define APPLE_BOOT_BEEP_GEN_PROTOCOL_GUID                 \
  { 0xC32332DF, 0xFC56, 0x4FE1,                           \
    { 0x93, 0x58, 0xBA, 0x0D, 0x52, 0x9B, 0x24, 0xCD } }

// APPLE_BEEP_GEN_BEEP
typedef
EFI_STATUS
(EFIAPI *APPLE_BEEP_GEN_BEEP)(
  IN UINTN  NoProtocolCallsStalls,
  IN UINTN  StallMicrosecs1, 
  IN UINTN  StallMicrosecs2
  );

// APPLE_BOOT_BEEP_GEN_PROTOCOL
typedef struct {
  /// Pointer to the function generating the boot beep.
  APPLE_BEEP_GEN_BEEP AppleBeepGenBeep;
} APPLE_BOOT_BEEP_GEN_PROTOCOL;

// gAppleBootBeepGenProtocolGuid
extern EFI_GUID gAppleBootBeepGenProtocolGuid;

#endif // APPLE_BOOT_BEEP_GEN_H
