/** @file
  The AppleKeyMap library to be used with the AppleKeyMap protocol.  Contains necessary
  structure definitions and useful additional data.

  Copyright (C) 2005 - 2015 Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_KEY_MAP_LIB_H_
#define APPLE_KEY_MAP_LIB_H_

#include <IndustryStandard/AppleHid.h>

// APPLE_KEY_DESCRIPTOR
typedef struct {
  APPLE_KEY     AppleKey;         ///< The Apple key identifier identifying the key.
  EFI_INPUT_KEY InputKey;         ///< 
  EFI_INPUT_KEY ShiftedInputKey;  ///< 
} APPLE_KEY_DESCRIPTOR;

// InputKeyFromAppleKey
VOID
InputKeyFromAppleKey (
  IN  APPLE_KEY      AppleKey,
  OUT EFI_INPUT_KEY  *InputKey,
  IN  BOOLEAN        Shifted
  );

// gAppleHidUsbKbKeyMap
/// The default United States key map for Apple keyboards.
extern APPLE_KEY_DESCRIPTOR gAppleKeyMap[];

#endif // APPLE_KEY_MAP_LIB_H_
