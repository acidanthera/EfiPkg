/** @file
  Copyright (c) 2005 - 2016, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2014 - 2016, CupertinoNet.  All rights reserved.<BR>

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

#ifndef APPLE_FAT_BINARY_IMAGE_H_
#define APPLE_FAT_BINARY_IMAGE_H_

// FAT_BINARY_SIGNATURE
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define EFI_FAT_BINARY_SIGNATURE  0x0EF1FAB9

// MACHO_FAT_BINARY_MAGIC
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define MACHO_FAT_BINARY_SIGNATURE  0xCAFEBABE

// MACHO_FAT_BINARY_SIGNATURE
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define MACHO_FAT_BINARY_INVERT_SIGNATURE  0xBEBAFECA

#pragma pack (1)

// FAT_ARCH
/// Defintion of the the Fat architecture-specific file header.
typedef PACKED struct {
  /// The found CPU architecture specifier.
  CPU_TYPE    CpuType;

  /// The found CPU sub-architecture specifier.
  CPU_SUBTYPE CpuSubtype;

  /// The offset of the architecture-specific boot file.
  UINT32      Offset;

  /// The size of the architecture-specific boot file.
  UINT32      Size;

  /// The alignment as a power of 2 (necessary for the x86_64 architecture).
  UINT32      Alignment;
} FAT_ARCH;

// FAT_HEADER
/// Defintion of the Fat file header
typedef PACKED struct {
  struct {
    /// The assumed "Fat Binary Magic" number found in the file.
    UINT32 Signature;

    /// The hard-coded number of architectures within the file.
    UINT32 NumberOfFatArch;
  }        Hdr;

  /// The first FAT_ARCH child of the FAT binary.
  FAT_ARCH FatArch[1];
} FAT_HEADER;

#pragma pack ()

#endif // APPLE_FAT_BINARY_IMAGE_H_
