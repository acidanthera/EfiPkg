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

#ifndef APPLE_OS_LOADED_H_
#define APPLE_OS_LOADED_H_

// APPLE_OS_LOADED_EVENT_NAME
#define APPLE_OS_LOADED_NAMED_EVENT_GUID                   \
  { 0xC5C5DA95, 0x7D5C, 0x45E6,                           \
    { 0x83, 0x72, 0x89, 0xBD, 0x52, 0x6D, 0xE9, 0x56 } }

// gAppleOSLoadedNamedEventGuid
extern EFI_GUID gAppleOSLoadedNamedEventGuid;

#endif // APPLE_OS_LOADED_H_
