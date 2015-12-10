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
/// @file      Library/AppleKeyMapAggregatorLib.h
///
///
/// @author    Download-Fritz
/// @date      15/03/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_KEY_MAP_AGGREGATOR_LIB_H__
#define __APPLE_KEY_MAP_AGGREGATOR_LIB_H__

// GetAppleKeyStrokes
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
GetAppleKeyStrokes (
	OUT APPLE_MODIFIER_MAP  *Modifiers,
	OUT UINTN               *NoKeys,
	OUT APPLE_KEY           **Keys
	);

// GetModifierStrokes
/// 
///
/// @param 
///
/// @return 
/// @retval 
APPLE_MODIFIER_MAP
GetModifierStrokes (
	VOID
	);

// mAppleKeyMapAggregator
extern APPLE_KEY_MAP_AGGREGATOR_PROTOCOL *mAppleKeyMapAggregator;

#endif // ifndef __APPLE_KEY_MAP_AGGREGATOR_LIB_H__
