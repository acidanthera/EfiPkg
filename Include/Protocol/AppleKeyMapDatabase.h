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
/// @file      Include/Protocol/AppleKeyMapDatabase.h
///
///            The Apple protocol to manage the database of pressed keys during the boot process.
///
/// @author    Download-Fritz
/// @date      15/03/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_KEY_MAP_DATABASE_H__
#define __APPLE_KEY_MAP_DATABASE_H__

// APPLE_KEY_MAP_DATABASE_PROTOCOL_GUID
/// The GUID of the APPLE_KEY_MAP_DATABASE_PROTOCOL.
#define APPLE_KEY_MAP_DATABASE_PROTOCOL_GUID \
  { 0x584B9EBE, 0x80C1, 0x4BD6, { 0x98, 0xB0, 0xA7, 0x78, 0x6E, 0xC2, 0xF2, 0xE2 } }

FORWARD_DECLARATION (APPLE_KEY_MAP_DATABASE_PROTOCOL);

// KEY_MAP_CREATE_KEY_STROKES_BUFFER
/// Creates a new key set with a given number of keys allocated. The index within the database is returned.
///
/// @param[in]  This           A pointer to the protocol instance.
/// @param[in]  KeyBufferSize  The amount of keys to allocate for the key set.
/// @param[out] Index          The assigned index of the created key set.
///
/// @return                       Returned is the status of the operation.
/// @retval EFI_SUCCESS           A key set with the given number of keys allocated has been created.
/// @retval EFI_OUT_OF_RESOURCES  The memory necessary to complete the operation could not be allocated.
/// @retval other                 An error returned by a sub-operation.
typedef
EFI_STATUS
(EFIAPI *KEY_MAP_CREATE_KEY_STROKES_BUFFER)(
  IN  APPLE_KEY_MAP_DATABASE_PROTOCOL  *This,
  IN  UINTN                            KeyBufferSize,
  OUT UINTN                            *Index
  );

// KEY_MAP_REMOVE_KEY_STROKES_BUFFER
/// Removes a key set specified by its index from the database.
///
/// @param[in] This   A pointer to the protocol instance.
/// @param[in] Index  The index of the key set to remove.
///
/// @return                Returned is the status of the operation.
/// @retval EFI_SUCCESS    The specified key set has been removed.
/// @retval EFI_NOT_FOUND  No key set could be found for the given index.
/// @retval other          An error returned by a sub-operation.
typedef
EFI_STATUS
(EFIAPI *KEY_MAP_REMOVE_KEY_STROKES_BUFFER)(
  IN APPLE_KEY_MAP_DATABASE_PROTOCOL  *This,
  IN UINTN                            Index
  );

// KEY_MAP_SET_KEY_STROKES_KEYS
/// Sets the keys of a key set specified by its index to the given Keys buffer.
///
/// @param[in] This       A pointer to the protocol instance.
/// @param[in] Index      The index of the key set to edit.
/// @param[in] Modifiers  The key modifiers manipulating the given keys.
/// @param[in] NoKeys     The number of keys contained in Keys.
/// @param[in] Keys       An array of keys to add to the specified key set.
///
/// @return                       Returned is the status of the operation.
/// @retval EFI_SUCCESS           The given keys were set for the specified key set.
/// @retval EFI_OUT_OF_RESOURCES  The memory necessary to complete the operation could not be allocated.
/// @retval EFI_NOT_FOUND         No key set could be found for the given index.
/// @retval other                 An error returned by a sub-operation.
typedef
EFI_STATUS
(EFIAPI *KEY_MAP_SET_KEY_STROKES_KEYS)(
  IN APPLE_KEY_MAP_DATABASE_PROTOCOL  *This,
  IN UINTN                            Index,
  IN APPLE_MODIFIER_MAP               Modifiers,
  IN UINTN                            NoKeys,
  IN APPLE_KEY                        *Keys
  );

// _APPLE_KEY_MAP_DATABASE_PROTOCOL
/// The structure exposed by the APPLE_KEY_MAP_DATABASE_PROTOCOL.
struct _APPLE_KEY_MAP_DATABASE_PROTOCOL {
  UINTN                             Revision;                ///< The revision of the installed protocol.
  KEY_MAP_CREATE_KEY_STROKES_BUFFER CreateKeyStrokesBuffer;  ///< A pointer to the CreateKeyStrokesBuffer function.
  KEY_MAP_REMOVE_KEY_STROKES_BUFFER RemoveKeyStrokesBuffer;  ///< A pointer to the RemoveKeyStrokes function.
  KEY_MAP_SET_KEY_STROKES_KEYS      SetKeyStrokeBufferKeys;  ///< A pointer to the SetKeyStrokeBufferKeys function.
};

// gAppleKeyMapDatabaseProtocolGuid
/// A global variable storing the GUID of the APPLE_KEY_MAP_DATABASE_PROTOCOL.
extern EFI_GUID gAppleKeyMapDatabaseProtocolGuid;

#endif // ifndef __APPLE_KEY_MAP_DATABASE_H__
