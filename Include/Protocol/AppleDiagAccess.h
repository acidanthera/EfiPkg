/** @file
Copyright (C) 2017, Download-Fritz.  All rights reserved.<BR>
This program and the accompanying materials are licensed and made available
under the terms and conditions of the BSD License which accompanies this
distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef APPLE_DIAG_ACCESS_H
#define APPLE_DIAG_ACCESS_H

// APPLE_DIAG_ACCESS_PROTOCOL_GUID
#define APPLE_DIAG_ACCESS_PROTOCOL_GUID  \
  { 0xC5CFF4F1, 0x379A, 0x54E1,          \
    { 0x9E, 0xDD, 0x93, 0x21, 0x9C, 0x6A, 0xA4, 0xFE } }

// DIAG_ACCESS_GET
typedef
EFI_STATUS
(EFIAPI *DIAG_ACCESS_GET)(
  IN CHAR16     *Key,
  OUT VOID      *Value,
  IN OUT UINTN  *Size
  );

// APPLE_DIAG_ACCESS_PROTOCOL
typedef struct {
  UINTN           Revision;
  DIAG_ACCESS_GET Get;
} APPLE_DIAG_ACCESS_PROTOCOL;

// gAppleDiagAccessProtocolGuid
extern EFI_GUID gAppleDiagAccessProtocolGuid;

#endif // APPLE_DIAG_ACCESS_H
