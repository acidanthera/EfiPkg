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

#ifndef _APPLE_KEY_MAP_AGGREGATOR_LIB_H_
#define _APPLE_KEY_MAP_AGGREGATOR_LIB_H_

// GetAppleKeyStrokes
EFI_STATUS
GetAppleKeyStrokes (
	OUT APPLE_MODIFIER_MAP *Modifiers,
	OUT UINTN              *NoKeys,
	OUT APPLE_KEY          **Keys
	);

// GetModifierStrokes
APPLE_MODIFIER_MAP
GetModifierStrokes (
	VOID
	);

// mAppleKeyMapAggregator
extern APPLE_KEY_MAP_AGGREGATOR_PROTOCOL *mAppleKeyMapAggregator;

#endif // ifndef _APPLE_KEY_MAP_AGGREGATOR_LIB_H_
