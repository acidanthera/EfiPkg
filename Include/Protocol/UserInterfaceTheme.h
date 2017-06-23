/** @file
  Copyright (c) 2005 - 2017, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2017, CupertinoNet.  All rights reserved.<BR>

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

#ifndef USER_INTERFACE_THEME_H_
#define USER_INTERFACE_THEME_H_

// EFI_USER_INTERFACE_THEME_PROTOCOL_GUID
#define EFI_USER_INTERFACE_THEME_PROTOCOL_GUID  \
  { 0xD5B0AC65, 0x9A2D, 0x4D2A,                 \
    { 0xBB, 0xD6, 0xE8, 0x71, 0xA9, 0x5E, 0x04, 0x35 } }

// UI_THEME_GET_BACKGROUND_COLOR
typedef
EFI_STATUS
(EFIAPI *UI_THEME_GET_BACKGROUND_COLOR)(
  IN OUT UINT32  *BackgroundColor
  );

// EFI_USER_INTERFACE_THEME_PROTOCOL
typedef struct {
  UINTN                         Revision;            ///< Revision.
  UI_THEME_GET_BACKGROUND_COLOR GetBackgroundColor;  ///< Present as of Revision 1.
} EFI_USER_INTERFACE_THEME_PROTOCOL;

// gEfiUserInterfaceThemeProtocolGuid
extern EFI_GUID gEfiUserInterfaceThemeProtocolGuid;

#endif // USER_INTERFACE_THEME_H_