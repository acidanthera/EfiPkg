///
/// @file      Protocol/AppleKeyMapAggregator/AppleKeyMapAggregator.h
///
///            The Apple protocol to output the pressed keys during the boot process.
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

#ifndef _APPLE_KEY_MAP_AGGREGATOR_H_
#define _APPLE_KEY_MAP_AGGREGATOR_H_

// APPLE_KEY_MAP_AGGREGATOR_PROTOCOL_GUID
/// The GUID of the APPLE_KEY_MAP_AGGREGATOR_PROTOCOL.
#define APPLE_KEY_MAP_AGGREGATOR_PROTOCOL_GUID \
  { 0x5B213447, 0x6E73, 0x4901, { 0xA4, 0xF1, 0xB8, 0x64, 0xF3, 0xB7, 0xA1, 0x72 } }

FORWARD_DECLARATION (APPLE_KEY_MAP_AGGREGATOR_PROTOCOL);

// GET_KEY_STROKES
/// Returns all pressed keys and key modifiers into the appropiate buffers.
///
/// @param[in]  This      A pointer to the protocol instance.
/// @param[out] Modifiers The modifiers manipulating the given keys.
/// @param[out] NoKeys    On input the number of keys allocated.
///                       On output the number of keys returned into Keys.
/// @param[out] Keys      A Pointer to a caller-allocated the pressed keys get returned in.
///
/// @return                      Returned is the status of the operation.
/// @retval EFI_SUCCESS          The pressed keys have been returned into Keys.
/// @retval EFI_BUFFER_TOO_SMALL The memory required to return the value exceeds the size of the allocated buffer.
///                              The required number of keys to allocate to complete the operation has been returned into NoKeys.
/// @retval other                An error returned by a sub-operation.
typedef
EFI_STATUS
(EFIAPI *GET_KEY_STROKES)(
  IN  APPLE_KEY_MAP_AGGREGATOR_PROTOCOL  *This,
  OUT APPLE_MODIFIER_MAP                 *Modifiers,
  OUT UINTN                              *NoKeys,
  OUT APPLE_KEY                          *Keys
  );

// CONTAINS_KEY_STROKES
/// Returns whether or not a list of keys and their modifiers are part of the database of pressed keys.
///
/// @param[in]      This       A pointer to the protocol instance.
/// @param[in]      Modifiers  The modifiers manipulating the given keys.
/// @param[in]      NoKeys     The number of keys present in Keys.
/// @param[in, out] Keys       The list of keys to check for. The children may be sorted in the process.
/// @param[in]      ExactMatch Specifies whether Modifiers and Keys should be exact matches or just contained.
///
/// @return               Returns whether or not a list of keys and their modifiers are part of the database of pressed keys.
/// @retval EFI_SUCCESS   The queried keys are part of the database.
/// @retval EFI_NOT_FOUND The queried keys could not be found.
typedef
EFI_STATUS
(EFIAPI *CONTAINS_KEY_STROKES)(
  IN     APPLE_KEY_MAP_AGGREGATOR_PROTOCOL  *This,
  IN     APPLE_MODIFIER_MAP                 Modifiers,
  IN     UINTN                              NoKeys,
  IN OUT APPLE_KEY                          *Keys,
  IN     BOOLEAN                            ExactMatch
  );

// _APPLE_KEY_MAP_AGGREGATOR_PROTOCOL
/// The structure exposed by the APPLE_KEY_MAP_AGGREGATOR_PROTOCOL.
struct _APPLE_KEY_MAP_AGGREGATOR_PROTOCOL {
  UINTN                Revision;            ///< The revision of the installed protocol.
  GET_KEY_STROKES      GetKeyStrokes;       ///< A pointer to the AppleKeyMapGetKeyStrokesImpl function.
  CONTAINS_KEY_STROKES ContainsKeyStrokes;  ///< A pointer to the ContainsKeyStrokes function.
};

// gAppleKeyMapAggregatorProtocolGuid
/// A global variable storing the GUID of the APPLE_KEY_MAP_AGGREGATOR_PROTOCOL.
extern EFI_GUID gAppleKeyMapAggregatorProtocolGuid;

#endif // ifndef _APPLE_KEY_MAP_AGGREGATOR_H_
