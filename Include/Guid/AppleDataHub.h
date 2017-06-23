/** @file
  Copyright (c) 2005 - 2017, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2014 - 2017, CupertinoNet.  All rights reserved.<BR>

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

#ifndef APPLE_DATA_HUB_H_
#define APPLE_DATA_HUB_H_

#include <Guid/DataHubRecords.h>

// APPLE_PLATFORM_PRODUCER_NAME_GUID
#define APPLE_PLATFORM_PRODUCER_NAME_GUID  \
  { 0x64517CC8, 0x6561, 0x4051,            \
    { 0xB0, 0x3C, 0x59, 0x64, 0xB6, 0x0F, 0x4C, 0x7A } }

// APPLE_ROM_PRODUCER_NAME_GUID
#define APPLE_ROM_PRODUCER_NAME_GUID  \
  { 0xA38DA1AC, 0xA626, 0x4E18,       \
    { 0x93, 0x88, 0x14, 0xB0, 0xE8, 0x2A, 0x54, 0x04 } }

// APPLE_ROM_DATA_RECORD_GUID
#define APPLE_ROM_DATA_RECORD_GUID  \
  { 0x8CBDD607, 0xCAB4, 0x43A4,     \
    { 0x97h, 0x8Bh, 0xABh, 0x8Dh, 0xEFh, 0x11h, 0x06, 0x1C } }

// APPLE_SYSTEM_SERIAL_NUMBER_DATA_RECORD_GUID
#define APPLE_SYSTEM_SERIAL_NUMBER_DATA_RECORD_GUID  \
  { 0x4BAA44C3, 0x9D4D, 0x46A6                       \
    { 0x99, 0x13, 0xAE, 0xF9, 0x0D, 0x3C, 0xC, 0xB1 } }

// APPLE_SYSTEM_ID_DATA_RECORD_GUID
#define APPLE_SYSTEM_ID_DATA_RECORD_GUID  \
  { 0x1485AFA4, 0xF000, 0x4E3E,           \
    { 0x81, 0xB4, 0xA7, 0xEE, 0x10, 0x4D, 0x5E, 0x30 } }

#define APPLE_SUBCLASS_VERSION   0x0100
#define APPLE_SUBCLASS_INSTANCE  EFI_SUBCLASS_INSTANCE_NON_APPLICABLE

// APPLE_PLATFORM_DATA_RECORD
typedef struct {
  struct {
    EFI_SUBCLASS_TYPE1_HEADER Header;
    UINT32                    KeySize;
    UINT32                    ValueSize;
  }      Hdr;
  CHAR16 Key[1];
//UINTN  Value[];
} APPLE_PLATFORM_DATA_RECORD;

// APPLE_ROM_RECORD
typedef struct {
  EFI_SUBCLASS_TYPE1_HEADER Header;
  UINT8                     Reserved1;
  UINT64                    Rom;
  UINT8                     Reserved2[3];
} APPLE_ROM_RECORD;

// gApplePlatformProducerNameGuid
extern EFI_GUID gApplePlatformProducerNameGuid;

// gAppleRomProducerNameGuid
extern EFI_GUID gAppleRomProducerNameGuid;

// gAppleRomDataRecordGuid
extern EFI_GUID gAppleRomDataRecordGuid;

// gAppleSystemSerialNumbrDataRecordGuid
extern EFI_GUID gAppleSystemSerialNumbrDataRecordGuid;

// gAppleSystemIdDataRecordGuid
extern EFI_GUID gAppleSystemIdDataRecordGuid;

#endif // APPLE_DATA_HUB_H_
