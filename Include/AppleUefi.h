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
