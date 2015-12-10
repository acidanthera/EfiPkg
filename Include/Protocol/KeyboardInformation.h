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
/// @file      Include/Protocol/KeyboardInformation.h
///
///            
///
/// @author    Download-Fritz
/// @date      13/10/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __EFI_KEYBOARD_INFORMATION_H__
#define __EFI_KEYBOARD_INFORMATION_H__

// EFI_KEYBOARD_INFORMATION_PROTOCOL_GUID
#define EFI_KEYBOARD_INFORMATION_PROTOCOL_GUID \
  { 0xE82A0A1E, 0x0E4D, 0x45AC, { 0xA6, 0xDC, 0x2A, 0xE0, 0x58, 0x00, 0xD3, 0x11 } }

// KEYBOARD_INFO_GET_INFO
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *KEYBOARD_INFO_GET_INFO)(
  OUT UINT16  *IdVendor,
  OUT UINT16  *IdProduct,
  OUT UINT8   *CountryCode
  );

// EFI_KEYBOARD_INFORMATION_PROTOCOL
typedef struct _EFI_KEYBOARD_INFORMATION_PROTOCOL {
  KEYBOARD_INFO_GET_INFO GetInfo;  ///< 
} EFI_KEYBOARD_INFORMATION_PROTOCOL;

// gEfiKeyboardInformationProtocolGuid
extern EFI_GUID gEfiKeyboardInformationProtocolGuid;

#endif // ifndef __EFI_KEYBOARD_INFORMATION_H__
