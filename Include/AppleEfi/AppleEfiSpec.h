/** @file
  Copyright (C) 2005 - 2016, Apple Inc.  All rights reserved.
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

#ifndef APPLE_EFI_SPEC_H_
#define APPLE_EFI_SPEC_H_

// APPLE_BOOTLOADER_FILE_PATH
/// The default, preferred location of the Apple bootloader
#define APPLE_BOOTER_FILE_PATH  L"\\System\\Library\\CoreServices\\boot.efi"

// BOOT_EFI_FILE_NAME
/// Path to the Apple bootloader in the root folder
#define APPLE_BOOTER_FILE_NAME  L"\\boot.efi"

// Apple EFI File location to boot from on removable media devices

#define APPLE_REMOVABLE_MEDIA_FILE_NAME_IA32  \
  L"\\EFI\\APPLE\\IA32\\BOOT.EFI"

#define APPLE_REMOVABLE_MEDIA_FILE_NAME_IA64  \
  L"\\EFI\\APPLE\\IA64\\BOOT.EFI"

#define APPLE_REMOVABLE_MEDIA_FILE_NAME_X64  \
  L"\\EFI\\APPLE\\X64\\BOOT.EFI"

#define APPLE_REMOVABLE_MEDIA_FILE_NAME_ARM  \
  L"\\EFI\\APPLE\\ARM\\BOOT.EFI"

#define APPLE_REMOVABLE_MEDIA_FILE_NAME_AARCH64  \
  L"\\EFI\\APPLE\\AARCH64\\BOOT.EFI"

// APPLE_SYSTEM_VERSION_FILE_NAME
/// The default location of the property list identifying the OS version
#define APPLE_SYSTEM_VERSION_FILE_NAME  \
  L"\\System\\Library\\CoreServices\\SystemVersion.plist"

#endif // APPLE_EFI_SPEC_H_
