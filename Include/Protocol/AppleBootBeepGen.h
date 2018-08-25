/** @file
  Copyright (C) 2014 - 2016, CupertinoNet.  All rights reserved.<BR>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
**/

#ifndef APPLE_BOOT_BEEP_GEN_H_
#define APPLE_BOOT_BEEP_GEN_H_

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

#endif // APPLE_BOOT_BEEP_GEN_H_
