/** @file
  Copyright (C) 2017, CupertinoNet.  All rights reserved.<BR>

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

#ifndef APPLE_FIRMWARE_PASSWORD_PROTOCOL_H_
#define APPLE_FIRMWARE_PASSWORD_PROTOCOL_H_

#define APPLE_FIRMWARE_PASSWORD_PROTOCOL_GUID \
  { \
  0x8FFEEB3A, 0x4C98, 0x4630, { 0x80, 0x3F, 0x74, 0x0F, 0x95, 0x67, 0x09, 0x1D } \
  }

// APPLE_FIRMWARE_PASSWORD_PROTOCOL
/// The forward declaration for the protocol for the APPLE_FIRMWARE_PASSWORD_PROTOCOL.

typedef struct APPLE_FIRMWARE_PASSWORD_PROTOCOL APPLE_FIRMWARE_PASSWORD_PROTOCOL;

// AppleFirmwarePasswordCheck
///
///
/// @param[in] This        This protocol.
/// @param[in] Arg1
///
/// @param[out] FilePath    Databuffer
///
/// @retval EFI_SUCCESS         The log was saved successfully.
/// @retval other

typedef
EFI_STATUS
(EFIAPI *APPLE_FIRMWARE_PASSWORD_CHECK) (
  IN     APPLE_FIRMWARE_PASSWORD_PROTOCOL  *This,
  IN OUT UINTN                             *Arg1
  );

// _APPLE_FIRMWARE_PASSWORD_PROTOCOL
/// The structure exposed by the APPLE_FIRMWARE_PASSWORD_PROTOCOL.

typedef struct APPLE_FIRMWARE_PASSWORD_PROTOCOL {
  UINTN Revision;
  UINTN Unknown01;
  UINTN Unknown02;
  UINTN Unknown03;
  APPLE_FIRMWARE_PASSWORD_CHECK Check;
} APPLE_FIRMWARE_PASSWORD_PROTOCOL;

//
// gAppleFirmwarePasswordProtocolGuid
/// A global variable storing the GUID of the _APPLE_FIRMWARE_PASSWORD_PROTOCOL.

extern EFI_GUID gAppleFirmwarePasswordProtocolGuid;

#endif /* APPLE_FIRMWARE_PASSWORD_PROTOCOL_H_ */

