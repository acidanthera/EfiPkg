/** @file
  Copyright (c) 2005 - 2017, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2014 - 2017, CupertinoNet.  All rights reserved.<BR>

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
#ifndef APPLE_PLATFORM_INFO_H_
#define APPLE_PLATFORM_INFO_H_

// APPLE_FSB_FREQUENCY_PLATFORM_INFO_GUID
#define APPLE_FSB_FREQUENCY_PLATFORM_INFO_GUID  \
  { 0xD1A04D55, 0x75B9, 0x41A3,                 \
    { 0x90, 0x36, 0x8F, 0x4A, 0x26, 0x1C, 0xBB, 0xA2 } }

// gAppleFsbFrequencyPlatformInfoGuid
extern EFI_GUID gAppleFsbFrequencyPlatformInfoGuid;

// APPLE_PLATFORM_INFO_KEYBOARD_GUID
#define APPLE_PLATFORM_INFO_KEYBOARD_GUID  \
  { 0x51871CB9, 0xE25D, 0x44B4,            \
    { 0x96, 0x99, 0x0E, 0xE8, 0x64, 0x4C, 0xED, 0x69 } }

// APPLE_KEYBOARD_INFO
typedef UINT32 APPLE_KEYBOARD_INFO;

// gAppleKeyboardPlatformInfoGuid
extern EFI_GUID gAppleKeyboardPlatformInfoGuid;

// APPLE_PRODUCT_INFO_PLATFORM_INFO_GUID
#define APPLE_PRODUCT_INFO_PLATFORM_INFO_GUID  \
  { 0xBF7F6F3A, 0x5523, 0x488E,                \
    { 0x8A, 0x60, 0xF0, 0x48, 0x63, 0xB9, 0x75, 0xC3 } }

// APPLE_PRODUCT_INFO
typedef struct {
  UINT8  Unknwon[86];
  CHAR8  Model[64];
  CHAR16 Family[64];
} APPLE_PRODUCT_INFO;

// gAppleProductInfoPlatformInfoGuid
extern EFI_GUID gAppleProductInfoPlatformInfoGuid;

#endif // APPLE_PLATFORM_INFO_H_
