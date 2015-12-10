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
/// @file      Guid/AppleBless/AppleBless.h
///
///            Apple protocol to get a volume's bootable file.
///
/// @author    Download-Fritz
/// @date      04/03/2014: Initial version
/// @date      28/03/2015: Updated documentation
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_BLESS_H__
#define __APPLE_BLESS_H__

// APPLE_BLESSED_FILE_INFO_ID
/// InformationType GUID exposed by HFSPlus.efi and AppleLegacyBootFS.efi
/// used to get the blessed file's path.
#define APPLE_BLESSED_FILE_INFO_ID \
  { 0xCA7E4814, 0x2ADC, 0x4ADD, { 0xAB, 0xFF, 0x73, 0x4E, 0x3C, 0xFE, 0x13, 0xF3 } }

// APPLE_BLESSED_FOLDER_INFO_ID
/// InformationType GUID exposed by HFSPlus.efi and AppleLegacyBootFS.efi
/// used to get the blessed folder's path.
#define APPLE_BLESSED_FOLDER_INFO_ID \
  { 0x7BD1F02D, 0x9C2F, 0x4581, { 0xBF, 0x12, 0xD5, 0x4a, 0xBA, 0x0D, 0x98, 0xD6 } }

// gAppleBlessedFileInfoId
/// A global variable storing the GUID of the APPLE_BLESSED_FILE_INFO_ID.
extern EFI_GUID gAppleBlessedFileInfoId;

// gBlessedFolderInfoGuid
/// A global variable storing the GUID of the APPLE_BLESSED_FOLDER_INFO_ID.
extern EFI_GUID gAppleBlessedFolderInfoId;

#endif // ifndef __APPLE_BLESS_H__
