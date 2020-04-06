/** @file
  Copyright (C) 2020, vit9696. All rights reserved.

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#ifndef APPLE_DISK_LABEL_H
#define APPLE_DISK_LABEL_H

///
/// Magic number used to identify the disk label.
///
#define APPLE_DISK_LABEL_VERSION    1

///
/// Maximum disk label width and height for 1x scale.
///
#define APPLE_DISK_LABEL_MAX_WIDTH  340U
#define APPLE_DISK_LABEL_MAX_HEIGHT 12U

#pragma pack(push, 1)

///
/// Apple disk label structure, all fields are Big Endian.
///
typedef struct APPLE_DISK_LABEL_ {
  UINT8   Version;
  UINT16  Width;
  UINT16  Height;
  UINT8   Data[];
} APPLE_DISK_LABEL;

#pragma pack(pop)

#endif // APPLE_DISK_LABEL_H
