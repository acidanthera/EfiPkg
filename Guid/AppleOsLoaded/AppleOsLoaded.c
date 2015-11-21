// 20/11/2015

#include <AppleEfi.h>

#include <Guid/AppleOsLoaded.h>

// gAppleOsLoadedNamedEventGuid
EFI_GUID gAppleOsLoadedNamedEventGuid = APPLE_OS_LOADED_EVENT_NAME_GUID;

EFI_GUID_STRING (&gAppleOsLoadedNamedEventGuid, "Apple OS Loaded", "Apple OS Loaded Event Name");
