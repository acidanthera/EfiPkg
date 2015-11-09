///
/// @file      Protocol/DevicePathPropertyDatabase/DevicePathPropertyDatabase.c
///
///            Apple protocol to manage Device Properties from firmware.
///
/// @author    Download-Fritz
/// @date      23/02/2015: Initial version
/// @date      15/03/2015: Updated documentation
/// @copyright The decompilation is of an educational purpose to better understand the behavior of the
///            Apple EFI implementation and making use of it. In no way is the content's usage licensed
///            or allowed. All rights remain at Apple Inc. To be used under the terms of 'Fair use'.
///

//
// CREDITS:
//   Reversed from EfiDevicePathPropertyDatabase.efi, which is Apple Inc. property
//   Decompiled by Download-Fritz
//

#include <AppleEfi.h>

#include <Protocol/DevicePathPropertyDatabase.h>

// gEfiDevicePathPropertyProtocolGuid
EFI_GUID gEfiDevicePathPropertyDatabaseProtocolGuid = EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL_GUID;

EFI_GUID_STRING (&gEfiDevicePathPropertyDatabaseProtocolGuid, "Device Path Property Database", "Apple Device Path Property Database Protocol");
