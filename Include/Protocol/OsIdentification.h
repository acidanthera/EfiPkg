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
/// @file      Include/Protocol/OsIdentification.h
///
///            
///
/// @author    Download-Fritz
/// @date      18/07/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __EFI_OS_IDENTIFICATION_H__
#define __EFI_OS_IDENTIFICATION_H__

// EFI_OS_IDENTIFICATION_PROTOCOL_GUID
#define EFI_OS_IDENTIFICATION_PROTOCOL_GUID \
  { 0xC5C5DA95, 0x7D5C, 0x45E6, { 0xB2, 0xF1, 0x3F, 0xD5, 0x2B, 0xB1, 0x00, 0x77 } }

// OS_IDENTIFICATION_OS_VENDOR
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
VOID
(EFIAPI *OS_IDENTIFICATION_OS_VENDOR)(
  IN CHAR8  *OSName
  );

// OS_IDENTIFICATION_OS_NAME
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
VOID
(EFIAPI *OS_IDENTIFICATION_OS_NAME)(
  IN CHAR8  *OSName
  );

// EFI_OS_IDENTIFICATION_PROTOCOL
typedef struct _EFI_OS_IDENTIFICATION_PROTOCOL {
  UINTN                       Revision;  ///< 
  OS_IDENTIFICATION_OS_VENDOR OSVendor;  ///< 
  OS_IDENTIFICATION_OS_NAME   OSName;    ///< 
} EFI_OS_IDENTIFICATION_PROTOCOL;

// gEfiOsIdentificationProtocolGuid
extern EFI_GUID gEfiOsIdentificationProtocolGuid;

#endif // ifndef __EFI_OS_IDENTIFICATION_H__
