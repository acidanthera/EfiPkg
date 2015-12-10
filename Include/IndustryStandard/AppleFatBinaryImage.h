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
/// @file      Include/IndustryStandard/AppleFatBinaryImage.h
///
///            
///
/// @author    Download-Fritz
/// @date      
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_FAT_BINARY_IMAGE_H__
#define __APPLE_FAT_BINARY_IMAGE_H__

// FAT_BINARY_SIGNATURE
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define EFI_FAT_BINARY_SIGNATURE  0x0EF1FAB9

// MACHO_FAT_BINARY_MAGIC
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define MACHO_FAT_BINARY_SIGNATURE  0xCAFEBABE

// MACHO_FAT_BINARY_SIGNATURE
/// The common "Fat Binary Magic" number used to identify a Fat binary.
#define MACHO_FAT_BINARY_INVERT_SIGNATURE  0xBEBAFECA

// FAT_ARCH
/// Defintion of the the Fat architecture-specific file header.
typedef struct _FAT_ARCH {
	CPU_TYPE    CpuType;     ///< The found CPU architecture specifier.
	CPU_SUBTYPE CpuSubtype;  ///< The found CPU sub-architecture specifier.
	UINT32      Offset;      ///< The offset of the architecture-specific boot file.
	UINT32      Size;        ///< The size of the architecture-specific boot file.
	UINT32      Alignment;   ///< The alignment as a power of 2 (necessary for the x86_64 architecture).
} FAT_ARCH;

// FAT_HEADER
/// Defintion of the Fat file header
typedef struct _FAT_HEADER {
	UINT32   Signature;  ///< The assumed "Fat Binary Magic" number found in the file.
	UINT32   NoFatArch;  ///< The hard-coded number of architectures within the file.
	FAT_ARCH FatArch;    ///< The first FAT_ARCH child of the FAT binary.
} FAT_HEADER;

#endif // ifndef __APPLE_FAT_BINARY_IMAGE_H__
