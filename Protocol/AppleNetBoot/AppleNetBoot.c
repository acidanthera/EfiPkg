#include <AppleEfi.h>

#include <Protocol/AppleNetBoot.h>

// gAppleNetBootProtocolGuid
EFI_GUID gAppleNetBootProtocolGuid = APPLE_NET_BOOT_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleNetBootProtocolGuid, "Net Boot", "Apple Net Boot Protocol");
