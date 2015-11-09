#include <AppleEfi.h>

#include <Protocol/AppleFramebufferInfo.h>

// gAppleFramebufferInfoProtocolGuid
EFI_GUID gAppleFramebufferInfoProtocolGuid = APPLE_FRAMEBUFFER_INFO_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleFramebufferInfoProtocolGuid, "Framebuffer Info", "Apple Framebuffer Info Protocol");
