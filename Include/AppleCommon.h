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

#ifndef APPLE_COMMON_H_
#define APPLE_COMMON_H_

// EFI Revision information

#define APPLE_EFI_FIRMWARE_MAJOR_REVISION  1
#define APPLE_EFI_FIRMWARE_MINOR_REVISION  0x0A

// APPLE_FORWARD_DECLARATION
#define APPLE_FORWARD_DECLARATION(x) typedef struct x x

// Define macros for including Protocols and Guids.

#define _STRINGIZE(a)                #a
#define APPLE_PROTOCOL_DEFINITION(a) _STRINGIZE (Protocol/a.h)
#define APPLE_GUID_DEFINITION(a)     _STRINGIZE (Guid/a.h)

// These should be used to include protocols.  If they are followed,
// intelligent build tools can be created to check dependencies at build
// time.

#define APPLE_PROTOCOL_PRODUCER(a)   APPLE_PROTOCOL_DEFINITION (a)
#define APPLE_PROTOCOL_CONSUMER(a)   APPLE_PROTOCOL_DEFINITION (a)
#define APPLE_PROTOCOL_DEPENDENCY(a) APPLE_PROTOCOL_DEFINITION (a)

// Define macros for including Architectural Protocols and PPIs

#define APPLE_PPI_DEFINITION(a) _STRINGIZE (Ppi/a.h)


// These should be used to include PPIs.  If they are followed,
// intelligent build tools can be created to check dependencies at build
// time.

#define APPLE_PPI_PRODUCER(a)   APPLE_PPI_DEFINITION (a)
#define APPLE_PPI_CONSUMER(a)   APPLE_PPI_DEFINITION (a)
#define APPLE_PPI_DEPENDENCY(a) APPLE_PPI_DEFINITION (a)

#endif // APPLE_COMMON_H_
