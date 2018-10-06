/** @file
  Apple LoadImage protocol.

  Copyright (C) 2018, savvas.  All rights reserved.<BR>
  Copyright (C) 2018, CupertinoNet.  All rights reserved.<BR>

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

#ifndef APPLE_LOAD_IMAGE_PROTOCOL_H_
#define APPLE_LOAD_IMAGE_PROTOCOL_H_

//
// 6C6148A4-97B8-429C-955E-4103E8ACA0FA
//
#define APPLE_LOAD_IMAGE_PROTOCOL_GUID \
  { 0x6C6148A4, 0x97B8, 0x429C,        \
    { 0x95, 0x5E, 0x41, 0x03, 0xE8, 0xAC, 0xA0, 0xFA } }

//
// Should return TRUE to perform image signature verification.
//
typedef
BOOLEAN
(EFIAPI *APPLE_LOAD_IMAGE_CALLBACK) (
  VOID
  );

typedef
EFI_STATUS
(EFIAPI *APPLE_LOAD_IMAGE) (
  IN  BOOLEAN                    BootPolicy,
  IN  EFI_HANDLE                 ParentImageHandle,
  IN  EFI_DEVICE_PATH_PROTOCOL   *DevicePath,
  IN  VOID                       *SourceBuffer OPTIONAL,
  IN  UINTN                      SourceSize,
  OUT EFI_HANDLE                 *ImageHandle,
  IN  APPLE_LOAD_IMAGE_CALLBACK  Callback OPTIONAL
);

typedef struct {
  APPLE_LOAD_IMAGE  LoadImage;
} APPLE_LOAD_IMAGE_PROTOCOL;

extern EFI_GUID gAppleLoadImageProtocolGuid;

#endif // APPLE_LOAD_IMAGE_PROTOCOL_H_
