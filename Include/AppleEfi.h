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

// EFI File location to boot from on removable media devices

#define EFI_REMOVABLE_MEDIA_FILE_NAME_IA32     L"\\EFI\\BOOT\\BOOTIA32.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_IA64     L"\\EFI\\BOOT\\BOOTIA64.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_X64      L"\\EFI\\BOOT\\BOOTX64.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_ARM      L"\\EFI\\BOOT\\BOOTARM.EFI"
#define EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64  L"\\EFI\\BOOT\\BOOTAA64.EFI"

#ifndef EFI_REMOVABLE_MEDIA_FILE_NAME
  #define EFI_REMOVABLE_MEDIA_FILE_NAME  EFI_REMOVABLE_MEDIA_FILE_NAME_
#endif

// The Microsoft* C compiler can removed references to unreferenced data items
// if the /OPT:REF linker option is used.  We defined a macro as this is a
// a non standard extension

#ifndef GLOBAL_REMOVE_IF_UNREFERENCED
  #if defined (_MSC_EXTENSIONS) && !defined (CPU_EBC)
    /// Remove global variable from the linked image if there are no references
    /// to it after all compiler and linker optimizations have been performed.
    #define GLOBAL_REMOVE_IF_UNREFERENCED  __declspec (selectany)
  #else // _MSC_EXTENSIONS && !CPU_EBC
    /// Remove the global variable from the linked image if there are no 
    /// references to it after all compiler and linker optimizations have been
    /// performed.
    #define GLOBAL_REMOVE_IF_UNREFERENCED
  #endif // _MSC_EXTENSIONS && !CPU_EBC
#endif // GLOBAL_REMOVE_IF_UNREFERENCED

#ifndef PACKED
  #ifdef __CC_ARM
    // PACKED
    /// Older RVCT ARM compilers don't fully support #pragma pack and require
    /// __packed as a prefix for the structure.
    #define PACKED  __packed
  #else // __CC_ARM
    #define PACKED
  #endif // __CC_ARM
#endif // PACKED

#ifndef EFI_TIMER_PERIOD_MILLISECONDS

// EFI_TIMER_PERIOD_MILLISECONDS
/** Macro that returns the number of 100 ns units for a specified number of
    milliseconds. This is useful for managing EFI timer events.

  @param[in] Milliseconds  The number of milliseconds.

  @return The number of 100 ns units equivalent to the number of milliseconds
          specified by Milliseconds.
**/
#define EFI_TIMER_PERIOD_MILLISECONDS(Milliseconds)  \
          MultU64x32 ((UINT64)(Milliseconds), 10000)

#endif // !EFI_TIMER_PERIOD_MILLISECONDS

#define  BIT0   0x00000001
#define  BIT1   0x00000002
#define  BIT2   0x00000004
#define  BIT3   0x00000008
#define  BIT4   0x00000010
#define  BIT5   0x00000020
#define  BIT6   0x00000040
#define  BIT7   0x00000080
#define  BIT8   0x00000100
#define  BIT9   0x00000200
#define  BIT10  0x00000400
#define  BIT11  0x00000800
#define  BIT12  0x00001000
#define  BIT13  0x00002000
#define  BIT14  0x00004000
#define  BIT15  0x00008000
#define  BIT16  0x00010000
#define  BIT17  0x00020000
#define  BIT18  0x00040000
#define  BIT19  0x00080000
#define  BIT20  0x00100000
#define  BIT21  0x00200000
#define  BIT22  0x00400000
#define  BIT23  0x00800000
#define  BIT24  0x01000000
#define  BIT25  0x02000000
#define  BIT26  0x04000000
#define  BIT27  0x08000000
#define  BIT28  0x10000000
#define  BIT29  0x20000000
#define  BIT30  0x40000000
#define  BIT31  0x80000000
#define  BIT32  0x0000000100000000ULL
#define  BIT33  0x0000000200000000ULL
#define  BIT34  0x0000000400000000ULL
#define  BIT35  0x0000000800000000ULL
#define  BIT36  0x0000001000000000ULL
#define  BIT37  0x0000002000000000ULL
#define  BIT38  0x0000004000000000ULL
#define  BIT39  0x0000008000000000ULL
#define  BIT40  0x0000010000000000ULL
#define  BIT41  0x0000020000000000ULL
#define  BIT42  0x0000040000000000ULL
#define  BIT43  0x0000080000000000ULL
#define  BIT44  0x0000100000000000ULL
#define  BIT45  0x0000200000000000ULL
#define  BIT46  0x0000400000000000ULL
#define  BIT47  0x0000800000000000ULL
#define  BIT48  0x0001000000000000ULL
#define  BIT49  0x0002000000000000ULL
#define  BIT50  0x0004000000000000ULL
#define  BIT51  0x0008000000000000ULL
#define  BIT52  0x0010000000000000ULL
#define  BIT53  0x0020000000000000ULL
#define  BIT54  0x0040000000000000ULL
#define  BIT55  0x0080000000000000ULL
#define  BIT56  0x0100000000000000ULL
#define  BIT57  0x0200000000000000ULL
#define  BIT58  0x0400000000000000ULL
#define  BIT59  0x0800000000000000ULL
#define  BIT60  0x1000000000000000ULL
#define  BIT61  0x2000000000000000ULL
#define  BIT62  0x4000000000000000ULL
#define  BIT63  0x8000000000000000ULL

#endif // APPLE_EFI_H_
