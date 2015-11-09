///
/// @file      Protocol/AppleKeyMapAggregator/AppleKeyMapAggregator.c
///
///
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
//   Decompiled by Download-Fritz
//

#include <AppleEfi.h>
#include <EfiDriverLib.h>
#include <IndustryStandard/AppleHid.h>

#include <Protocol/AppleKeyMapAggregator.h>

// gAppleKeyMapAggregatorProtocolGuid
EFI_GUID gAppleKeyMapAggregatorProtocolGuid = APPLE_KEY_MAP_AGGREGATOR_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleKeyMapAggregatorProtocolGuid, "Key Map Aggregator", "Apple Key Map Aggregator Protocol");
