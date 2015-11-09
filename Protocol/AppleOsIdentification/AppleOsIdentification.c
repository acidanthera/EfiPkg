#include <AppleEfi.h>

#include <Protocol/AppleOsIdentification.h>

// gEfiOsIdentificationProtocolGuid
EFI_GUID gEfiOsIdentificationProtocolGuid = EFI_OS_IDENTIFICATION_PROTOCOL_GUID;

EFI_GUID_STRING (&gEfiOsIdentificationProtocolGuid, "OS Identification", "Apple OS Identification Protocol");

// gAppleOsLoadedNamedEventGuid
EFI_GUID gAppleOsLoadedNamedEventGuid = APPLE_OS_LOADED_EVENT_NAME_GUID;

EFI_GUID_STRING (&gAppleOsLoadedNamedEventGuid, "Apple OS Identification", "Apple OS Identification Event Name");
