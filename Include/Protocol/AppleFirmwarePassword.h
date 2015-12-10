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
/// @file      Include/Protocol/AppleFirmwarePassword.h
///
///            
///
/// @author    tiamo
/// @date      26/08/2012: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_FIRMWARE_PASSWORD_H__
#define __APPLE_FIRMWARE_PASSWORD_H__

// APPLE_FIRMWARE_PASSWORD_PROTOCOL_GUID
#define APPLE_FIRMWARE_PASSWORD_PROTOCOL_GUID \
  { 0x8FFEEB3A, 0x4C98, 0x4630, { 0x80, 0x3F, 0x74, 0x0F, 0x95, 0x67, 0x09, 0x1D } }

FORWARD_DECLARATION (APPLE_FIRMWARE_PASSWORD_PROTOCOL);

// FIRMWARE_PASSWORD_CHECK
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *FIRMWARE_PASSWORD_CHECK)(
  IN  APPLE_FIRMWARE_PASSWORD_PROTOCOL  *This,
  OUT UINTN                             *CheckValue
  );

// _APPLE_FIRMWARE_PASSWORD_PROTOCOL
struct _APPLE_FIRMWARE_PASSWORD_PROTOCOL {
  UINT64                  Revision;    ///< 
  UINTN                   Unknown[3];  ///< 
  FIRMWARE_PASSWORD_CHECK Check;       ///< 
};

// gAppleFirmwarePasswordProtocolGuid
extern EFI_GUID gAppleFirmwarePasswordProtocolGuid;

#endif // ifndef __APPLE_FIRMWARE_PASSWORD_H__
