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
/// @file      Include/Protocol/DevicePathPropertyDatabase.h
///
///            Apple protocol to manage Device Properties from firmware.
///
/// @author    Download-Fritz
/// @date      23/02/2015: Initial version
/// @date      15/03/2015: Updated documentation
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __DEVICE_PATH_PROPERTY_DATABASE_H__
#define __DEVICE_PATH_PROPERTY_DATABASE_H__

//
// Related definitions
//

// _DEVICE_PATH_PROPERTY_DATA
/// The structure defining the header of a Device Property data set.
typedef struct _DEVICE_PATH_PROPERTY_DATA {
  struct {
    UINT32 Size;  ///< The size, in bytes, of the current data set.
  }     Hdr;  ///< 
  UINT8 Data; ///< The begin of the data.
} EFI_DEVICE_PATH_PROPERTY_DATA;

// _DEVICE_PATH_PROPERTY_BUFFER_NODE
/// The structure defining the header of a Device Property node.
typedef struct _DEVICE_PATH_PROPERTY_BUFFER_NODE {
  struct {
    UINT32                       Size;          ///< The size, in bytes, of the entire node.
    UINT32                       NoProperties;  ///< The number of properties within the node.
  }                              Hdr;         ///< The node header structure.
  EFI_DEVICE_PATH_PROTOCOL       DevicePath;  ///< The device path for the current node.
// EFI_DEVICE_PATH_PROPERTY_DATA Data;        ///< The begin of the Device Property data set.
} EFI_DEVICE_PATH_PROPERTY_BUFFER_NODE;

// _DEVICE_PATH_PROPERTY_BUFFER
/// The structure defining the header of a Device Property buffer.
typedef struct _DEVICE_PATH_PROPERTY_BUFFER {
  struct {
    UINT32                             Size;     ///< The size, in bytes, of the entire buffer.
    UINT32                             MustBe1;  ///< Must be 1.
    UINT32                             NoNodes;  ///< The number of nodes in the buffer.
  }                                    Hdr;   ///< The buffer header structure.
  EFI_DEVICE_PATH_PROPERTY_BUFFER_NODE Node;  ///< The first node in the buffer.
} EFI_DEVICE_PATH_PROPERTY_BUFFER;

//
// Protocol definition
//

// EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL_GUID
/// The GUID of the EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL.
#define EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL_GUID \
  { 0x91BD12FE, 0xF6C3, 0x44FB, { 0xA5, 0xB7, 0x51, 0x22, 0xAB, 0x30, 0x3A, 0xE0 } }

FORWARD_DECLARATION (EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL);

// DPP_DATABASE_GET_PROPERTY_VALUE
/// Locates a device property in the database and returns its value into Value.
///
/// @param[in]      This        A pointer to the protocol instance.
/// @param[in]      DevicePath  The device path of the device to get the property of.
/// @param[in]      Name        The Name of the requested property.
/// @param[out]     Value       The buffer allocated by the caller to return the value of the property into.
/// @param[in, out] Size        On input the size of the allocated Value buffer.
///                             On output the size required to fill the buffer.
///
/// @return                       The status of the operation is returned.
/// @retval EFI_BUFFER_TOO_SMALL  The memory required to return the value exceeds the size of the allocated buffer.
///                               The required size to complete the operation has been returned into Size.
/// @retval EFI_NOT_FOUND         The given device path does not have a property with the specified Name.
/// @retval EFI_SUCCESS           The operation completed successfully.
typedef
EFI_STATUS
(EFIAPI *DPP_DATABASE_GET_PROPERTY_VALUE)(
  IN     EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  IN     EFI_DEVICE_PATH_PROTOCOL                    *DevicePath,
  IN     CHAR16                                      *Name,
  OUT    VOID                                        *Value,
  IN OUT UINTN                                       *Size
  );

// DPP_DATABASE_SET_PROPERTY
/// Sets the sepcified property of the given device path to the provided Value.
///
/// @param[in]  This        A pointer to the protocol instance.
/// @param[in]  DevicePath  The device path of the device to set the property of.
/// @param[in]  Name        The Name of the desired property.
/// @param[in]  Value       The buffer holding the value to set the property to.
/// @param[out] Size        The size of the Value buffer.
///
/// @return                       The status of the operation is returned.
/// @retval EFI_OUT_OF_RESOURCES  The memory necessary to complete the operation could not be allocated.
/// @retval EFI_SUCCESS           The operation completed successfully.
typedef
EFI_STATUS
(EFIAPI *DPP_DATABASE_SET_PROPERTY)(
  IN EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  IN EFI_DEVICE_PATH_PROTOCOL                    *DevicePath,
  IN CHAR16                                      *Name,
  IN VOID                                        *Value,
  IN UINTN                                       Size
  );

// DPP_DATABASE_REMOVE_PROPERTY
/// Removes the sepcified property from the given device path.
///
/// @param[in] This        A pointer to the protocol instance.
/// @param[in] DevicePath  The device path of the device to set the property of.
/// @param[in] Name        The Name of the desired property.
///
/// @return                The status of the operation is returned.
/// @retval EFI_NOT_FOUND  The given device path does not have a property with the specified Name.
/// @retval EFI_SUCCESS    The operation completed successfully.
typedef
EFI_STATUS
(EFIAPI *DPP_DATABASE_REMOVE_PROPERTY)(
  IN EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  IN EFI_DEVICE_PATH_PROTOCOL                    *DevicePath,
  IN CHAR16                                      *Name
  );

// DPP_DATABASE_GET_PROPERTY_BUFFER
/// Returns a buffer of all device properties into Buffer.
///
/// @param[in]      This    A pointer to the protocol instance.
/// @param[out]     Buffer  The buffer allocated by the caller to return the property buffer into.
/// @param[in, out] Size    On input the size of the allocated Buffer.
///                                                   On output the size required to fill the buffer.
///
/// @return                       The status of the operation is returned.
/// @retval EFI_BUFFER_TOO_SMALL  The memory required to return the value exceeds the size of the allocated buffer.
///                               The required size to complete the operation has been returned into Size.
/// @retval EFI_SUCCESS           The operation completed successfully.
typedef
EFI_STATUS
(EFIAPI *DPP_DATABASE_GET_PROPERTY_BUFFER)(
  IN     EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL  *This,
  OUT    EFI_DEVICE_PATH_PROPERTY_BUFFER             *Buffer,
  IN OUT UINTN                                       *Size
  );

// _EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL
/// The structure exposed by the EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL.
struct _EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL {
  /// The revision of the installed protocol.
  UINT64                           Revision;

  /// Locates a device property in the database and returns its value into Value.
  DPP_DATABASE_GET_PROPERTY_VALUE  GetPropertyValue;

  /// Sets the sepcified property of the given device path to the provided Value.
  DPP_DATABASE_SET_PROPERTY        SetProperty;

  /// Removes the sepcified property from the given device path.
  DPP_DATABASE_REMOVE_PROPERTY     RemoveProperty;

  /// Returns a buffer of all device properties into Buffer.
  DPP_DATABASE_GET_PROPERTY_BUFFER GetPropertyBuffer;
};

// gEfiDevicePathPropertyDatabaseProtocolGuid
/// A global variable storing the GUID of the EFI_DEVICE_PATH_PROPERTY_DATABASE_PROTOCOL.
extern EFI_GUID gEfiDevicePathPropertyDatabaseProtocolGuid;

#endif // ifndef __DEVICE_PATH_PROPERTY_DATABASE_H__
