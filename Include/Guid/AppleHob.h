/** @file
  Copyright (C) 2005 - 2016, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2014 - 2016, CupertinoNet.  All rights reserved.<BR>

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

#ifndef APPLE_HOB_H_
#define APPLE_HOB_H_

// APPLE_HOB_1_GUID
#define APPLE_HOB_1_GUID                                  \
  { 0x908B63A8, 0xC7C8, 0x493A,                           \
    { 0x80, 0x72, 0x9D, 0x58, 0xDB, 0xCF, 0x72, 0x4D } }

// APPLE_HOB_2_GUID
#define APPLE_HOB_2_GUID                                  \
  { 0xC78F061E, 0x0290, 0x4E4F,                           \
    { 0x8D, 0xDC, 0x5B, 0xDA, 0xAC, 0x83, 0x7D, 0xE5 } }

// APPLE_HOB_3_GUID
#define APPLE_HOB_3_GUID                                  \
  { 0xB8E65062, 0xFB30, 0x4078,                           \
    { 0xAB, 0xD3, 0xA9, 0x4E, 0x09, 0xCA, 0x9D, 0xE6 } }

// APPLE_DRIVER_INIT_HOB_GUID
#define APPLE_DRIVER_INIT_HOB_GUID                        \
  { 0xEF4AE2DD, 0xB736, 0x40E3,                           \
    { 0x80, 0x61, 0xA7, 0x46, 0x33, 0x34, 0x7F, 0x23 } }

// gAppleHob1Guid
extern EFI_GUID gAppleHob1Guid;

// gAppleHob1Guid
extern EFI_GUID gAppleHob2Guid;

// gAppleHob1Guid
extern EFI_GUID gAppleHob3Guid;

// gAppleDriverInitHobGuid
extern EFI_GUID gAppleDriverInitHobGuid;

#endif //ifndef APPLE_HOB_H_
