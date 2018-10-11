/** @file
Copyright (C) 2014 - 2017, Download-Fritz.  All rights reserved.<BR>
This program and the accompanying materials are licensed and made available
under the terms and conditions of the BSD License which accompanies this
distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef APPLE_SMBIOS_H_
#define APPLE_SMBIOS_H_

#include <IndustryStandard/SmBios.h>

#pragma pack (1)

#define APPLE_SMBIOS_TYPE_FIRMWARE_INFORMATION  128
#define APPLE_SMBIOS_TYPE_MEMORY_SPD_DATA       130
#define APPLE_SMBIOS_TYPE_PROCESSOR_TYPE        131
#define APPLE_SMBIOS_TYPE_PROCESSOR_BUS_SPEED   132
#define APPLE_SMBIOS_TYPE_PLATFORM_FEATURE      133
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
    UINT16           MemoryDeviceHandle;
    UINT16           Offset;
    UINT16           Size;
  }                Hdr;
  UINT16           Data[];
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

// APPLE_SMBIOS_TABLE_TYPE133
typedef struct {
  SMBIOS_STRUCTURE Hdr;
  UINT64           PlatformFeature;
} APPLE_SMBIOS_TABLE_TYPE133;

// APPLE_SMBIOS_TABLE_TYPE134
typedef PACKED struct {
  SMBIOS_STRUCTURE Hdr;
  UINT8            SmcVersion[16];
} APPLE_SMBIOS_TABLE_TYPE134;

// APPLE_SMBIOS_STRUCTURE_POINTER
typedef union {
  SMBIOS_STRUCTURE_POINTER   Standard;
  APPLE_SMBIOS_TABLE_TYPE128 *Type128;
  APPLE_SMBIOS_TABLE_TYPE130 *Type130;
  APPLE_SMBIOS_TABLE_TYPE131 *Type131;
  APPLE_SMBIOS_TABLE_TYPE132 *Type132;
  APPLE_SMBIOS_TABLE_TYPE133 *Type133;
  APPLE_SMBIOS_TABLE_TYPE134 *Type134;
  UINT8                      *Raw;
} APPLE_SMBIOS_STRUCTURE_POINTER;

#pragma pack ()

#endif // APPLE_SMBIOS_H_
