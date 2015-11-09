#include <AppleEfi.h>

#include <Protocol/AppleBootBeepGen.h>

// gAppleBootBeepGenProtocolGuid
EFI_GUID gAppleBootBeepGenProtocolGuid = APPLE_BOOT_BEEP_GEN_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleBootBeepGenProtocolGuid, "Boot Beep", "Apple Boot Beep Protocol");
