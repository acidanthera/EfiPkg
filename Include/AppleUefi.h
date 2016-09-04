/** @file
  Copyright (C) 2005 - 2015, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_UEFI_H_
#define APPLE_UEFI_H_

#include <AppleCpuType.h>

#include <Uefi.h>
#include <AppleEfi/AppleEfiSpec.h>
#include <AppleCommon.h>

#define EFI_FIRMWARE_MAJOR_REVISION  APPLE_EFI_FIRMWARE_MAJOR_REVISION
#define EFI_FIRMWARE_MINOR_REVISION  APPLE_EFI_FIRMWARE_MINOR_REVISION
#define EFI_FIRMWARE_REVISION  \
  ((EFI_FIRMWARE_MAJOR_REVISION << 16) | EFI_FIRMWARE_MINOR_REVISION)

// Define macros for including Protocols and Guids.

#define _STRINGIZE(a)              #a
#define EFI_PROTOCOL_DEFINITION(a) _STRINGIZE (Protocol/a/a.h)
#define EFI_GUID_DEFINITION(a)     _STRINGIZE EFI_STRINGIZE (Guid/a/a.h)


// These should be used to include protocols.  If they are followed,
// intelligent build tools can be created to check dependencies at build
// time.

#define EFI_PROTOCOL_PRODUCER(a)   EFI_PROTOCOL_DEFINITION (a)
#define EFI_PROTOCOL_CONSUMER(a)   EFI_PROTOCOL_DEFINITION (a)
#define EFI_PROTOCOL_DEPENDENCY(a) EFI_PROTOCOL_DEFINITION (a)


// Define macros for including Architectural Protocols and PPIs

#define EFI_ARCH_PROTOCOL_DEFINITION(a) EFI_STRINGIZE (ArchProtocol/a/a.h)
#define EFI_PPI_DEFINITION(a)           EFI_STRINGIZE (Ppi/a/a.h)

// These should be used to include protocols.  If they are followed,
// intelligent build tools can be created to check dependencies at build
// time.

#define EFI_ARCH_PROTOCOL_PRODUCER(a)   EFI_ARCH_PROTOCOL_DEFINITION (a)
#define EFI_ARCH_PROTOCOL_CONSUMER(a)   EFI_ARCH_PROTOCOL_DEFINITION (a)
#define EFI_ARCH_PROTOCOL_DEPENDENCY(a) EFI_ARCH_PROTOCOL_DEFINITION (a)

#define EFI_PPI_PRODUCER(a)   EFI_PPI_DEFINITION (a)
#define EFI_PPI_CONSUMER(a)   EFI_PPI_DEFINITION (a)
#define EFI_PPI_DEPENDENCY(a) EFI_PPI_DEFINITION (a)

#endif // APPLE_UEFI_H_
