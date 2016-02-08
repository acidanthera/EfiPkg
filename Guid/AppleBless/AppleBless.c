/** @file
  Copyright (C) 2005 - 2015, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#include <AppleEfi.h>

#include APPLE_GUID_DEFINITION (AppleBless)

// gAppleBlessedSystemFileInfoGuid
/// A global variable storing the GUID of the APPLE_BLESSED_SYSTEM_FILE_INFO_GUID.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID gAppleBlessedSystemFileInfoGuid = APPLE_BLESSED_SYSTEM_FILE_INFO_GUID;

// gAppleBlessedSystemFolderInfoGuid
/// A global variable storing the GUID of the APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID gAppleBlessedSystemFolderInfoGuid = APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID;

// gAppleBlessedOsxFolderInfoGuid
/// A global variable storing the GUID of the APPLE_BLESSED_OSX_FOLDER_INFO_GUID.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID gAppleBlessedOsxFolderInfoGuid = APPLE_BLESSED_OSX_FOLDER_INFO_GUID;
