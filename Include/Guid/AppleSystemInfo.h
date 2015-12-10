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
/// @file      Include/Guid/AppleSystemInfo.h
///
///            
///
/// @author    Download-Fritz
/// @date      
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_SYSTEM_INFO_H__
#define __APPLE_SYSTEM_INFO_H__

// APPLE_SYSTEM_INFO_PRODUCER_NAME_GUID
#define APPLE_SYSTEM_INFO_PRODUCER_NAME_GUID \
  { 0x64517CC8, 0x6561, 0x4051, { 0xB0, 0x3C, 0x59, 0x64, 0xB6, 0x0F, 0x4C, 0x7A } }

// _APPLE_SYSTEM_INFO_DATA_RECORD
typedef struct _APPLE_SYSTEM_INFO_DATA_RECORD {
  EFI_SUBCLASS_TYPE1_HEADER Header;     ///< 
  UINT32                    NameSize;   ///< 
  UINT32                    ValueSize;  ///< 
} APPLE_SYSTEM_INFO_DATA_RECORD;

// gAppleSystemInfoProducerNameGuid
extern EFI_GUID gAppleSystemInfoProducerNameGuid;

#endif // ifndef __APPLE_SYSTEM_INFO_H__
