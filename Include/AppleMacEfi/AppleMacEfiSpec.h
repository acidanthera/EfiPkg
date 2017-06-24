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

#ifndef APPLE_MAC_EFI_SPEC_H_
#define APPLE_MAC_EFI_SPEC_H_

// EFI Revision information

#define APPLE_EFI_FIRMWARE_REVISION  0x010000
#define APPLE_EFI_FIRMWARE_VENDOR    L"Apple"

// APPLE_BOOTER_FILE_NAME
#define APPLE_BOOTER_FILE_NAME  L"boot.efi"

// APPLE_BOOTLOADER_FILE_PATH
#define APPLE_BOOTER_DEFAULT_FILE_NAME  L"\\System\\Library\\CoreServices\\boot.efi"

// BOOT_EFI_FILE_NAME
#define APPLE_BOOTER_ROOT_FILE_NAME  L"\\boot.efi"

// Apple EFI File location to boot from on removable media devices

// APPLE_REMOVABLE_MEDIA_FILE_NAME_IA32
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_IA32  \
  L"\\EFI\\APPLE\\IA32\\BOOT.EFI"

// APPLE_REMOVABLE_MEDIA_FILE_NAME_X64
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_X64  \
  L"\\EFI\\APPLE\\X64\\BOOT.EFI"

// APPLE_REMOVABLE_MEDIA_FILE_NAME_ARM
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_ARM  \
  L"\\EFI\\APPLE\\ARM\\BOOT.EFI"

// APPLE_REMOVABLE_MEDIA_FILE_NAME_AARCH64
#define APPLE_REMOVABLE_MEDIA_FILE_NAME_AARCH64  \
  L"\\EFI\\APPLE\\AARCH64\\BOOT.EFI"

// APPLE_SYSTEM_VERSION_FILE_NAME
#define APPLE_SYSTEM_VERSION_FILE_NAME  \
  L"\\System\\Library\\CoreServices\\SystemVersion.plist"

#endif // APPLE_MAC_EFI_SPEC_H_
