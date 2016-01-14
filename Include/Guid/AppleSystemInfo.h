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

#ifndef APPLE_SYSTEM_INFO_H_
#define APPLE_SYSTEM_INFO_H_

#include <Guid/DataHubRecords/DataHubSubClass.h>

// APPLE_SYSTEM_INFO_PRODUCER_NAME_GUID
#define APPLE_SYSTEM_INFO_PRODUCER_NAME_GUID \
  { 0x64517CC8, 0x6561, 0x4051, { 0xB0, 0x3C, 0x59, 0x64, 0xB6, 0x0F, 0x4C, 0x7A } }

// APPLE_SYSTEM_INFO_DATA_RECORD
typedef struct {
  EFI_SUBCLASS_TYPE1_HEADER Header;     ///< 
  UINT32                    NameSize;   ///< 
  UINT32                    ValueSize;  ///< 
} APPLE_SYSTEM_INFO_DATA_RECORD;

// gAppleSystemInfoProducerNameGuid
extern EFI_GUID gAppleSystemInfoProducerNameGuid;

#endif // APPLE_SYSTEM_INFO_H_
