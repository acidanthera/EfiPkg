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

/// @file
/// Declaration of internal functions in AppleMathLib.
///
/// Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>
/// This program and the accompanying materials
/// are licensed and made available under the terms and conditions of the BSD License
/// which accompanies this distribution.  The full text of the license may be found at
/// http://opensource.org/licenses/bsd-license.php.
///
/// THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
/// WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

#ifndef __APPLE_MATH_LIB__
#define __APPLE_MATH_LIB__

// DivS64x64
/// 
///
/// @param 
///
/// @return 
/// @retval 
INT64
EFIAPI
DivS64x64 (
  IN  INT64 Dividend,
  IN  INT64 Divisor
  );

#endif // ifdef __APPLE_MATH_LIB__
