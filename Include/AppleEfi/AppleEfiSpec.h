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
/// @file      Include/AppleEfi/AppleEfiSpec.h
///
///            
///
/// @author    Download-Fritz
/// @date      18/07/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_EFI_SPEC_H__
#define __APPLE_EFI_SPEC_H__

#include <AppleCpuType.h>

// APPLE_BOOTLOADER_FILE_PATH
/// The default, preferred location of the Apple bootloader
#define APPLE_BOOTER_FILE_PATH  L"\\System\\Library\\CoreServices\\boot.efi"

// BOOT_EFI_FILE_NAME
/// Path to the Apple bootloader in the root folder
#define APPLE_BOOTER_FILE_NAME  L"\\boot.efi"

/// @Name File names
/// EFI File location to boot from on removable media devices
/// @{
#ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_IA32
  #define EFI_REMOVABLE_MEDIA_FILE_NAME_IA32     L"\\EFI\\BOOT\\BOOTIA32.EFI"
#endif // ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_IA32

#ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_IA64
  #define EFI_REMOVABLE_MEDIA_FILE_NAME_IA64     L"\\EFI\\BOOT\\BOOTIA64.EFI"
#endif // ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_IA64

#ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_X64
  #define EFI_REMOVABLE_MEDIA_FILE_NAME_X64      L"\\EFI\\BOOT\\BOOTX64.EFI"
#endif // ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_X64

#ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_ARM
  #define EFI_REMOVABLE_MEDIA_FILE_NAME_ARM      L"\\EFI\\BOOT\\BOOTARM.EFI"
#endif // ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_ARM

#ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64
  #define EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64  L"\\EFI\\BOOT\\BOOTAA64.EFI"
#endif // ifndef EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64
/// @}

/// @Name
/// Apple EFI File location to boot from on removable media devices
/// @{
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_IA32     L"\\EFI\\APPLE\\IA32\\BOOT.EFI"
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_IA64     L"\\EFI\\APPLE\\IA64\\BOOT.EFI"
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_X64      L"\\EFI\\APPLE\\X64\\BOOT.EFI"
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_ARM      L"\\EFI\\APPLE\\ARM\\BOOT.EFI"
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_AARCH64  L"\\EFI\\APPLE\\AA64\\BOOT.EFI"

// EFI_REMOVABLE_MEDIA_FILE_NAME
///
#if defined (CPU_IA32)
  #define _EFI_REMOVABLE_MEDIA_FILE_NAME   EFI_REMOVABLE_MEDIA_FILE_NAME_IA32
  #define APPLE_REMOVABLE_MEDIA_FILE_NAME  APPLE_REMOVABLE_MEDIA_FILE_NAME_IA32
#elif defined (CPU_IPF)
  #define _EFI_REMOVABLE_MEDIA_FILE_NAME   EFI_REMOVABLE_MEDIA_FILE_NAME_IA64
  #define APPLE_REMOVABLE_MEDIA_FILE_NAME  APPLE_REMOVABLE_MEDIA_FILE_NAME_IA64
#elif defined (CPU_X64)
  #define _EFI_REMOVABLE_MEDIA_FILE_NAME   EFI_REMOVABLE_MEDIA_FILE_NAME_X64
  #define APPLE_REMOVABLE_MEDIA_FILE_NAME  APPLE_REMOVABLE_MEDIA_FILE_NAME_X64
#elif defined (CPU_ARM)
  #define _EFI_REMOVABLE_MEDIA_FILE_NAME   EFI_REMOVABLE_MEDIA_FILE_NAME_ARM
  #define APPLE_REMOVABLE_MEDIA_FILE_NAME  APPLE_REMOVABLE_MEDIA_FILE_NAME_ARM
#elif defined (CPU_AARCH64)
  #define _EFI_REMOVABLE_MEDIA_FILE_NAME   EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64
  #define APPLE_REMOVABLE_MEDIA_FILE_NAME  APPLE_REMOVABLE_MEDIA_FILE_NAME_AARCH64
#else
  #error Unknown Processor Type
#endif // defined (CPU_IA32)

#ifndef EFI_REMOVABLE_MEDIA_FILE_NAME
  #define EFI_REMOVABLE_MEDIA_FILE_NAME  _EFI_REMOVABLE_MEDIA_FILE_NAME
#endif // ifndef EFI_REMOVABLE_MEDIA_FILE_NAME
/// @}

// APPLE_SYSTEM_VERSION_FILE_NAME
/// The default location of the property list identifying the OS version
#define APPLE_SYSTEM_VERSION_FILE_NAME  L"\\System\\Library\\CoreServices\\SystemVersion.plist"

#endif // ifndef __APPLE_EFI_SPEC_H__
