#include <AppleEfi.h>

#include <Protocol/OsIdentification.h>

// gEfiOsIdentificationProtocolGuid
EFI_GUID gEfiOsIdentificationProtocolGuid = EFI_OS_IDENTIFICATION_PROTOCOL_GUID;

EFI_GUID_STRING (&gEfiOsIdentificationProtocolGuid, "OS Identification", "EFI OS Identification Protocol");
