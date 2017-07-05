/** @file
  Copyright (c) 2005 - 2016, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2014 - 2016, CupertinoNet.  All rights reserved.<BR>

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

#ifndef EFI_KEYBOARD_INFORMATION_H_
#define EFI_KEYBOARD_INFORMATION_H_

// EFI_KEYBOARD_INFO_PROTOCOL_GUID
#define EFI_KEYBOARD_INFO_PROTOCOL_GUID                   \
  { 0xE82A0A1E, 0x0E4D, 0x45AC,                           \
    { 0xA6, 0xDC, 0x2A, 0xE0, 0x58, 0x00, 0xD3, 0x11 } }

// KEYBOARD_INFO_GET_INFO
typedef
EFI_STATUS
(EFIAPI *KEYBOARD_INFO_GET_INFO)(
  OUT UINT16  *IdVendor,
  OUT UINT16  *IdProduct,
  OUT UINT8   *CountryCode
  );

// EFI_KEYBOARD_INFO_PROTOCOL
typedef struct {
  KEYBOARD_INFO_GET_INFO GetInfo;
} EFI_KEYBOARD_INFO_PROTOCOL;

// gEfiKeyboardInfoProtocolGuid
extern EFI_GUID gEfiKeyboardInfoProtocolGuid;

#endif // EFI_KEYBOARD_INFORMATION_H_
