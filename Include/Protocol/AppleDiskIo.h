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
/// @file      Include/Protocol/AppleDiskIo.h
///
///            
///
/// @author    tiamo
/// @date      15/09/2012: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.

#ifndef __APPLE_DISK_IO_H__
#define __APPLE_DISK_IO_H__

// APPLE_DISK_IO_PROTOCOL_GUID
#define APPLE_DISK_IO_PROTOCOL_GUID \
  { 0x5B27263B, 0x9083, 0x415E, { 0x88, 0x9E, 0x64, 0x32, 0xCA, 0xA9, 0xB8, 0x13 } }

FORWARD_DECLARATION (APPLE_DISK_IO_PROTOCOL);

// DISK_IO_READ
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *DISK_IO_READ)(
  IN  APPLE_DISK_IO_PROTOCOL  *This,
  IN  UINT32                  MediaId,
  IN  UINT64                  LBA,
  IN  UINTN                   BufferSize,
  OUT VOID                    *Buffer
  );

// APPLE_DISK_FLUSH
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *DISK_IO_FLUSH)(
  IN APPLE_DISK_IO_PROTOCOL  *This
  );

// _APPLE_DISK_IO_PROTOCOL
struct _APPLE_DISK_IO_PROTOCOL {
  DISK_IO_READ  Read;   ///< 
  DISK_IO_FLUSH Flush;  ///< 
};

// gAppleDiskIoProtocolGuid
extern EFI_GUID gAppleDiskIoProtocolGuid;

#endif // ifndef __APPLE_DISK_IO_H__
