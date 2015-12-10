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
/// @file      Include/Protocol/AppleDeviceControl.h
///
///            
///
/// @author    tiamo
/// @date      28/08/2012: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.

// TODO: headers conflict

#ifndef __APPLE_DEVICE_CONTROL_H__
#define __APPLE_DEVICE_CONTROL_H__

// APPLE_DEVICE_CONTROL_PROTOCOL_GUID
#define APPLE_DEVICE_CONTROL_PROTOCOL_GUID \
  { 0x8ECE08D8, 0xA6D4, 0x430B, { 0xA7, 0xB0, 0x2D, 0xF3, 0x18, 0xE7, 0x88, 0x4A } }

// DEVICE_CONTROL_CONNECT_DISPLAY
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *DEVICE_CONTROL_CONNECT_DISPLAY)(
  VOID
  );

// DEVICE_CONTROL_CONNECT_ALL
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *DEVICE_CONTROL_CONNECT_ALL)(
  VOID
  );

// _APPLE_DEVICE_CONTROL_PROTOCOL
typedef struct _APPLE_DEVICE_CONTROL_PROTOCOL {
  UINTN                          Unknown0;        ///< 
  DEVICE_CONTROL_CONNECT_DISPLAY ConnectDisplay;  ///< 
  UINTN                          Unknown2;        ///< 
  DEVICE_CONTROL_CONNECT_ALL     ConnectAll;      ///< 
} APPLE_DEVICE_CONTROL_PROTOCOL;

// gAppleDeviceControlProtocolGuid
extern EFI_GUID gAppleDeviceControlProtocolGuid;

#endif // ifndef __APPLE_DEVICE_CONTROL_H__


#ifndef __APPLE_DEVICE_CONTROL_H__
#define _APPLE_DEVICE_CONTROL_H_

// APPLE_DEVICE_CONTROL_PROTOCOL_GUID
#define APPLE_DEVICE_CONTROL_PROTOCOL_GUID \
  { 0x8ECE08D8, 0xA6D4, 0x430B, { 0xA7, 0xB0, 0x2D, 0xF3, 0x18, 0xE7, 0x88, 0x4A } }

typedef struct _APPLE_DEVICE_CONTROL_PROTOCOL APPLE_DEVICE_CONTROL_PROTOCOL;

// DEVICE_CONTROL_RESTORE_CONFIG
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *DEVICE_CONTROL_RESTORE_CONFIG)(
  APPLE_DEVICE_CONTROL_PROTOCOL *This,
  UINT32                        Param1,
  UINT32                        Param2,
  VOID                          *Param3,
  VOID                          *Param4,
  VOID                          *Param5
  );

// _APPLE_DEVICE_CONTROL_PROTOCOL
struct _APPLE_DEVICE_CONTROL_PROTOCOL {
  UINTN                         Unknown0;       ///< 
  DEVICE_CONTROL_RESTORE_CONFIG RestoreConfig;  ///< 
};

// gAppleDeviceControlProtocolGuid
extern EFI_GUID gAppleDeviceControlProtocolGuid;

#endif // ifndef __APPLE_DEVICE_CONTROL_H__
