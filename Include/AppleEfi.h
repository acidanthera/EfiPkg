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

#ifndef APPLE_EFI_H_
#define APPLE_EFI_H_

#include <AppleCpuType.h>

#include <Tiano.h>
#include <AppleEfi/AppleEfiSpec.h>
#include <AppleCommon.h>

#ifdef EFI_FIRMWARE_MAJOR_REVISION
#undef EFI_FIRMWARE_MAJOR_REVISION
#endif // EFI_FIRMWARE_MAJOR_REVISION

#ifdef EFI_FIRMWARE_MINOR_REVISION
#undef EFI_FIRMWARE_MINOR_REVISION
#endif // EFI_FIRMWARE_MINOR_REVISION

#define EFI_FIRMWARE_MAJOR_REVISION  APPLE_EFI_FIRMWARE_MAJOR_REVISION
#define EFI_FIRMWARE_MINOR_REVISION  APPLE_EFI_FIRMWARE_MINOR_REVISION

// The Microsoft* C compiler can removed references to unreferenced data items
// if the /OPT:REF linker option is used.  We defined a macro as this is a
// a non standard extension

#ifndef GLOBAL_REMOVE_IF_UNREFERENCED
  #if defined (_MSC_EXTENSIONS) && !defined (CPU_EBC)
    /// Remove global variable from the linked image if there are no references to
    /// it after all compiler and linker optimizations have been performed.
    #define GLOBAL_REMOVE_IF_UNREFERENCED  __declspec (selectany)
  #else // _MSC_EXTENSIONS && !CPU_EBC
    /// Remove the global variable from the linked image if there are no references
    /// to it after all compiler and linker optimizations have been performed.
    #define GLOBAL_REMOVE_IF_UNREFERENCED
  #endif // _MSC_EXTENSIONS && !CPU_EBC
#endif // GLOBAL_REMOVE_IF_UNREFERENCED

#ifndef PACKED
  #ifdef __CC_ARM
    // PACKED
    /// Older RVCT ARM compilers don't fully support #pragma pack and require __packed
    /// as a prefix for the structure.
    #define PACKED  __packed
  #else // __CC_ARM
    #define PACKED
  #endif // __CC_ARM
#endif // PACKED

#endif // APPLE_EFI_H_

