/** @file
  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#include <AppleEfi.h>

#include "AppleMathLibInternal.h"

// MultU64x64
/** Multiplies a 64-bit unsigned integer by a 64-bit unsigned integer and
    generates a 64-bit unsigned result.

  This function multiplies the 64-bit unsigned value Multiplicand by the 64-bit
  unsigned value Multiplier and generates a 64-bit unsigned result. This 64-
  bit unsigned result is returned.

  @param  Multiplicand  A 64-bit unsigned value.
  @param  Multiplier    A 64-bit unsigned value.

  @return  Multiplicand * Multiplier.
**/
UINT64
EFIAPI
MultU64x64 (
  IN UINT64  Multiplicand,
  IN UINT64  Multiplier
  )
{
  return InternalMathMultU64x64 (Multiplicand, Multiplier);
}

// MultS64x64
/** Multiplies a 64-bit signed integer by a 64-bit signed integer and generates a
    64-bit signed result.

  This function multiplies the 64-bit signed value Multiplicand by the 64-bit
  signed value Multiplier and generates a 64-bit signed result. This 64-bit
  signed result is returned.

  @param  Multiplicand  A 64-bit signed value.
  @param  Multiplier    A 64-bit signed value.

  @return  Multiplicand * Multiplier.
**/
INT64
EFIAPI
MultS64x64 (
  IN INT64  Multiplicand,
  IN INT64  Multiplier
  )
{
  return (INT64)MultU64x64 ((UINT64)Multiplicand, (UINT64)Multiplier);
}

// MathLibDivU64x32
/** Divides a 64-bit unsigned integer by a 32-bit unsigned integer and
    generates a 64-bit unsigned result and an optional 32-bit unsigned remainder.

  This function divides the 64-bit unsigned value Dividend by the 32-bit
  unsigned value Divisor and generates a 64-bit unsigned quotient.
  This function returns the 64-bit unsigned quotient.

  It is the caller's responsibility to not call this function with a Divisor of 0.
  If Divisor is 0, then the quotient should be assumed to be the largest negative
  integer.

  If Divisor is 0, then ASSERT().

  @param  Dividend  A 64-bit unsigned value.
  @param  Divisor   A 32-bit unsigned value.

  @return  Dividend / Divisor.
**/
UINT64
EFIAPI
MathLibDivU64x32 (
  IN UINT64  Dividend,
  IN UINT32  Divisor
  )
{
  ASSERT (Divisor != 0);

  return InternalMathDivU64x32 (Dividend, Divisor);
}

// MathLibDivU64x64
/** Divides a 64-bit unsigned integer by a 64-bit unsigned integer and
    generates a 64-bit unsigned result and an optional 64-bit unsigned remainder.

  This function divides the 64-bit unsigned value Dividend by the 64-bit
  unsigned value Divisor and generates a 64-bit unsigned quotient.
  This function returns the 64-bit unsigned quotient.

  It is the caller's responsibility to not call this function with a Divisor of 0.
  If Divisor is 0, then the quotient should be assumed to be the largest negative
  integer.

  If Divisor is 0, then ASSERT().

  @param  Dividend  A 64-bit unsigned value.
  @param  Divisor   A 64-bit unsigned value.

  @return  Dividend / Divisor
**/
UINT64
EFIAPI
MathLibDivU64x64 (
  IN UINT64  Dividend,
  IN UINT64  Divisor
  )
{
  ASSERT (Divisor != 0);

  return InternalMathDivU64x64 (Dividend, Divisor);
}

// MathLibDivS64x64
/** Divides a 64-bit signed integer by a 64-bit signed integer and generates a
    64-bit signed result.

  This function divides the 64-bit signed value Dividend by the 64-bit signed
  value Divisor and generates a 64-bit signed quotient. This function
  returns the 64-bit signed quotient.

  It is the caller's responsibility to not call this function with a Divisor of 0.
  If Divisor is 0, then the quotient should be assumed to be the largest negative
  integer.

  If Divisor is 0, then ASSERT().

  @param  Dividend  A 64-bit signed value.
  @param  Divisor   A 64-bit signed value.

  @return  Dividend / Divisor
**/
INT64
EFIAPI
MathLibDivS64x64 (
  IN INT64  Dividend,
  IN INT64  Divisor
  )
{
  ASSERT (Divisor != 0);

  return InternalMathDivS64x64 (Dividend, Divisor);
}
