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

#include APPLE_GUID_DEFINITION (AppleHob)

// gAppleHob1Guid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleHob1Guid = APPLE_HOB_1_GUID;

// gAppleHob1Guid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleHob2Guid = APPLE_HOB_2_GUID;

// gAppleHob1Guid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleHob3Guid = APPLE_HOB_3_GUID;

// gAppleDriverInitHobGuid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleDriverInitHobGuid = APPLE_DRIVER_INIT_HOB_GUID;
