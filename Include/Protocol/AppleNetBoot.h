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
/// @file      Include/Protocol/AppleNetBoot.h
///
///            
///
/// @author    tiamo
/// @date      21/08/2012: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_NET_BOOT_H__
#define __APPLE_NET_BOOT_H__

// APPLE_NET_BOOT_PROTOCOL_GUID
#define APPLE_NET_BOOT_PROTOCOL_GUID \
  { 0x78EE99FB, 0x6A5E, 0x4186, { 0x97, 0xDE, 0xCD, 0x0A, 0xBA, 0x34, 0x5A, 0x74 } }

FORWARD_DECLARATION (APPLE_NET_BOOT_PROTOCOL);

// NET_BOOT_GET_DHCP_RESPONSE
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *NET_BOOT_GET_DHCP_RESPONSE)(
  IN  APPLE_NET_BOOT_PROTOCOL  *This,
  OUT UINTN                    *BufferSize,
  OUT VOID                     *DataBuffer
  );

// NET_BOOT_GET_BSDP_RESPONSE
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *NET_BOOT_GET_BSDP_RESPONSE)(
  IN  APPLE_NET_BOOT_PROTOCOL  *This,
  OUT UINTN                    *BufferSize,
  OUT VOID                     *DataBuffer
  );

// _APPLE_NET_BOOT_PROTOCOL
struct _APPLE_NET_BOOT_PROTOCOL {
  NET_BOOT_GET_DHCP_RESPONSE GetDhcpResponse;  ///< 
  NET_BOOT_GET_BSDP_RESPONSE GetBsdpResponse;  ///< 
};

// gAppleNetBootProtocolGuid
extern EFI_GUID gAppleNetBootProtocolGuid;

#endif // ifndef __APPLE_NET_BOOT_H__
