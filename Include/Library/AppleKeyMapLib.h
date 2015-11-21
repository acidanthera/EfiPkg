///
/// @file      Library/AppleKeyMapLib.h
///
///            The AppleKeyMap library to be used with the AppleKeyMap protocol. Contains necessary
///            structure definitions and useful additional data.
///
/// @author    Download-Fritz
/// @date      15/03/2015: Initial version
/// @copyright The decompilation is of an educational purpose to better understand the behavior of the
///            Apple EFI implementation and making use of it. In no way is the content's usage licensed
///            or allowed. All rights remain at Apple Inc. To be used under the terms of 'Fair use'.
///

//
// CREDITS:
//   Reversed from AppleKeyMapAggregator.efi and AppleEvent.efi, which are Apple Inc. property
//	 Key modifier and identifier list by tiamo (macosxbootloader, UsbHidKbKeyState.h)
//   Decompiled by Download-Fritz
//

#ifndef __APPLE_KEY_MAP_LIB_H__
#define __APPLE_KEY_MAP_LIB_H__

// _APPLE_KEY_DESCRIPTOR
typedef struct _APPLE_KEY_DESCRIPTOR {
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
extern APPLE_KEY_DESCRIPTOR gAppleKeyMap[91];

#endif // ifndef __APPLE_KEY_MAP_LIB_H__
