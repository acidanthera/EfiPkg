/** @file
  Copyright (C) 2005 - 2015 Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_COMMON_H_
#define APPLE_COMMON_H_

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
