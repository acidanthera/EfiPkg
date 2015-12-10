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
/// @file      Include/AppleCommon.h
///
///            
///
/// @author    Download-Fritz
/// @date      08/11/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_COMMON_H__
#define __APPLE_COMMON_H__

//
// The Microsoft* C compiler can removed references to unreferenced data items
// if the /OPT:REF linker option is used. We defined a macro as this is a
// a non standard extension
//
#if defined(_MSC_EXTENSIONS) && !defined (MDE_CPU_EBC) // MDE?
  ///
  /// Remove global variable from the linked image if there are no references to
  /// it after all compiler and linker optimizations have been performed.
  ///
  ///
  #define GLOBAL_REMOVE_IF_UNREFERENCED __declspec(selectany)
#else
  ///
  /// Remove the global variable from the linked image if there are no references
  /// to it after all compiler and linker optimizations have been performed.
  ///
  ///
  #define GLOBAL_REMOVE_IF_UNREFERENCED
#endif

#ifdef EFI_FORWARD_DECLARATION
  #define FORWARD_DECLARATION(x) EFI_FORWARD_DECLARATION (x)
#else
#if defined (EFI_NO_INTERFACE_DECL) || defined (NO_INTERFACE_DECL)
  #define FORWARD_DECLARATION(x)
#else
  #define FORWARD_DECLARATION(x) typedef struct _##x x
#endif // ifdef (EFI_NO_INTERFACE_DECL || NO_INTERFACE_DECL)
  #define EFI_FORWARD_DECLARATION(x) FORWARD_DECLARATION (x)
#endif // ifdef EFI_FORWARD_DECLARATION

#ifdef __CC_ARM
  //
  // Older RVCT ARM compilers don't fully support #pragma pack and require __packed
  // as a prefix for the structure.
  //
  #define PACKED  __packed
#else
  #define PACKED
#endif

// ARRAY_LENGTH
#define ARRAY_LENGTH(Array) (sizeof (Array) / sizeof (*(Array)))

// CONVERT_LENGTH
#define CONVERT_LENGTH(Size, SourceType, DestinationType) (((Size) / sizeof (SourceType)) * sizeof (DestinationType))

#define OFFSET_PTR(Ptr, Index, Type) ((Type *)((UINTN)(Ptr) + (UINTN)(Index * sizeof (Type))))
#define OFFSET(Value, Index, Type)   OFFSET_PTR (&(Value), Index, Type)

#define BYTE_PTR(Ptr, Index) (*(OFFSET_PTR (Ptr, Index, UINT8)))
#define BYTE(Value, Index)   (*(OFFSET (Value, Index, UINT8)))

#define WORD_PTR(Ptr, Index) (*(OFFSET_PTR (Ptr, Index, UINT16)))
#define WORD(Value, Index)   (*(OFFSET (Value, Index, UINT16)))

#define DWORD_PTR(Ptr, Index) (*(OFFSET (Ptr, Index, UINT32)))
#define DWORD(Value, Index)   (*(OFFSET (Value, Index, UINT32)))

#define QWORD_PTR(Ptr, Index) (*(OFFSET (Ptr, Index, UINT64)))
#define QWORD(Value, Index)   (*(OFFSET (Value, Index, UINT64)))

// BIT
#define BIT(Index)                (1 << (Index))
#define JOIN_MASKS(Mask1, Mask2)  ((Mask1) | (Mask2))
#define JOIN_BITS(Mask1, Mask2)   JOIN_MASKS ((Mask1), (Mask2))
#define SET_BIT(Mask1, Mask2)     JOIN_MASKS ((Mask1), (Mask2))
#define SET_BITS(Mask1, Mask2)    SET_BIT ((Mask1), (Mask2))
#define UNSET_BITS(Mask1, Mask2)  ((Mask1) & ~(Mask2))
#define UNSET_BIT(Mask1, Mask2)   UNSET_BITS ((Mask1), (Mask2))
#define DIFF_BITS(Mask1, Mask2)   ((Mask1) ^ (Mask2))
#define TOGGLE_BITS(Mask1, Mask2) DIFF_BITS ((Mask1), (Mask2))
#define TOGGLE_BIT(Mask1, Mask2)  TOGGLE_BITS ((Mask1), (Mask2))
#define APPLY_MASK(Mask1, Mask2)  ((Mask1) & (Mask2))
#define SELECT_BITS(Mask1, Mask2) APPLY_MASK ((Mask1), (Mask2))
#define BIT_SET(Mask1, Mask2)     ((BOOLEAN)(SELECT_BITS ((Mask1), (Mask2)) != 0))
#define BITS_SET(Mask1, Mask2)    ((BOOLEAN)(SELECT_BITS ((Mask1), (Mask2)) == (Mask2)))

#endif // ifndef __APPLE_COMMON_H__
