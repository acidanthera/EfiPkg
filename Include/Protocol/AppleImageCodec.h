/** @file
  Copyright (C) 2012, tiamo.  All rights reserved.<BR>
  Copyright (C) 2014, dmazar.  All rights reserved.<BR>
  Copyright (C) 2018, savvas.  All rights reserved.<BR>
  Copyright (C) 2018, CupertinoNet.  All rights reserved.<BR>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
**/

#ifndef APPLE_IMAGE_CODEC_H_
#define APPLE_IMAGE_CODEC_H_

#define APPLE_IMAGE_CODEC_PROTOCOL_GUID               \
  { 0x0DFCE9F6, 0xC4E3, 0x45EE,                       \
    {0xA0, 0x6A, 0xA8, 0x61, 0x3B, 0x98, 0xA5, 0x07 } }

//
// Protocol revision
//
#define APPLE_IMAGE_CODEC_PROTOCOL_REVISION 0x20000

//
// Generic protocol extension capable of opening any file,
// possibly by chainloading other files
//
#define APPLE_IMAGE_CODEC_PROTOCOL_ANY_EXTENSION 0

//
// Interface version for Ver-suffixed functions
//
#define APPLE_IMAGE_CODEC_PROTOCOL_INTERFACE_V1 1

typedef
EFI_STATUS
(EFIAPI* RECOGNIZE_IMAGE_DATA) (
  IN VOID                 *ImageBuffer,
  IN UINTN                ImageSize
  );

typedef
EFI_STATUS
(EFIAPI* GET_IMAGE_DIMS) (
  IN  VOID                *ImageBuffer,
  IN  UINTN               ImageSize,
  OUT UINT32              *ImageWidth,
  OUT UINT32              *ImageHeight
  );

typedef
EFI_STATUS
(EFIAPI* DECODE_IMAGE_DATA) (
  IN     VOID            *ImageBuffer,
  IN     UINTN           ImageSize,
  IN OUT EFI_UGA_PIXEL   **RawImageData,
     OUT UINTN           *RawImageDataSize
  );

typedef
EFI_STATUS
(EFIAPI* GET_IMAGE_DIMS_VER) (
  IN  VOID               *ImageBuffer,
  IN  UINTN              ImageSize,
  IN  UINTN              Version,
  OUT UINT32             *ImageWidth,
  OUT UINT32             *ImageHeight
  );

typedef
EFI_STATUS
(EFIAPI* DECODE_IMAGE_DATA_VER) (
  IN     VOID            *ImageBuffer,
  IN     UINTN           ImageSize,
  IN     UINTN           Version,
  IN OUT EFI_UGA_PIXEL   **RawImageData,
     OUT UINTN           *RawImageDataSize
  );

typedef struct APPLE_IMAGE_CODEC_PROTOCOL_
{
  UINT64                 Revision;
  UINTN                  FileExt;
  RECOGNIZE_IMAGE_DATA   RecognizeImageData;
  GET_IMAGE_DIMS         GetImageDims;
  DECODE_IMAGE_DATA      DecodeImageData;
  GET_IMAGE_DIMS_VER     GetImageDimsVer;
  DECODE_IMAGE_DATA_VER  DecodeImageDataVer;
} APPLE_IMAGE_CODEC_PROTOCOL;

extern EFI_GUID gAppleImageCodecProtocolGuid;

#endif //APPLE_IMAGE_CODEC_H_
