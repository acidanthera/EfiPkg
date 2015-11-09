#include <AppleEfi.h>
#include <EfiDriverLib.h>

#include <IndustryStandard/AppleHid.h>

#include <Protocol/AppleEvent.h>

// gAppleEventProtocolGuid
EFI_GUID gAppleEventProtocolGuid = APPLE_EVENT_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleEventProtocolGuid, "Apple Event", "Apple Event Protocol");
