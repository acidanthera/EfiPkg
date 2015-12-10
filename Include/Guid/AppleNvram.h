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
/// @file      Include/Guid/AppleNvram.h
///
///            
///
/// @author    Download-Fritz
/// @date      
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_NVRAM_H__
#define __APPLE_NVRAM_H__

// APPLE_VENDOR_NVRAM_GUID
/// The Apple firmware NVRAM-vendor GUID.
#define APPLE_VENDOR_NVRAM_GUID \
  { 0x4D1EDE05, 0x38C7, 0x4A6A, { 0x9C, 0xC6, 0x4B, 0xCC, 0xA8, 0xB3, 0x8C, 0x14 } }

// APPLE_EFI_NVRAM_GUID
/// 
#define APPLE_EFI_NVRAM_GUID \
  0x7C436110, 0xAB2A, 0x4BBB

// APPLE_EFI_NVRAM
/// 
#define APPLE_EFI_NVRAM(Data41, Data42, Data43, Data44, Data45, Data46, Data47, Data48) \
  { APPLE_EFI_NVRAM_GUID, { Data41, Data42, Data43, Data44, Data45, Data46, Data47, Data48 } }

// APPLE_BOOT_GUID
/// The OS X NVRAM-vendor GUID.
#define APPLE_BOOT_GUID \
  APPLE_EFI_NVRAM (0xA8, 0x80, 0xFE, 0x41, 0x99, 0x5C, 0x9F, 0x82)

// APPLE_CORE_STORAGE_GUID
/// The Apple Core Storage NVRAM-vendor GUID.
#define APPLE_CORE_STORAGE_NVRAM_GUID \
  { 0x8D63D4FE, 0xBD3C, 0x4AAD, { 0x88, 0x1D, 0x86, 0xFD, 0x97, 0x4B, 0xC1, 0xDF } }

// APPLE_EFI_NVRAM_TRB_SECURE_GUID
/// The 
#define APPLE_EFI_NVRAM_TRB_STAGING_COMMAND_GUID \
  { 0x5D62B28D, 0x6ED2, 0x40B4, { 0xA5, 0x60, 0x6C, 0xD7, 0x9B, 0x93, 0xD3, 0x66 } }

// APPLE_WIRELESS_NETWORK_NVRAM_GUID
/// The Apple WiFi Network NVRAM-vendor GUID.
#define APPLE_WIRELESS_NETWORK_NVRAM_GUID \
  { 0x36C28AB5, 0x6566, 0x4C50, { 0x9E, 0xBD, 0xCB, 0xB9, 0x20, 0xF8, 0x38, 0x43 } }

// APPLE_EFI_APPEARANCE_NVRAM_GUID
/// The Apple EFI Appearance NVRAM-vendor GUID.
#define APPLE_EFI_APPEARANCE_NVRAM_GUID \
  { 0xFA4CE28D, 0xB62F, 0x4C99, { 0x9C, 0xC3, 0x68, 0x15, 0x68, 0x6E, 0x30, 0xF9 } }

// APPLE_NVRAM_RESET_GUID
/// The Apple EFI NVRAM TRB Secure-vendor GUID.
#define APPLE_EFI_NVRAM_TRB_SECURE_VARIABLE_GUID \
  { 0xF68DA75E, 0x1B55, 0x4E70, { 0xB4, 0x1B, 0xA7, 0xB7, 0xA5, 0xB7, 0x58, 0xEA } }

// gAppleVendorNvramGuid
/// A global variable storing the GUID of the APPLE_VENDOR_NVRAM EFI variable scope.
extern EFI_GUID gAppleVendorNvramGuid;

// gAppleEfiNvramGuid
/// 
extern EFI_GUID gAppleEfiNvramGuid;

// gAppleBootGuid
/// A global variable storing the GUID of the APPLE_BOOT EFI variable scope.
extern EFI_GUID gAppleBootGuid;

// gAppleCoreStorageGuid
/// A global variable storing the GUID of the APPLE_CORE_STORAGE EFI variable scope.
extern EFI_GUID gAppleCoreStorageNvramGuid;

// gAppleEfiNvramTrbSecureGuid
/// A global variable storing the GUID of the APPLE_EFI_NVRAM_TRB_SECURE EFI variable scope.
extern EFI_GUID gAppleEfiNvramTrbStagingCommandGuid;

// AppleWirelessNetworkNvramGuid
/// A global variable storing the GUID of the APPLE_WIRELESS_NETWORK EFI variable scope.
extern EFI_GUID gAppleWirelessNetworkNvramGuid;

// AppleEfiAppearanceNvramGuid
/// A global variable storing the GUID of the APPLE_EFI_APPEARANCE EFI variable scope.
extern EFI_GUID gAppleEfiAppearanceNvramGuid;

// gAppleEfiNvramResetGuid
/// A global variable storing the GUID of the APPLE_EFI_NVRAM_TRB_SECURE EFI variable scope.
extern EFI_GUID gAppleEfiNvramTrbSecureVariableGuid;

#endif // ifndef __APPLE_NVRAM_H__
