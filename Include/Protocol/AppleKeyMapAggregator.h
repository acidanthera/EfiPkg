/** @file
  The Apple protocol to output the pressed keys during the boot process.

  Copyright (C) 2005 - 2015, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_KEY_MAP_AGGREGATOR_H_
#define APPLE_KEY_MAP_AGGREGATOR_H_

// APPLE_KEY_MAP_AGGREGATOR_PROTOCOL_GUID
/// The GUID of the APPLE_KEY_MAP_AGGREGATOR_PROTOCOL.
#define APPLE_KEY_MAP_AGGREGATOR_PROTOCOL_GUID            \
  { 0x5B213447, 0x6E73, 0x4901,                           \
    { 0xA4, 0xF1, 0xB8, 0x64, 0xF3, 0xB7, 0xA1, 0x72 } }

APPLE_FORWARD_DECLARATION (APPLE_KEY_MAP_AGGREGATOR_PROTOCOL);

// KEY_MAP_GET_KEY_STROKES
/** Returns all pressed keys and key modifiers into the appropiate buffers.

  @param[in]  This       A pointer to the protocol instance.
  @param[out] Modifiers  The modifiers manipulating the given keys.
  @param[out] NoKeys     On input the number of keys allocated.
                         On output the number of keys returned into Keys.
  @param[out] Keys       A Pointer to a caller-allocated the pressed keys get
                         returned in.

  @return                       Returned is the status of the operation.
  @retval EFI_SUCCESS           The pressed keys have been returned into Keys.
  @retval EFI_BUFFER_TOO_SMALL  The memory required to return the value exceeds
                                the size of the allocated Buffer.
                                The required number of keys to allocate to
                                complete the operation has been returned into
                                NoKeys.
  @retval other                 An error returned by a sub-operation.
**/
typedef
EFI_STATUS
(EFIAPI *KEY_MAP_GET_KEY_STROKES)(
  IN  APPLE_KEY_MAP_AGGREGATOR_PROTOCOL  *This,
  OUT APPLE_MODIFIER_MAP                 *Modifiers,
  OUT UINTN                              *NoKeys,
  OUT APPLE_KEY                          *Keys
  );

// KEY_MAP_CONTAINS_KEY_STROKES
/** Returns whether or not a list of keys and their modifiers are part of the
    database of pressed keys.

  @param[in]      This        A pointer to the protocol instance.
  @param[in]      Modifiers   The modifiers manipulating the given keys.
  @param[in]      NoKeys      The number of keys present in Keys.
  @param[in, out] Keys        The list of keys to check for.  The children may
                              be sorted in the process.
  @param[in]      ExactMatch  Specifies whether Modifiers and Keys should be
                              exact matches or just contained.

  @return                Returns whether or not a list of keys and their
                         modifiers are part of the database of pressed keys.
  @retval EFI_SUCCESS    The queried keys are part of the database.
  @retval EFI_NOT_FOUND  The queried keys could not be found.
**/
typedef
EFI_STATUS
(EFIAPI *KEY_MAP_CONTAINS_KEY_STROKES)(
  IN     APPLE_KEY_MAP_AGGREGATOR_PROTOCOL  *This,
  IN     APPLE_MODIFIER_MAP                 Modifiers,
  IN     UINTN                              NoKeys,
  IN OUT APPLE_KEY                          *Keys,
  IN     BOOLEAN                            ExactMatch
  );

// APPLE_KEY_MAP_AGGREGATOR_PROTOCOL
/// The structure exposed by the APPLE_KEY_MAP_AGGREGATOR_PROTOCOL.
struct APPLE_KEY_MAP_AGGREGATOR_PROTOCOL {
  /// The revision of the installed protocol.
  UINTN                        Revision;

  /// A pointer to the GetKeyStrokes function.
  KEY_MAP_GET_KEY_STROKES      GetKeyStrokes;

  /// A pointer to the ContainsKeyStrokes function.
  KEY_MAP_CONTAINS_KEY_STROKES ContainsKeyStrokes;
};

// gAppleKeyMapAggregatorProtocolGuid
/// A global variable storing the GUID of the APPLE_KEY_MAP_AGGREGATOR_PROTOCOL.
extern EFI_GUID gAppleKeyMapAggregatorProtocolGuid;

#endif // APPLE_KEY_MAP_AGGREGATOR_H_
