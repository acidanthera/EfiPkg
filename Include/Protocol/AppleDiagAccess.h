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

#ifndef APPLE_DIAG_ACCESS_H_
#define APPLE_DIAG_ACCESS_H_

// APPLE_DIAG_ACCESS_PROTOCOL_GUID
#define APPLE_DIAG_ACCESS_PROTOCOL_GUID  \
  { 0xC5CFF4F1, 0x379A, 0x54E1,          \
    { 0x9E, 0xDD, 0x93, 0x21, 0x9C, 0x6A, 0xA4, 0xFE } }

// DIAG_ACCESS_GET
typedef
EFI_STATUS
(EFIAPI *DIAG_ACCESS_GET)(
  IN CHAR16     *Key,
  OUT VOID      *Value,
  IN OUT UINTN  *Size
  );

// APPLE_DIAG_ACCESS_PROTOCOL
typedef struct {
  UINTN           Revision;
  DIAG_ACCESS_GET Get;
} APPLE_DIAG_ACCESS_PROTOCOL;

// gAppleDiagAccessProtocolGuid
extern EFI_GUID gAppleDiagAccessProtocolGuid;

#endif // APPLE_DIAG_ACCESS_H_
