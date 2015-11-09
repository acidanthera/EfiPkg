#include <AppleEfi.h>

#include <Protocol/AppleDiskIo.h>

// gAppleDiskIoProtocolGuid
EFI_GUID gAppleDiskIoProtocolGuid = APPLE_DISK_IO_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleDiskIoProtocolGuid, "Disk IO", "Apple Disk IO Protocol");
