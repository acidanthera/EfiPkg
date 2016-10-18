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

#include APPLE_GUID_DEFINITION (AppleNvram)

// gAppleVendorVariableGuid
/// A global variable storing the GUID of the APPLE_VENDOR EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleVendorVariableGuid = APPLE_VENDOR_VARIABLE_GUID;

EFI_GUID_STRING (
  &gAppleVendorVariableGuid,
  "Apple Vendor Variable",
  "Apple Vendor Variable"
  );

// gAppleBootVariableGuid
/// A global variable storing the GUID of the APPLE_BOOT EFI variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBootVariableGuid = APPLE_BOOT_VARIABLE_GUID;

EFI_GUID_STRING (
  &gAppleBootVariableGuid,
  "Boot Variable",
  "Apple Boot Variable"
  );

// gAppleCoreStorageVariableGuid
/// A global variable storing the GUID of the APPLE_CORE_STORAGE EFI variable
/// scope.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleCoreStorageVariableGuid = APPLE_CORE_STORAGE_VARIABLE_GUID;

EFI_GUID_STRING (
  &gAppleCoreStorageVariableGuid,
  "Core Storage Variable",
  "Apple Core Storage Variable"
  );

// gAppleTrbStagingCommandVariableGuid
/// A global variable storing the GUID of the APPLE_TRB_STAGING_COMMAND EFI
/// variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleTrbStagingCommandVariableGuid = APPLE_TRB_STAGING_COMMAND_VARIABLE_GUID;

EFI_GUID_STRING (
  &gAppleTrbStagingCommandVariableGuid,
  "TRB Staging Command Variable",
  "Apple TRB Staging Command Variable"
  );

// AppleWirelessNetworkNvramGuid
/// A global variable storing the GUID of the APPLE_WIRELESS_NETWORK EFI
/// variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleWirelessNetworkVariableGuid = APPLE_WIRELESS_NETWORK_VARIABLE_GUID;

EFI_GUID_STRING (
  &gAppleWirelessNetworkVariableGuid,
  "Wireless Network Variable",
  "Apple Wireless Network Variable"
  );

// AppleEfiAppearanceNvramGuid
/// A global variable storing the GUID of the APPLE_PERSONALIZATION EFI
/// variable scope.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gApplePersonalizationVariableGuid = APPLE_PERSONALIZATION_VARIABLE_GUID;

EFI_GUID_STRING (
  &gApplePersonalizationVariableGuid,
  "Personalization Variable",
  "Apple Personalization Variable"
  );

// gAppleEfiNvramResetGuid
/// A global variable storing the GUID of the APPLE_TRB_SECURE EFI variable
/// scope.
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleTrbSecureVariableGuid = APPLE_TRB_SECURE_VARIABLE_GUID;

EFI_GUID_STRING (
  &gAppleTrbSecureVariableGuid,
  "TRB Secure Variable",
  "Apple TRB Secure Variable"
  );
