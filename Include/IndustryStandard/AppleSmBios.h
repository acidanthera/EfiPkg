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

#ifndef APPLE_SMBIOS_H_
#define APPLE_SMBIOS_H_

#include <IndustryStandard/SmBios.h>

#pragma pack (1)

#define APPLE_SMBIOS_TYPE_FIRMWARE_INFORMATION  128
#define APPLE_SMBIOS_TYPE_MEMORY_SPD_DATA       130
#define APPLE_SMBIOS_TYPE_PROCESSOR_TYPE        131
#define APPLE_SMBIOS_TYPE_PROCESSOR_BUS_SPEED   132
#define APPLE_SMBIOS_TYPE_SMC_INFORMATION       134

#define APPLE_NUMBER_OF_FLASHMAP_ENTRIES  8

// APPLE_REGION_TYPE
enum {
  AppleRegionTypeReserved  = 0,
  AppleRegionTypeRecovery  = 1,
  AppleRegionTypeMain      = 2,
  AppleRegionTypeNvram     = 3,
  AppleRegionTypeConfig    = 4,
  AppleRegionTypeDiagvault = 5
};

typedef UINT8 APPLE_REGION_TYPE;

// APPLE_FIRMWARE_REGION_INFO
typedef PACKED struct {
  UINT32 StartAddress;
  UINT32 EndAddress;
} APPLE_FIRMWARE_REGION_INFO;

// APPLE_SMBIOS_TABLE_TYPE128
typedef PACKED struct {
  SMBIOS_STRUCTURE           Hdr;
  UINT8                      NumberOfRegions;
  UINT8                      Reserved[3];
  UINT32                     FirmwareFeatures;
  UINT32                     FirmwareFeaturesMask;
  APPLE_REGION_TYPE          RegionTypeMap[APPLE_NUMBER_OF_FLASHMAP_ENTRIES];
  APPLE_FIRMWARE_REGION_INFO FlashMap[APPLE_NUMBER_OF_FLASHMAP_ENTRIES];
  UINT32                     ExtendedFirmwareFeatures;
  UINT32                     ExtendedFirmwareFeaturesMask;
} APPLE_SMBIOS_TABLE_TYPE128;

// APPLE_SMBIOS_TABLE_TYPE130
typedef struct {
  struct {
    SMBIOS_STRUCTURE Hdr;
    SMBIOS_HANDLE    MemoryDeviceHandle;
    UINT16           Offset;
    UINT16           Size;
  }                Hdr;
  UINT16           Data[1];
} APPLE_SMBIOS_TABLE_TYPE130;

// APPLE_PROCESSOR_TYPE
enum {
  AppleProcessorClassI5 = 6,
  AppleProcessorClassI7 = 7,
  AppleProcessorClassI3 = 9,
  AppleProcessorClassM3 = 12,
  AppleProcessorClassM5 = 13,
  AppleProcessorClassM7 = 14
};

typedef UINT8 APPLE_PROCESSOR_TYPE[2];

// APPLE_SMBIOS_TABLE_TYPE131
typedef PACKED struct {
  SMBIOS_STRUCTURE     Hdr;
  APPLE_PROCESSOR_TYPE ProcessorType;
  UINT8                Reserved[2];
} APPLE_SMBIOS_TABLE_TYPE131;

// APPLE_SMBIOS_TABLE_TYPE132
typedef struct {
  SMBIOS_STRUCTURE Hdr;
  UINT16           ProcessorBusSpeed;
} APPLE_SMBIOS_TABLE_TYPE132;

// APPLE_SMBIOS_TABLE_TYPE134
typedef PACKED struct {
  SMBIOS_STRUCTURE Hdr;
  UINT8            SmcVersion[16];
} APPLE_SMBIOS_TABLE_TYPE134;

// APPLE_SMBIOS_STRUCTURE_POINTER
typedef union {
  SMBIOS_STRUCTURE           *Hdr;
  SMBIOS_TABLE_TYPE0         *Type0;
  SMBIOS_TABLE_TYPE1         *Type1;
  SMBIOS_TABLE_TYPE2         *Type2;
  SMBIOS_TABLE_TYPE3         *Type3;
  SMBIOS_TABLE_TYPE4         *Type4;
  SMBIOS_TABLE_TYPE5         *Type5;
  SMBIOS_TABLE_TYPE6         *Type6;
  SMBIOS_TABLE_TYPE7         *Type7;
  SMBIOS_TABLE_TYPE8         *Type8;
  SMBIOS_TABLE_TYPE9         *Type9;
  SMBIOS_TABLE_TYPE10        *Type10;
  SMBIOS_TABLE_TYPE11        *Type11;
  SMBIOS_TABLE_TYPE12        *Type12;
  SMBIOS_TABLE_TYPE13        *Type13;
  SMBIOS_TABLE_TYPE14        *Type14;
  SMBIOS_TABLE_TYPE15        *Type15;
  SMBIOS_TABLE_TYPE16        *Type16;
  SMBIOS_TABLE_TYPE17        *Type17;
  SMBIOS_TABLE_TYPE18        *Type18;
  SMBIOS_TABLE_TYPE19        *Type19;
  SMBIOS_TABLE_TYPE20        *Type20;
  SMBIOS_TABLE_TYPE21        *Type21;
  SMBIOS_TABLE_TYPE22        *Type22;
  SMBIOS_TABLE_TYPE23        *Type23;
  SMBIOS_TABLE_TYPE24        *Type24;
  SMBIOS_TABLE_TYPE25        *Type25;
  SMBIOS_TABLE_TYPE26        *Type26;
  SMBIOS_TABLE_TYPE27        *Type27;
  SMBIOS_TABLE_TYPE28        *Type28;
  SMBIOS_TABLE_TYPE29        *Type29;
  SMBIOS_TABLE_TYPE30        *Type30;
  SMBIOS_TABLE_TYPE31        *Type31;
  SMBIOS_TABLE_TYPE32        *Type32;
  SMBIOS_TABLE_TYPE33        *Type33;
  SMBIOS_TABLE_TYPE34        *Type34;
  SMBIOS_TABLE_TYPE35        *Type35;
  SMBIOS_TABLE_TYPE36        *Type36;
  SMBIOS_TABLE_TYPE37        *Type37;
  SMBIOS_TABLE_TYPE38        *Type38;
  SMBIOS_TABLE_TYPE39        *Type39;
  SMBIOS_TABLE_TYPE40        *Type40;
  SMBIOS_TABLE_TYPE41        *Type41;
  SMBIOS_TABLE_TYPE42        *Type42;
  SMBIOS_TABLE_TYPE43        *Type43;
  SMBIOS_TABLE_TYPE126       *Type126;
  SMBIOS_TABLE_TYPE127       *Type127;
  APPLE_SMBIOS_TABLE_TYPE128 *Type128;
  APPLE_SMBIOS_TABLE_TYPE130 *Type130;
  APPLE_SMBIOS_TABLE_TYPE131 *Type131;
  APPLE_SMBIOS_TABLE_TYPE132 *Type132;
  APPLE_SMBIOS_TABLE_TYPE134 *Type134;
  UINT8                      *Raw;
} APPLE_SMBIOS_STRUCTURE_POINTER;

#pragma pack ()

#endif // APPLE_SMBIOS_H_
