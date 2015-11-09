#include <AppleEfi.h>

#include <Protocol/AppleDeviceControl.h>

// gAppleDeviceControlProtocolGuid
EFI_GUID gAppleDeviceControlProtocolGuid = APPLE_DEVICE_CONTROL_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleDeviceControlProtocolGuid, "Device Control", "Apple Device Control Protocol");
