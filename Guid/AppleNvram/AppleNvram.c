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

#include APPLE_GUID_DEFINITION (AppleNvram)

// gAppleVendorVariableGuid
/// A global variable storing the GUID of the APPLE_VENDOR EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleVendorVariableGuid = APPLE_VENDOR_VARIABLE_GUID;

// gAppleBootVariableGuid
/// A global variable storing the GUID of the APPLE_BOOT EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleBootVariableGuid = APPLE_BOOT_VARIABLE_GUID;

// gAppleCoreStorageVariableGuid
/// A global variable storing the GUID of the APPLE_CORE_STORAGE EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleCoreStorageVariableGuid = APPLE_CORE_STORAGE_VARIABLE_GUID;

// gAppleTrbStagingCommandVariableGuid
/// A global variable storing the GUID of the APPLE_TRB_STAGING_COMMAND EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleTrbStagingCommandVariableGuid = APPLE_TRB_STAGING_COMMAND_VARIABLE_GUID;

// AppleWirelessNetworkNvramGuid
/// A global variable storing the GUID of the APPLE_WIRELESS_NETWORK EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleWirelessNetworkVariableGuid = APPLE_WIRELESS_NETWORK_VARIABLE_GUID;

// AppleEfiAppearanceNvramGuid
/// A global variable storing the GUID of the APPLE_PERSONALIZATION EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gApplePersonalizationVariableGuid = APPLE_PERSONALIZATION_VARIABLE_GUID;

// gAppleEfiNvramResetGuid
/// A global variable storing the GUID of the APPLE_TRB_SECURE EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleTrbSecureVariableGuid = APPLE_TRB_SECURE_VARIABLE_GUID;
