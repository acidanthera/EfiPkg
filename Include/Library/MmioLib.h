/** @file
  Provide services to access I/O Ports and MMIO registers.

  Copyright (c) 2006 - 2012, Intel Corporation.  All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#ifndef MMIO_LIB_H_
#define MMIO_LIB_H_

// MemoryFence
/** Used to serialize load and store operations.

  All loads and stores that proceed calls to this function are guaranteed to be
  globally visible when this function returns.
**/
VOID
EFIAPI
MemoryFence (
  VOID
  );

// MmioRead8
/** Reads an 8-bit MMIO register.

  Reads the 8-bit MMIO register specified by Address.  The 8-bit read value is
  returned.  This function must guarantee that all MMIO read and write
  operations are serialized.

  If 8-bit MMIO register operations are not supported, then ASSERT().

  @param[in] Address  The MMIO register to read.

  @return  The value read.
**/
UINT8
EFIAPI
MmioRead8 (
  IN UINTN  Address
  );

// MmioWrite8
/** Writes an 8-bit MMIO register.

  Writes the 8-bit MMIO register specified by Address with the value specified
  by Value and returns Value.  This function must guarantee that all MMIO read
  and write operations are serialized.

  If 8-bit MMIO register operations are not supported, then ASSERT().

  @param[in] Address  The MMIO register to write.
  @param[in] Value    The value to write to the MMIO register.
 
  @return  Value.
**/
UINT8
EFIAPI
MmioWrite8 (
  IN UINTN  Address,
  IN UINT8  Value
  );

// MmioRead16
/** Reads a 16-bit MMIO register.

  Reads the 16-bit MMIO register specified by Address.  The 16-bit read value is
  returned.  This function must guarantee that all MMIO read and write
  operations are serialized.

  If 16-bit MMIO register operations are not supported, then ASSERT().
  If Address is not aligned on a 16-bit boundary, then ASSERT().

  @param[in] Address  The MMIO register to read.

  @return  The value read.
**/
UINT16
EFIAPI
MmioRead16 (
  IN UINTN  Address
  );

// MmioWrite16
/** Writes a 16-bit MMIO register.

  Writes the 16-bit MMIO register specified by Address with the value specified
  by Value and returns Value.  This function must guarantee that all MMIO read
  and write operations are serialized.

  If 16-bit MMIO register operations are not supported, then ASSERT().
  If Address is not aligned on a 16-bit boundary, then ASSERT().

  @param[in] Address  The MMIO register to write.
  @param[in] Value    The value to write to the MMIO register.

  @return  Value.
**/
UINT16
EFIAPI
MmioWrite16 (
  IN UINTN   Address,
  IN UINT16  Value
  );

// MmioRead32
/** Reads a 32-bit MMIO register.

  Reads the 32-bit MMIO register specified by Address.  The 32-bit read value is
  returned.  This function must guarantee that all MMIO read and write
  operations are serialized.

  If 32-bit MMIO register operations are not supported, then ASSERT().
  If Address is not aligned on a 32-bit boundary, then ASSERT().

  @param[in] Address  The MMIO register to read.

  @return  The value read.
**/
UINT32
EFIAPI
MmioRead32 (
  IN UINTN  Address
  );

// MmioWrite32
/** Writes a 32-bit MMIO register.

  Writes the 32-bit MMIO register specified by Address with the value specified
  by Value and returns Value.  This function must guarantee that all MMIO read
  and write operations are serialized.

  If 32-bit MMIO register operations are not supported, then ASSERT().
  If Address is not aligned on a 32-bit boundary, then ASSERT().

  @param[in] Address  The MMIO register to write.
  @param[in] Value    The value to write to the MMIO register.

  @return  Value.
**/
UINT32
EFIAPI
MmioWrite32 (
  IN UINTN   Address,
  IN UINT32  Value
  );

// MmioRead64
/** Reads a 64-bit MMIO register.

  Reads the 64-bit MMIO register specified by Address.  The 64-bit read value is
  returned.  This function must guarantee that all MMIO read and write
  operations are serialized.

  If 64-bit MMIO register operations are not supported, then ASSERT().
  If Address is not aligned on a 64-bit boundary, then ASSERT().

  @param[in] Address  The MMIO register to read.

  @return  The value read.
**/
UINT64
EFIAPI
MmioRead64 (
  IN UINTN  Address
  );

// MmioWrite64
/** Writes a 64-bit MMIO register.

  Writes the 64-bit MMIO register specified by Address with the value specified
  by Value and returns Value.  This function must guarantee that all MMIO read
  and write operations are serialized.

  If 64-bit MMIO register operations are not supported, then ASSERT().
  If Address is not aligned on a 64-bit boundary, then ASSERT().

  @param[in] Address  The MMIO register to write.
  @param[in] Value    The value to write to the MMIO register.
**/
UINT64
EFIAPI
MmioWrite64 (
  IN UINTN   Address,
  IN UINT64  Value
  );

#endif //ifdef MMIO_LIB_H_
