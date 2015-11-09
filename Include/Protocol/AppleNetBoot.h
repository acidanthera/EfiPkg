#ifndef _APPLE_NET_BOOT_H_
#define _APPLE_NET_BOOT_H_

// APPLE_NET_BOOT_PROTOCOL_GUID
#define APPLE_NET_BOOT_PROTOCOL_GUID \
  { 0x78EE99FB, 0x6A5E, 0x4186, { 0x97, 0xDE, 0xCD, 0x0A, 0xBA, 0x34, 0x5A, 0x74 } }

FORWARD_DECLARATION (APPLE_NET_BOOT_PROTOCOL);

// GET_DHCP_RESPONSE
typedef
EFI_STATUS
(EFIAPI *GET_DHCP_RESPONSE)(
  APPLE_NET_BOOT_PROTOCOL  *This,
  UINTN                    *BufferSize,
  VOID                     *DataBuffer
  );

// GET_BSDP_RESPONSE
typedef
EFI_STATUS
(EFIAPI *GET_BSDP_RESPONSE)(
  APPLE_NET_BOOT_PROTOCOL  *This,
  UINTN                    *BufferSize,
  VOID                     *DataBuffer
  );

// _APPLE_NET_BOOT_PROTOCOL
struct _APPLE_NET_BOOT_PROTOCOL {
  GET_DHCP_RESPONSE GetDhcpResponse;
  GET_BSDP_RESPONSE GetBsdpResponse;
};

// gAppleNetBootProtocolGuid
extern EFI_GUID gAppleNetBootProtocolGuid;

#endif // ifndef _APPLE_NET_BOOT_H_
