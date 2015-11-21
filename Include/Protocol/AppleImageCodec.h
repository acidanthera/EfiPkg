//********************************************************************
//	created:	28:8:2012   20:54
//	filename: 	AppleImageCodec.h
//	author:		tiamo
//	purpose:	image code
//********************************************************************
// dmazar: changed ImageWidth and ImageHeight in GET_IMAGE_DIMS
//         to UINT32 from UINTN to get it working in 64 bit
//********************************************************************

#ifndef __APPLE_IMAGE_CODEC_H__
#define __APPLE_IMAGE_CODEC_H__

#include <Protocol/UgaDraw/UgaDraw.h>

// APPLE_IMAGE_CODEC_PROTOCOL_GUID
#define APPLE_IMAGE_CODEC_PROTOCOL_GUID \
  { 0x0DFCE9F6, 0xC4E3, 0x45EE, { 0xA0, 0x6A, 0xA8, 0x61, 0x3B, 0x98, 0xA5, 0x07 } }

// RECOGNIZE_IMAGE_DATA
typedef
EFI_STATUS
(EFIAPI *RECOGNIZE_IMAGE_DATA)(
  VOID   *ImageBuffer,
  UINTN  ImageSize
  );

// GET_IMAGE_DIMS
typedef
EFI_STATUS
(EFIAPI *GET_IMAGE_DIMS)(
  VOID    *ImageBuffer,
  UINTN   ImageSize,
  UINT32  *ImageWidth,
  UINT32  *ImageHeight
  );

// DECODE_IMAGE_DATA
typedef
EFI_STATUS
(EFIAPI *DECODE_IMAGE_DATA)(
  VOID           *ImageBuffer,
  UINTN          ImageSize,
  EFI_UGA_PIXEL  **RawImageData,
  UINTN          *RawImageDataSize
  );

// _APPLE_IMAGE_CODEC_PROTOCOL
typedef struct _APPLE_IMAGE_CODEC_PROTOCOL {
  UINT64               Version;
  UINTN                FileExt;
  RECOGNIZE_IMAGE_DATA RecognizeImageData;
  GET_IMAGE_DIMS       GetImageDims;
  DECODE_IMAGE_DATA    DecodeImageData;
} APPLE_IMAGE_CODEC_PROTOCOL;

// gAppleImageCodecProtocolGuid
extern EFI_GUID gAppleImageCodecProtocolGuid;

#endif // ifndef __APPLE_IMAGE_CODEC_H__
