#include <AppleEfi.h>

#include <Protocol/AppleFirmwarePassword.h>

// gAppleFirmwarePasswordProtocolGuid
EFI_GUID gAppleFirmwarePasswordProtocolGuid = APPLE_FIRMWARE_PASSWORD_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleFirmwarePasswordProtocolGuid, "Firmware Password", "Apple Firmware Password Protocol");
