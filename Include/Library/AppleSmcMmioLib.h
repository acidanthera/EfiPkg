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

///
/// @file      Include/Library/AppleSmcMmioLib.h
///
///            
///
/// @author    Download-Fritz
/// @date      22/10/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

// 02/12/2015

#ifndef __APPLE_SMC_MMIO_LIB_H__
#define __APPLE_SMC_MMIO_LIB_H__

#include <IndustryStandard/AppleSmc.h>

// SmcReadValueMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcReadValueMmio (
  IN     SMC_ADDRESS    BaseAddress,
  IN     SMC_KEY        Key,
  IN OUT SMC_DATA_SIZE  *Size,
  OUT    SMC_DATA       *Value
  );

// SmcWriteValueMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcWriteValueMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN SMC_KEY      Key,
  IN UINT32       Size,
  IN SMC_DATA     *Value
  );

// SmcGetKeyFromIndexMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcGetKeyFromIndexMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN SMC_INDEX    Index,
  IN SMC_KEY      *Key
  );

// SmcGetKeyInfoMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcGetKeyInfoMmio (
  IN SMC_ADDRESS         BaseAddress,
  IN SMC_KEY             Key,
  IN SMC_DATA_SIZE       *Size,
  IN SMC_KEY_TYPE        *Type,
  IN SMC_KEY_ATTRIBUTES  *Attributes
  );

// SmcFlashTypeMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcFlashTypeMmio (
  IN SMC_ADDRESS     BaseAddress,
  IN SMC_FLASH_TYPE  Type
  );

// SmcFlashWriteMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcFlashWriteMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Unknown,
  IN UINT32       Size,
  IN SMC_DATA     *Data
  );

// SmcFlashAuthMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcFlashAuthMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Size,
  IN SMC_DATA     *Data
  );

// SmcMmioInterface
/// 
///
/// @param 
///
/// @return 
/// @retval 
BOOLEAN
SmcMmioInterface (
  IN SMC_ADDRESS  BaseAddress
  );

// SmcResetMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcResetMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Mode
  );

#endif // ifndef __APPLE_SMC_MMIO_LIB_H__
