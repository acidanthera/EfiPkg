//
// Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>
// This program and the accompanying materials
// are licensed and made available under the terms and conditions of the BSD License
// which accompanies this distribution.  The full text of the license may be found at
// http://opensource.org/licenses/bsd-license.php.
//
// THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
// WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
//

///
/// @file      Library/AppleMathLib/DivS64x64.c
///
///            Math worker functions.
///
/// @copyright Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.
///

#include "AppleMathLibInternals.h"

// DivS64x64
/// Divides a 64-bit signed integer by a 64-bit signed integer and generates a
/// 64-bit signed result and a optional 64-bit signed remainder.
///
/// This function divides the 64-bit signed value Dividend by the 64-bit signed
/// value Divisor and generates a 64-bit signed quotient. This function
/// returns the 64-bit signed quotient.
///
/// It is the caller's responsibility to not call this function with a Divisor of 0.
/// If Divisor is 0, then the quotient and remainder should be assumed to be
/// the largest negative integer.
///
/// If Divisor is 0, then ASSERT().
///
/// @param  Dividend  A 64-bit signed value.
/// @param  Divisor   A 64-bit signed value.
///
/// @return Dividend / Divisor
INT64
EFIAPI
DivS64x64 (
  IN INT64  Dividend,
  IN INT64  Divisor
  )
{
  ASSERT (Divisor != 0);
  return InternalMathDivS64x64 (Dividend, Divisor);
}
