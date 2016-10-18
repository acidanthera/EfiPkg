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
#ifndef APPLE_BOOT_POLICY_H_
#define APPLE_BOOT_POLICY_H_

// APPLE_BOOT_POLICY_PROTOCOL_GUID
/// The GUID of the APPLE_BOOT_POLICY_PROTOCOL.
#define APPLE_BOOT_POLICY_PROTOCOL_GUID                   \
  { 0x62257758, 0x350C, 0x4D0A,                           \
    { 0xB0, 0xBD, 0xF6, 0xBE, 0x2E, 0x1E, 0x27, 0x2C } }

// BOOT_POLICY_GET_BOOT_FILE
/** Locates the bootable file of the given volume.  Prefered are the values
    blessed, though if unavailable, hard-coded names are being verified and
    used if existing.

  The blessed paths are to be determined by the HFS Driver via
  EFI_FILE_PROTOCOL.GetInfo().  The related identifier definitions are to be
  found in AppleBless.h.

  @param[in]  Device        The Device's Handle to perform the search on.
  @param[out] BootFilePath  A pointer to the device path pointer to set to the
                            file path of the boot file.

  @return                       The status of the operation is returned.
  @retval EFI_NOT_FOUND         A bootable file could not be found on the given
                                volume.
  @retval EFI_OUT_OF_RESOURCES  The memory necessary to complete the operation
                                could not be allocated.
  @retval EFI_SUCCESS           The operation completed successfully and the
                                BootFilePath Buffer has been filled.
  @retval other                 The status of an operation used to complete
                                this operation is returned.
**/
typedef
EFI_STATUS
(EFIAPI *BOOT_POLICY_GET_BOOT_FILE)(
  IN  EFI_HANDLE            Device,
  OUT FILEPATH_DEVICE_PATH  **BootFilePath
  );

// APPLE_BOOT_POLICY_PROTOCOL
/// The structure exposed by the APPLE_BOOT_POLICY_PROTOCOL.
typedef struct {
  /// The revision of the installed protocol.
  UINTN                     Revision;

  /// A pointer to the function that locates the bootable file of the volume.
  BOOT_POLICY_GET_BOOT_FILE GetBootFile;
} APPLE_BOOT_POLICY_PROTOCOL;

// gAppleBootPolicyProtocolGuid
/// A global variable storing the GUID of the APPLE_BOOT_POLICY_PROTOCOL.
extern EFI_GUID gAppleBootPolicyProtocolGuid;

#endif // APPLE_BOOT_POLICY_H_
