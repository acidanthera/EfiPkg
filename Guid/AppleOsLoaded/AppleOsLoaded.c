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
/// @file      Guid/AppleOsLoaded/AppleOsLoaded.c
///
///            
///
/// @author    Download-Fritz
/// @date      18/07/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

// 20/11/2015

#include <AppleEfi.h>

#include <Guid/AppleOsLoaded.h>

// gAppleOsLoadedNamedEventGuid
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gAppleOsLoadedNamedEventGuid = APPLE_OS_LOADED_EVENT_NAME_GUID;

EFI_GUID_STRING (&gAppleOsLoadedNamedEventGuid, "Apple OS Loaded", "Apple OS Loaded Event Name");
