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

#include <AppleEfi.h>

#include <Library/AppleDriverLib.h>

#include EFI_GUID_DEFINITION (Hob)
#include <Guid/AppleHob.h>

#include <EfiHobLib.h>

// mAppleDriverInitHobData
STATIC VOID *mAppleDriverInitHobData;

// SaveAppleDriverInitHobData 
VOID
SaveAppleDriverInitHobData (
  IN VOID  *Data
  )
{
  mAppleDriverInitHobData = Data;
}

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
  )
{
  VOID                 *Table;
  EFI_PEI_HOB_POINTERS TableWalker;
  BOOLEAN              Match;

  EfiInitializeDriverLib (ImageHandle, SystemTable);
  EfiLibGetSystemConfigurationTable (&gEfiHobListGuid, &Table);

  TableWalker.Raw = Table;

  if (!END_OF_HOB_LIST (TableWalker)) {
    do {
      GetHob (EFI_HOB_TYPE_GUID_EXTENSION, (VOID *)TableWalker.Raw);

      if (GET_HOB_TYPE (TableWalker) == EFI_HOB_TYPE_GUID_EXTENSION) {
        Match = EfiCompareGuid (&gAppleDriverInitHobGuid, &TableWalker.Guid->Name);

        if (Match) {
          Table = (VOID *)GET_NEXT_HOB (TableWalker);

          SaveAppleDriverInitHobData ((VOID *)((UINTN)TableWalker.Raw + sizeof (*TableWalker.Guid)));
          break;
        }
      }

      Table           = (VOID *)GET_NEXT_HOB (TableWalker);
      TableWalker.Raw = GET_NEXT_HOB (TableWalker);
    } while (!END_OF_HOB_LIST (TableWalker));
  }

  return EFI_SUCCESS;
}