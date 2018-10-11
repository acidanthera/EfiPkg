/** @file
Copyright (C) 2014 - 2016, Download-Fritz.  All rights reserved.<BR>
This program and the accompanying materials are licensed and made available
under the terms and conditions of the BSD License which accompanies this
distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

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
  FAT_ARCH FatArch;
} FAT_HEADER;

#pragma pack ()

#endif // APPLE_FAT_BINARY_IMAGE_H_
