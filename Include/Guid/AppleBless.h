/** @file
  Apple protocol to get a volume's bootable file.

  Copyright (C) 2005 - 2016, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_BLESS_H_
#define APPLE_BLESS_H_

// APPLE_BLESSED_SYSTEM_FILE_INFO_GUID
/// InformationType GUID used to get the blessed file's path.
#define APPLE_BLESSED_SYSTEM_FILE_INFO_GUID               \
  { 0xCA7E4814, 0x2ADC, 0x4ADD,                           \
    { 0xAB, 0xFF, 0x73, 0x4E, 0x3C, 0xFE, 0x13, 0xF3 } }

// APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID
/// InformationType GUID exposed used to get the blessed folder's path.
#define APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID             \
  { 0x7BD1F02D, 0x9C2F, 0x4581,                           \
    { 0xBF, 0x12, 0xD5, 0x4a, 0xBA, 0x0D, 0x98, 0xD6 } }

// APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID
/// InformationType GUID exposed used to get the blessed folder's path.
#define APPLE_BLESSED_OSX_FOLDER_INFO_GUID                \
  { 0x893CA450, 0x5F5E, 0x48BA,                           \
    { 0x85, 0x8F, 0x08, 0xC4, 0x5D, 0x80, 0x23, 0x18 } }

// gAppleBlessedSystemFileInfoGuid
/// A global variable storing the GUID of the APPLE_BLESSED_SYSTEM_FILE_INFO_GUID.
extern EFI_GUID gAppleBlessedSystemFileInfoGuid;

// gAppleBlessedSystemFolderInfoGuid
/// A global variable storing the GUID of the APPLE_BLESSED_SYSTEM_FOLDER_INFO_GUID.
extern EFI_GUID gAppleBlessedSystemFolderInfoGuid;

// gAppleBlessedOsxFolderInfoGuid
/// A global variable storing the GUID of the APPLE_BLESSED_OSX_FOLDER_INFO_GUID.
extern EFI_GUID gAppleBlessedOsxFolderInfoGuid;

#endif // APPLE_BLESS_H_
