/** @file
  Base Library CPU functions for Itanium

  Copyright (c) 2006 - 2008, Intel Corporation.  All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
**/

#include <AppleEfi.h>

#include <Library/MmioLib.h>

// MemoryFence
/** Used to serialize load and store operations.

  All loads and stores that proceed calls to this function are guaranteed to be
  globally visible when this function returns.
**/
VOID
EFIAPI
MemoryFence (
  VOID
  )
{
  __mfa ();
}
