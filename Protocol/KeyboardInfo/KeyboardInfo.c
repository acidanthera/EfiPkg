#include <AppleEfi.h>

#include <Protocol/KeyboardInfo.h>

// gEfiKeyboardInfoProtocolGuid
EFI_GUID gEfiKeyboardInfoProtocolGuid = EFI_KEYBOARD_INFO_PROTOCOL_GUID;

EFI_GUID_STRING (&gEfiKeyboardInfoProtocolGuid, "Keyboard Info", "EFI keyboard Info Protocol");
