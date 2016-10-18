/** @file
  Copyright (C) 2005 - 2016, Apple Inc.  All rights reserved.
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

#include <AppleEfi.h>

#include APPLE_GUID_DEFINITION (AppleBless)

// gAppleBlessedSystemFileInfoGuid
/// A global variable storing the GUID of the
/// APPLE_BLESSED_SYSTEM_FILE_INFO_GUID.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBlessedSystemFileInfoGuid = APPLE_BLESSED_SYSTEM_FILE_INFO_GUID;

EFI_GUID_STRING (
  &gAppleBlessedSystemFileInfoGuid,
  "Blessed System File",
  "Apple Blessed System File Info"
  );

// gAppleBlessedSystemFolderInfoGuid
/// A global variable storing the GUID of the
/// APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBlessedSystemFolderInfoGuid = APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID;

EFI_GUID_STRING (
  &gAppleBlessedSystemFolderInfoGuid,
  "Blessed System Folder",
  "Apple Blessed System Folder Info"
  );

// gAppleBlessedOsxFolderInfoGuid
/// A global variable storing the GUID of the
/// APPLE_BLESSED_OSX_FOLDER_INFO_GUID.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBlessedOsxFolderInfoGuid = APPLE_BLESSED_OSX_FOLDER_INFO_GUID;

EFI_GUID_STRING (
  &gAppleBlessedOsxFolderInfoGuid,
  "Blessed OS X Folder",
  "Apple Blessed OS X Folder Info"
  );
