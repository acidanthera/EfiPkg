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
/// @file      Protocol/AppleDeviceControl/AppleDeviceControl.c
///
///            
///
/// @author    Download-Fritz
/// @date      
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#include <AppleEfi.h>

#include <Protocol/AppleDeviceControl.h>

// gAppleDeviceControlProtocolGuid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleDeviceControlProtocolGuid = APPLE_DEVICE_CONTROL_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleDeviceControlProtocolGuid, "Device Control", "Apple Device Control Protocol");
