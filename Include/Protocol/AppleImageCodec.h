//
// Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
//
// This program and the accompanying materials have not been licensed.
// Neither is its usage, its redistribution, in source or binary form,
// licensed, nor implicitely or explicitely permitted, except when
// required by applicable law.
//
// Unless required by applicable law or agreed to in writing, software
// distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
// OR CONDITIONS OF ANY KIND, either express or implied.
//

///
/// @file      Include/Protocol/AppleImageCodec.h
///
///            
///
/// @author    tiamo
/// @author    dmazar
/// @date      28/08/2012: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.

#ifndef __APPLE_IMAGE_CODEC_H__
#define __APPLE_IMAGE_CODEC_H__

#include <Protocol/UgaDraw/UgaDraw.h>

// APPLE_IMAGE_CODEC_PROTOCOL_GUID
#define APPLE_IMAGE_CODEC_PROTOCOL_GUID \
  { 0x0DFCE9F6, 0xC4E3, 0x45EE, { 0xA0, 0x6A, 0xA8, 0x61, 0x3B, 0x98, 0xA5, 0x07 } }

// IMAGE_CODEC_RECOGNIZE_IMAGE_DATA
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *IMAGE_CODEC_RECOGNIZE_IMAGE_DATA)(
  VOID   *ImageBuffer,
  UINTN  ImageSize
  );

// IMAGE_CODEC_GET_IMAGE_DIMS
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *IMAGE_CODEC_GET_IMAGE_DIMS)(
  VOID    *ImageBuffer,
  UINTN   ImageSize,
  UINT32  *ImageWidth,
  UINT32  *ImageHeight
  );

// IMAGE_CODEC_DECODE_IMAGE_DATA
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *IMAGE_CODEC_DECODE_IMAGE_DATA)(
  VOID           *ImageBuffer,
  UINTN          ImageSize,
  EFI_UGA_PIXEL  **RawImageData,
  UINTN          *RawImageDataSize
  );

// _APPLE_IMAGE_CODEC_PROTOCOL
typedef struct _APPLE_IMAGE_CODEC_PROTOCOL {
  UINT64                           Version;             ///< 
  UINTN                            ImageType;           ///< 
  IMAGE_CODEC_RECOGNIZE_IMAGE_DATA RecognizeImageData;  ///< 
  IMAGE_CODEC_GET_IMAGE_DIMS       GetImageDims;        ///< 
  IMAGE_CODEC_DECODE_IMAGE_DATA    DecodeImageData;     ///< 
} APPLE_IMAGE_CODEC_PROTOCOL;

// gAppleImageCodecProtocolGuid
extern EFI_GUID gAppleImageCodecProtocolGuid;

#endif // ifndef __APPLE_IMAGE_CODEC_H__
