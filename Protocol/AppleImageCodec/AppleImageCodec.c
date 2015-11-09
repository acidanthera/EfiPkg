#include <AppleEfi.h>

#include <Protocol/AppleImageCodec.h>

// gAppleImageCodecProtocolGuid
EFI_GUID gAppleImageCodecProtocolGuid = APPLE_IMAGE_CODEC_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleImageCodecProtocolGuid, "Image Codec", "Apple Image Codec Protocol");
