/** @file
  Copyright (C) 2016, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_PLATFORM_INFO_H_
#define APPLE_PLATFORM_INFO_H_

// APPLE_PLATFORM_INFO_KEYBOARD_GUID
#define APPLE_PLATFORM_INFO_KEYBOARD_GUID                 \
  { 0x51871CB9, 0xE25D, 0x44B4,                           \
    { 0x96, 0x99, 0x0E, 0xE8, 0x64, 0x4C, 0xED, 0x69 } }

// gApplePlatformInfoKeyboardGuid
extern EFI_GUID gApplePlatformInfoKeyboardGuid;

#endif // APPLE_PLATFORM_INFO_H_
