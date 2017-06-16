/** @file
  Copyright (C) 2005 - 2017, Apple Inc.  All rights reserved.
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

#ifndef EFI_OS_INFO_H_
#define EFI_OS_INFO_H_

// EFI_OS_INFO_PROTOCOL_GUID
#define EFI_OS_INFO_PROTOCOL_GUID                         \
  { 0xC5C5DA95, 0x7D5C, 0x45E6,                           \
    { 0xB2, 0xF1, 0x3F, 0xD5, 0x2B, 0xB1, 0x00, 0x77 } }

// OS_INFO_OS_VENDOR
typedef
VOID
(EFIAPI *OS_INFO_OS_VENDOR)(
  IN CHAR8  *OSName
  );

// OS_INFO_OS_NAME
typedef
VOID
(EFIAPI *OS_INFO_OS_NAME)(
  IN CHAR8  *OSName
  );

// OS_INFO_SET_VTD_ENABLED
typedef
VOID
(EFIAPI *OS_INFO_SET_VTD_ENABLED)(
  IN UINTN  *BootVTdEnabled
  );

// OS_INFO_GET_VTD_ENABLED
typedef
VOID
(EFIAPI *OS_INFO_GET_VTD_ENABLED)(
  OUT UINTN  *BootVTdEnabled
  );

// EFI_OS_INFO_PROTOCOL
typedef struct {
  UINTN                   Revision;           ///< Revision.
  OS_INFO_OS_VENDOR       OSVendor;           ///< Present as of Revision 1.
  OS_INFO_OS_NAME         OSName;             ///< Present as of Revision 2.
  OS_INFO_SET_VTD_ENABLED SetBootVTdEnabled;  ///< Present as of Revision 3.
  OS_INFO_GET_VTD_ENABLED GetBootVTdEnabled;  ///< Present as of Revision 3.
} EFI_OS_INFO_PROTOCOL;

// gEfiOSInfoProtocolGuid
extern EFI_GUID gEfiOSInfoProtocolGuid;

#endif // EFI_OS_INFO_H_
