/** @file
  Apple FileSystem BDS stage protocol to inform Apfs Loader, that Apple Filesystem
  not supported

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

#ifndef APFS_UNSUPPORTED_BDS_PROTOCOL_H_
#define APFS_UNSUPPORTED_BDS_PROTOCOL_H_

#define APFS_UNSUPPORTED_BDS_PROTOCOL_GUID \
  { 0xA196A7CA, 0x14C6, 0x11E7,            \
    {0xB9, 0x06, 0xB8, 0xE8, 0x56, 0x2C, 0xBA, 0xFA } }

extern EFI_GUID gApfsUnsupportedBdsProtocolGuid;

#endif // APFS_UNSUPPORTED_BDS_PROTOCOL_H_