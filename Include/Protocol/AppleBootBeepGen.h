//
// Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
//
// This program and the accompanying materials have not been licensed.
// Neither is its usage, its redistribution, in source or binary form,
// licensed, nor implicitely or explicitely permitted, except when
// required by applicable law.
//
// Unless required by applicable law or agreed to in writing, software
// distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
// OR CONDITIONS OF ANY KIND, either express or implied.
//

///
/// @file      Include/Protocol/AppleBootBeepGen.h
///
///            
///
/// @author    Download-Fritz
/// @date      
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_BOOT_BEEP_GEN_H__
#define __APPLE_BOOT_BEEP_GEN_H__

// APPLE_BOOT_BEEP_GEN_PROTOCOL_GUID
#define APPLE_BOOT_BEEP_GEN_PROTOCOL_GUID \
  { 0xC32332DF, 0xFC56, 0x4FE1, { 0x93, 0x58, 0xBA, 0x0D, 0x52, 0x9B, 0x24, 0xCD } }

// APPLE_BEEP_GEN_BEEP
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *APPLE_BEEP_GEN_BEEP)(
  IN UINTN  NoProtocolCallsStalls,
  IN UINTN  StallMicrosecs1, 
  IN UINTN  StallMicrosecs2
  );

// _APPLE_BOOT_BEEP_GEN_PROTOCOL
typedef struct _APPLE_BOOT_BEEP_GEN_PROTOCOL {
  APPLE_BEEP_GEN_BEEP AppleBeepGenBeep;  ///< Pointer to the function generating the boot beep.
} APPLE_BOOT_BEEP_GEN_PROTOCOL;

// gAppleBootBeepGenProtocolGuid
extern EFI_GUID gAppleBootBeepGenProtocolGuid;

#endif // ifndef __APPLE_BOOT_BEEP_GEN_H__
