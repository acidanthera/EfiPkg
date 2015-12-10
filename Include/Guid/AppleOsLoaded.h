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
/// @file      Include/Guid/AppleOsLoaded.h
///
///            
///
/// @author    Download-Fritz
/// @date      18/07/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

// 20/11/2015

#ifndef __APPLE_OS_LOADED_H__
#define __APPLE_OS_LOADED_H__

// APPLE_OS_LOADED_EVENT_NAME
#define APPLE_OS_LOADED_EVENT_NAME_GUID \
  { 0xC5C5DA95, 0x7D5C, 0x45E6, { 0x83, 0x72, 0x89, 0xBD, 0x52, 0x6D, 0xE9, 0x56 } }

// gAppleOsLoadedNamedEventGuid
EFI_GUID gAppleOsLoadedNamedEventGuid;

#endif // ifndef __APPLE_OS_LOADED_H__
