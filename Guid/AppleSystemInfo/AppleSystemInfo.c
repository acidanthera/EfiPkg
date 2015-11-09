#include <AppleEfi.h>
#include <TianoDevicePath.h>

#include EFI_GUID_DEFINITION (DataHubRecords)
#include <Guid/AppleSystemInfo.h>

// gAppleSystemInfoProducerNameGuid
EFI_GUID gAppleSystemInfoProducerNameGuid = APPLE_SYSTEM_INFO_PRODUCER_NAME_GUID;

EFI_GUID_STRING (&gAppleSystemInfoProducerNameGuid, "System Info", "Apple System Info Producer Name");
