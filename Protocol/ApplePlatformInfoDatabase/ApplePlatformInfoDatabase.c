#include <AppleEfi.h>

#include <Protocol/ApplePlatformInfoDatabase.h>

// gApplePlatformInfoDatabaseProtocolGuid
EFI_GUID gApplePlatformInfoDatabaseProtocolGuid = APPLE_PLATFORM_INFO_DATABASE_PROTOCOL_GUID;

EFI_GUID_STRING (&gApplePlatformInfoDatabaseProtocolGuid, "Platform Info Database", "Apple Platform Info Database Protocol");
