/** @file
  Copyright (C) 2005 - 2015 Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_DRIVER_LIB_H_
#define APPLE_DRIVER_LIB_H_

#include <EfiDriverLib.h>

// AppleInitializeDriverLib
/** Intialize Driver Lib if it has not yet been initialized.

  @param[in] ImageHandle  Standard EFI Image entry parameter
  @param[in] SystemTable  Standard EFI Image entry parameter
 
  @retval EFI_SUCCESS  Operation succeeded
**/
EFI_STATUS
AppleInitializeDriverLib (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

#endif // APPLE_DRIVER_LIB_H_
