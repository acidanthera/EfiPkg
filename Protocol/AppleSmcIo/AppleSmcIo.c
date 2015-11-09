#include <AppleEfi.h>

#include <Protocol/AppleSmcIo.h>

// gAppleSmcIoProtocolGuid
EFI_GUID gAppleSmcIoProtocolGuid = APPLE_SMC_IO_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleSmcIoProtocolGuid, "SMC IO", "Apple SMC IO Protocol");
