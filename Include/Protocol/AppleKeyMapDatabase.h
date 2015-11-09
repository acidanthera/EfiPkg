///
/// @file      Protocol/AppleKeyMapDatabase/AppleKeyMapDatabase.h
///
///            The Apple protocol to manage the database of pressed keys during the boot process.
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

#ifndef _APPLE_KEY_MAP_DATABASE_H_
#define _APPLE_KEY_MAP_DATABASE_H_

// APPLE_KEY_MAP_DATABASE_PROTOCOL_GUID
/// The GUID of the APPLE_KEY_MAP_DATABASE_PROTOCOL.
#define APPLE_KEY_MAP_DATABASE_PROTOCOL_GUID \
  { 0x584B9EBE, 0x80C1, 0x4BD6, { 0x98, 0xB0, 0xA7, 0x78, 0x6E, 0xC2, 0xF2, 0xE2 } }

FORWARD_DECLARATION (APPLE_KEY_MAP_DATABASE_PROTOCOL);

// CREATE_KEY_STROKES_BUFFER
/// Creates a new key set with a given number of keys allocated. The index within the database is returned.
///
/// @param[in]  This          A pointer to the protocol instance.
/// @param[in]  KeyBufferSize The amount of keys to allocate for the key set.
/// @param[out] Index         The assigned index of the created key set.
///
/// @return                      Returned is the status of the operation.
/// @retval EFI_SUCCESS          A key set with the given number of keys allocated has been created.
/// @retval EFI_OUT_OF_RESOURCES The memory necessary to complete the operation could not be allocated.
/// @retval other                An error returned by a sub-operation.
typedef
EFI_STATUS
(EFIAPI *CREATE_KEY_STROKES_BUFFER)(
  IN  APPLE_KEY_MAP_DATABASE_PROTOCOL  *This,
  IN  UINTN                            KeyBufferSize,
  OUT UINTN                            *Index
  );

// REMOVE_KEY_STROKES_BUFFER
/// Removes a key set specified by its index from the database.
///
/// @param[in] This  A pointer to the protocol instance.
/// @param[in] Index The index of the key set to remove.
///
/// @return               Returned is the status of the operation.
/// @retval EFI_SUCCESS   The specified key set has been removed.
/// @retval EFI_NOT_FOUND No key set could be found for the given index.
/// @retval other         An error returned by a sub-operation.
typedef
EFI_STATUS
(EFIAPI *REMOVE_KEY_STROKES_BUFFER)(
  IN APPLE_KEY_MAP_DATABASE_PROTOCOL  *This,
  IN UINTN                            Index
  );

// SET_KEY_STROKES_KEYS
/// Sets the keys of a key set specified by its index to the given Keys buffer.
///
/// @param[in] This      A pointer to the protocol instance.
/// @param[in] Index     The index of the key set to edit.
/// @param[in] Modifiers The key modifiers manipulating the given keys.
/// @param[in] NoKeys    The number of keys contained in Keys.
/// @param[in] Keys      An array of keys to add to the specified key set.
///
/// @return                      Returned is the status of the operation.
/// @retval EFI_SUCCESS          The given keys were set for the specified key set.
/// @retval EFI_OUT_OF_RESOURCES The memory necessary to complete the operation could not be allocated.
/// @retval EFI_NOT_FOUND        No key set could be found for the given index.
/// @retval other                An error returned by a sub-operation.
typedef
EFI_STATUS
(EFIAPI *SET_KEY_STROKES_KEYS)(
  IN APPLE_KEY_MAP_DATABASE_PROTOCOL  *This,
  IN UINTN                            Index,
  IN APPLE_MODIFIER_MAP               Modifiers,
  IN UINTN                            NoKeys,
  IN APPLE_KEY                        *Keys
  );

// _APPLE_KEY_MAP_DATABASE_PROTOCOL
/// The structure exposed by the APPLE_KEY_MAP_DATABASE_PROTOCOL.
struct _APPLE_KEY_MAP_DATABASE_PROTOCOL {
  UINTN                     Revision;                ///< The revision of the installed protocol.
  CREATE_KEY_STROKES_BUFFER CreateKeyStrokesBuffer;  ///< A pointer to the CreateKeyStrokesBuffer function.
  REMOVE_KEY_STROKES_BUFFER RemoveKeyStrokesBuffer;  ///< A pointer to the RemoveKeyStrokes function.
  SET_KEY_STROKES_KEYS      SetKeyStrokeBufferKeys;        ///< A pointer to the SetKeyStrokeBufferKeys function.
};

// gAppleKeyMapDatabaseProtocolGuid
/// A global variable storing the GUID of the APPLE_KEY_MAP_DATABASE_PROTOCOL.
extern EFI_GUID gAppleKeyMapDatabaseProtocolGuid;

#endif // ifndef _APPLE_KEY_MAP_DATABASE_H_
