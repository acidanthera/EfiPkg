/** @file
  Copyright (C) 2005 - 2015 Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#include <AppleEfi.h>

#include APPLE_PROTOCOL_DEFINITION (KeyboardInfo)

// gEfiKeyboardInfoProtocolGuid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiKeyboardInfoProtocolGuid = EFI_KEYBOARD_INFO_PROTOCOL_GUID;

EFI_GUID_STRING (&gEfiKeyboardInfoProtocolGuid, "Keyboard Information", "Keyboard Information Protocol");
