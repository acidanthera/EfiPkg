/** @file
Copyright (C) 2014 - 2017, Download-Fritz.  All rights reserved.<BR>
This program and the accompanying materials are licensed and made available
under the terms and conditions of the BSD License which accompanies this
distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef APPLE_VARIABLE_H
#define APPLE_VARIABLE_H

#include <Uefi.h>

///
/// The Apple Vendor Variable-vendor GUID.
///
#define APPLE_VENDOR_VARIABLE_GUID  \
  { 0x4D1EDE05, 0x38C7, 0x4A6A,     \
    { 0x9C, 0xC6, 0x4B, 0xCC, 0xA8, 0xB3, 0x8C, 0x14 } }

///
/// The Apple boot Variable-vendor GUID.
///
#define APPLE_BOOT_VARIABLE_GUID  \
  { 0x7C436110, 0xAB2A, 0x4BBB,   \
    { 0xA8, 0x80, 0xFE, 0x41, 0x99, 0x5C, 0x9F, 0x82 } }

///
/// The Apple Core Storage Variable-vendor GUID.
///
#define APPLE_CORE_STORAGE_VARIABLE_GUID  \
  { 0x8D63D4FE, 0xBD3C, 0x4AAD,           \
    { 0x88, 0x1D, 0x86, 0xFD, 0x97, 0x4B, 0xC1, 0xDF } }

///
/// The Apple TRB Variable-vendor GUID.
///
#define APPLE_TAMPER_RESISTANT_BOOT_VARIABLE_GUID  \
  { 0x5D62B28D, 0x6ED2, 0x40B4,                    \
    { 0xA5, 0x60, 0x6C, 0xD7, 0x9B, 0x93, 0xD3, 0x66 } }

///
/// The Apple TRB EFI User GUID.
///
#define APPLE_TAMPER_RESISTANT_BOOT_EFI_USER_GUID  \
  { 0x4E8023FF, 0xA79A, 0x47D1,                    \
    { 0xA3, 0x42, 0x75, 0x24, 0xCF, 0xC9, 0x6D, 0xC4 } }

///
/// The Apple WiFi Network Variable-vendor GUID.
///
#define APPLE_WIRELESS_NETWORK_VARIABLE_GUID  \
  { 0x36C28AB5, 0x6566, 0x4C50,               \
    { 0x9E, 0xBD, 0xCB, 0xB9, 0x20, 0xF8, 0x38, 0x43 } }

///
/// The Apple Personalization Variable-vendor GUID.
///
#define APPLE_PERSONALIZATION_VARIABLE_GUID  \
  { 0xFA4CE28D, 0xB62F, 0x4C99,              \
    { 0x9C, 0xC3, 0x68, 0x15, 0x68, 0x6E, 0x30, 0xF9 } }

///
/// The Apple TRB Secure Variable-vendor GUID.
///
#define APPLE_TAMPER_RESISTANT_BOOT_SECURE_VARIABLE_GUID  \
  { 0xF68DA75E, 0x1B55, 0x4E70,                           \
    { 0xB4, 0x1B, 0xA7, 0xB7, 0xA5, 0xB7, 0x58, 0xEA } }

///
/// The Apple Netboot Variable-vendor GUID.
///
#define APPLE_NETBOOT_VARIABLE_GUID  \
  { 0x37BCBEC7, 0xA645, 0x4215,      \
    { 0x97, 0x9E, 0xF5, 0xAE, 0x4D, 0x11, 0x5F, 0x13 } }

///
/// The Apple Secure Boot Variable-vendor GUID.
///
#define APPLE_SECURE_BOOT_VARIABLE_GUID  \
  { 0x94B73556, 0x2197, 0x4702,          \
    { 0x82, 0xA8, 0x3E, 0x13, 0x37, 0xDA, 0xFB, 0xFB } }

///
/// The Apple Recovery Variable-vendor GUID.
///
#define APPLE_RECOVERY_VARIABLE_GUID     \
  { 0x5EEB160F, 0x45FB, 0x4CE9,          \
    { 0xB4, 0xE3, 0x61, 0x03, 0x59, 0xAB, 0xF6, 0xF8 } }

///
/// A global variable storing the GUID of the APPLE_VENDOR EFI variable scope.
///
extern EFI_GUID gAppleVendorVariableGuid;

///
/// A global variable storing the GUID of the APPLE_BOOT EFI variable scope.
///
extern EFI_GUID gAppleBootVariableGuid;

///
/// A global variable storing the GUID of the APPLE_CORE_STORAGE EFI variable
/// scope.
///
extern EFI_GUID gAppleCoreStorageNvramGuid;

///
/// A global variable storing the GUID of the APPLE_TAMPER_RESISTANT_BOOT EFI
/// variable scope.
///
extern EFI_GUID gAppleTamperResistantBootVariableGuid;

///
/// A global variable storing the GUID of the APPLE_WIRELESS_NETWORK EFI
/// variable scope.
///
extern EFI_GUID gAppleWirelessNetworkVariableGuid;

///
/// A global variable storing the GUID of the APPLE_PERSONALIZATION EFI
/// variable scope.
///
extern EFI_GUID gApplePersonalizationVariableGuid;

///
/// A global variable storing the GUID of
/// the APPLE_TAMPER_RESISTANT_BOOT_SECURE_VARIABLE_GUID EFI variable scope.
///
extern EFI_GUID gAppleTamperResistantBootSecureVariableGuid;

///
/// A global variable storing the GUID of
/// the APPLE_TAMPER_RESISTANT_BOOT_EFI_USER_VARIABLE_GUID EFI variable scope.
///
extern EFI_GUID gAppleTamperResistantBootEfiUserVariableGuid;

///
/// A global variable storing the GUID of the APPLE_NETBOOT EFI variable
/// scope.
///
extern EFI_GUID gAppleNetbootVariableGuid;

///
/// A global variable storing the GUID of the APPLE_SECURE_BOOT_VARIABLE_GUID
/// EFI variable  scope.
///
extern EFI_GUID gAppleSecureBootVariableGuid;

///
/// A global variable storing the GUID of the APPLE_RECOVERY variable scope.
///
extern EFI_GUID gAppleRecoveryVariableGuid;

#endif // APPLE_VARIABLE_H
