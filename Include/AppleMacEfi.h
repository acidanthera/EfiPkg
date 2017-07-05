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

#ifndef APPLE_MAC_EFI_H_
#define APPLE_MAC_EFI_H_

#include <AppleCpuType.h>

#include <Uefi.h>
#include <AppleMacEfi/AppleMacEfiSpec.h>

#ifndef ARRAY_SIZE

  /**
    Return the number of elements in an array.

    @param  Array  An object of array type. Array is only used as an argument to
                   the sizeof operator, therefore Array is never evaluated. The
                   caller is responsible for ensuring that Array's type is not
                   incomplete; that is, Array must have known constant size.

    @return The number of elements in Array. The result has type UINTN.

  **/
  #define ARRAY_SIZE(Array) (sizeof (Array) / sizeof ((Array)[0]))

#endif

#endif // APPLE_MAC_EFI_H_
