//******************************************************************** 
//	created:	21:8:2012   22:43 
//	filename: 	AppleNetBoot.h 
//	author:		tiamo 
//	purpose:	apple net boot 
//******************************************************************** 


#ifndef __APPLE_NET_BOOT_H__
#define __APPLE_NET_BOOT_H__

// APPLE_NET_BOOT_PROTOCOL_GUID
#define APPLE_NET_BOOT_PROTOCOL_GUID \
  { 0x78EE99FB, 0x6A5E, 0x4186, { 0x97, 0xDE, 0xCD, 0x0A, 0xBA, 0x34, 0x5A, 0x74 } }

FORWARD_DECLARATION (APPLE_NET_BOOT_PROTOCOL);

// GET_DHCP_RESPONSE
typedef
EFI_STATUS
(EFIAPI *GET_DHCP_RESPONSE)(
  IN  APPLE_NET_BOOT_PROTOCOL  *This,
  OUT UINTN                    *BufferSize,
  OUT VOID                     *DataBuffer
  );

// GET_BSDP_RESPONSE
typedef
EFI_STATUS
(EFIAPI *GET_BSDP_RESPONSE)(
  IN  APPLE_NET_BOOT_PROTOCOL  *This,
  OUT UINTN                    *BufferSize,
  OUT VOID                     *DataBuffer
  );

// _APPLE_NET_BOOT_PROTOCOL
struct _APPLE_NET_BOOT_PROTOCOL {
  GET_DHCP_RESPONSE GetDhcpResponse;
  GET_BSDP_RESPONSE GetBsdpResponse;
};

// gAppleNetBootProtocolGuid
extern EFI_GUID gAppleNetBootProtocolGuid;

#endif // ifndef __APPLE_NET_BOOT_H__
