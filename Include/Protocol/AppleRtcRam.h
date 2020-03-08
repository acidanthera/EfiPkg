/** @file
  Apple RTC RAM.

Copyright (C) 2020, vit9696.  All rights reserved.<BR>
This program and the accompanying materials are licensed and made available
under the terms and conditions of the BSD License which accompanies this
distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php.

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef APPLE_RTC_RAM_H
#define APPLE_RTC_RAM_H

/**
  Installed by RTC driver.
  E121EC07-9C42-45EE-B0B6-FFF8EF03C521
**/

#define APPLE_RTC_RAM_PROTOCOL_GUID \
  { 0xE121EC07, 0x9C42, 0x45EE,     \
     { 0xB0, 0xB6, 0xFF, 0xF8, 0xEF, 0x03, 0xC5, 0x21 } }

extern EFI_GUID gAppleRtcRamProtocolGuid;

#endif // APPLE_RTC_RAM_H
