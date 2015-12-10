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
/// @file      Library/AppleSmcMmioLib/AppleSmcMmioLib.c
///
///            
///
/// @author    Download-Fritz
/// @date      31/10/2015: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#include <AppleEfi.h>

#include <IndustryStandard/AppleSmc.h>

#include <Library/EdkIIGlueIoLib.h>

#define SwapBytes32(...) 0

// SmcReadKeyStatusMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT32
SmcReadKeyStatusMmio (
  IN UINTN  BaseAddress
  )
{
  return (UINT32)MmioRead8 (BaseAddress + SMC_MMIO_READ_KEY_STATUS);
}

// SmcReadResultMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT32
SmcReadResultMmio (
  IN UINTN  BaseAddress
  )
{
  return (UINT32)MmioRead8 (BaseAddress + SMC_MMIO_READ_RESULT);
}

// SmcWriteCommandMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT8
SmcWriteCommandMmio (
  IN UINTN   BaseAddress,
  IN UINT32  Command
  )
{
  return MmioWrite8 ((BaseAddress + SMC_MMIO_WRITE_COMMAND), (UINT8)Command);
}

// SmcWriteAttributesMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT8
SmcWriteAttributesMmio (
  IN UINTN   BaseAddress,
  IN UINT32  Attributes
  )
{
  return MmioWrite8 ((BaseAddress + SMC_MMIO_WRITE_KEY_ATTRIBUTES), (UINT8)Attributes);
}

// SmcReadDataSizeMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
SMC_DATA_SIZE
SmcReadDataSizeMmio (
  IN SMC_ADDRESS  BaseAddress
  )
{
  return (SMC_DATA_SIZE)MmioRead8 ((UINTN)(BaseAddress + SMC_MMIO_READ_DATA_SIZE));
}

// SmcWriteDataSizeMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT8
SmcWriteDataSizeMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Size
  )
{
  MmioWrite8 ((UINTN)(BaseAddress + SMC_MMIO_WRITE_DATA_SIZE), (UINT8)Size);

  return 0;
}

// SmcReadData8Mmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
SMC_DATA
SmcReadData8Mmio (
  IN SMC_ADDRESS  Address
  )
{
  return (SMC_DATA)MmioRead8 ((UINTN)Address);
}

// SmcWriteData8Mmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT8
SmcWriteData8Mmio (
  IN UINTN     Address,
  IN SMC_DATA  Data
  )
{
  return MmioWrite8 ((UINTN)Address, (UINT8)Data);
}

// SmcWriteData32Mmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
SmcWriteData32Mmio (
  IN SMC_ADDRESS  Address,
  IN UINT32       Data
  )
{
  SmcWriteData8Mmio ((UINTN)(Address + SMC_MMIO_DATA_FIXED), (SMC_DATA)(Data >> 24));
  SmcWriteData8Mmio ((UINTN)(Address + SMC_MMIO_DATA_FIXED + (1 * sizeof (SMC_DATA))), (SMC_DATA)(Data >> 16));
  SmcWriteData8Mmio ((UINTN)(Address + SMC_MMIO_DATA_FIXED + (2 * sizeof (SMC_DATA))), (SMC_DATA)(Data >> 8));
  SmcWriteData8Mmio ((UINTN)(Address + SMC_MMIO_DATA_FIXED + (3 * sizeof (SMC_DATA))), (SMC_DATA)Data);

  return EFI_SUCCESS;
}

// SmcReadData32Mmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT32
SmcReadData32Mmio (
  IN UINTN  Address
  )
{
  UINT32 Data;

  Data  = (MmioRead8 (Address + SMC_MMIO_DATA_VARIABLE) << 24);
  Data |= (MmioRead8 (Address + SMC_MMIO_DATA_VARIABLE + 1 * sizeof (UINT8)) << 16);
  Data |= (MmioRead8 (Address + SMC_MMIO_DATA_VARIABLE + 2 * sizeof (UINT8)) << 8);
  Data |= (MmioRead8 (Address + SMC_MMIO_DATA_VARIABLE + 3 * sizeof (UINT8)));

  return Data;
}

// TimeoutWaitingForStatusFlagClearMmio
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
TimeoutWaitingForStatusFlagClearMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Flag,
  IN UINTN        Iterations
  )
{
  EFI_STATUS Status;

  SMC_STATUS SmcStatus;

  SmcStatus = (SMC_RESULT)SmcReadKeyStatusMmio ((UINTN)BaseAddress);

  while (TRUE) {
    Status = EFI_SUCCESS;

    if ((Flag & SmcStatus) == 0) {
      break;
    }

    Status = EFI_TIMEOUT;
    --Iterations;

    if (Iterations == 0) {
      break;
    }

    // sub_498 (100);
    SmcStatus = (SMC_RESULT)SmcReadKeyStatusMmio ((UINTN)BaseAddress);
  }

  return Status;
}

// TimeoutWaitingForStatusFlagSetMmio
EFI_STATUS
TimeoutWaitingForStatusFlagSetMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Flag,
  IN UINTN        Iterations
  )
{
  EFI_STATUS Status;

  SMC_STATUS SmcStatus;

  SmcStatus = (SMC_STATUS)SmcReadKeyStatusMmio ((UINTN)BaseAddress);

  while (TRUE) {
    Status = EFI_SUCCESS;

    if ((SmcStatus & Flag) != 0) {
      break;
    }

    Status = EFI_TIMEOUT;
    --Iterations;

    if (Iterations == 0) {
      break;
    }

    // sub_498 (100);
    SmcStatus = (SMC_STATUS)SmcReadKeyStatusMmio ((UINTN)BaseAddress);
  }

  return Status;
}

// sub_5FB
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
sub_5FB (
  IN SMC_ADDRESS  BaseAddress,
  IN UINTN        Ukn
  )
{
  EFI_STATUS Status;

  SMC_STATUS SmcStatus;
  UINT32     StatusMask;

  SmcStatus = (SMC_STATUS)SmcReadKeyStatusMmio ((UINTN)BaseAddress);

  if (SmcStatus >= SMC_STATUS_UKN_0x40) {
    SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdUnknown1);

    while ((SmcStatus & SMC_STATUS_KEY_DONE) == 0) {
      StatusMask = ((UINT32)SmcStatus & (SMC_STATUS_UKN_0x40 | SMC_STATUS_UKN_0x80));

      while (Ukn == 0) {
        Status = EFI_TIMEOUT;
        Ukn    = (UINT32)0;

        if (StatusMask != 0) {
          goto Return;
        }
      }

      // sub_498 (100);
      --Ukn;
      SmcStatus = (SMC_STATUS)SmcReadKeyStatusMmio ((UINTN)BaseAddress);
    }
  }

  SmcStatus = (SMC_STATUS)SmcReadKeyStatusMmio ((UINTN)BaseAddress);
  Status    = EFI_SUCCESS;

  if ((SmcStatus & SMC_STATUS_KEY_DONE) != 0) {
    SmcReadResultMmio ((UINTN)BaseAddress);
  }

Return:
  return Status;
}

// ClearArbitration
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
ClearArbitration (
  IN SMC_ADDRESS  BaseAddress
  )
{
  EFI_STATUS Status;

  Status = TimeoutWaitingForStatusFlagClearMmio (
             BaseAddress,
             (SMC_STATUS_UKN_0x16 | SMC_STATUS_KEY_DONE | SMC_STATUS_UKN_0x40 | SMC_STATUS_UKN_0x80),
             1000
             );

  if (EFI_ERROR (Status)) {
    sub_5FB (BaseAddress, 1000);

    if (!EFI_ERROR (Status)) {
      Status = TimeoutWaitingForStatusFlagClearMmio (
                 BaseAddress,
                 (SMC_STATUS_UKN_0x16 | SMC_STATUS_KEY_DONE | SMC_STATUS_UKN_0x40 | SMC_STATUS_UKN_0x80),
                 1000
                 );
    }
  }

  return Status;
}

// WaitForKeyDone
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
WaitForKeyDone (
  IN SMC_ADDRESS  BaseAddress
  )
{
  return TimeoutWaitingForStatusFlagSetMmio (BaseAddress, SMC_STATUS_KEY_DONE, 1000);
}

// WaitLongForKeyDone
/// 
///
/// @param 
///
/// @return 
/// @retval 
EFI_STATUS
WaitLongForKeyDone (
  IN SMC_ADDRESS  BaseAddress
  )
{
  return TimeoutWaitingForStatusFlagSetMmio (BaseAddress, SMC_STATUS_KEY_DONE, 100000);
}

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
  )
{
  EFI_STATUS    Status;

  SMC_RESULT    Result;
  SMC_DATA_SIZE KeySize;
  UINT8         Index;

  Status = ClearArbitration (BaseAddress);

  if (!EFI_ERROR (Status)) {
    SmcWriteData32Mmio (BaseAddress, (UINT32)Key);
    SmcWriteAttributesMmio ((UINTN)BaseAddress, 0);
    SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdReadValue);

    Status = WaitForKeyDone (BaseAddress);

    if (!EFI_ERROR (Status)) {
      Result = (SMC_RESULT)SmcReadResultMmio ((UINTN)BaseAddress);

      if (!SMCERR (Result)) {
        KeySize = SmcReadDataSizeMmio (BaseAddress);
        *Size   = KeySize;

        if ((KeySize > SMC_MAX_DATA_SIZE) || (KeySize <= 0)) {
          goto ReturnInvalidSize;
        }

        Index = 0;

        do {
          Value[Index] = SmcReadData8Mmio (BaseAddress + SMC_MMIO_DATA_VARIABLE + Index);
          ++Index;
        } while ((UINT32)Index < (UINT32)*Size);
      }
    }
  }

  if (Status == EFI_TIMEOUT) {
    Status = EFI_SMC_TIMEOUT_ERROR;
  } else if (Status == SMC_INVALID_SIZE) {
  ReturnInvalidSize:
    Status = EFI_SMC_INVALID_SIZE;
  } else {
    Status = EFI_STATUS_FROM_SMC_RESULT (Status);
  }

  return Status;
}

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
  )
{
  EFI_STATUS Status;

  UINTN      Index;
  SMC_RESULT Result;

  Status = EFI_INVALID_PARAMETER;

  if (((SMC_DATA_SIZE)Size > 0) && ((SMC_DATA_SIZE)Size <= SMC_MAX_DATA_SIZE) && (Value != NULL)) {
    Status = ClearArbitration (BaseAddress);
    Index  = 0;

    do {
      SmcWriteData8Mmio ((UINTN)BaseAddress, Value[Index]);

      ++Index;
    } while (Index < (SMC_DATA_SIZE)Size);

    SmcWriteData32Mmio (BaseAddress, (UINT32)Key);
    SmcWriteAttributesMmio (BaseAddress, 0);
    SmcWriteDataSizeMmio (BaseAddress, (UINT32)(SMC_DATA_SIZE)Size);
    SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdWriteValue);

    Status = WaitForKeyDone (BaseAddress);
    Result = (SMC_RESULT)SmcReadResultMmio ((UINTN)BaseAddress);
    Status = ((Status == EFI_TIMEOUT) ? EFI_SMC_TIMEOUT_ERROR : EFI_STATUS_FROM_SMC_RESULT (Result));
  }

  return Status;
}

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
  )
{
  EFI_STATUS Status;

  SMC_RESULT Result;

  Status = EFI_INVALID_PARAMETER;

  if (Index > 0) {
    Status = ClearArbitration (BaseAddress);

    if (!EFI_ERROR (Status)) {
      SmcWriteData32Mmio (BaseAddress, (UINT32)Index);
      SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdGetKeyFromIndex);
      
      Status = WaitForKeyDone (BaseAddress);

      if (!EFI_ERROR (Status)) {
        Result = (SMC_RESULT)SmcReadResultMmio ((UINTN)BaseAddress);

        if (!SMCERR (Result)) {
          *Key = (SMC_KEY)SmcReadData32Mmio ((UINTN)BaseAddress + SMC_MMIO_READ_KEY);
        }

        goto ReturnResult;
      }
    }

    Result = SMC_SUCCESS;

    if (Status == EFI_TIMEOUT) {
      Status = EFI_SMC_TIMEOUT_ERROR;
    } else {
    ReturnResult:
      Status = EFI_STATUS_FROM_SMC_RESULT (Result);
    }
  }

  return Status;
}

// SmcGetkeyInfoMmio
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
  )
{
  EFI_STATUS Status;

  SMC_RESULT Result;

  Status = EFI_INVALID_PARAMETER;

  if ((Size != NULL) && (Type != NULL) && (Attributes != NULL)) {
    Status = ClearArbitration (BaseAddress);

    if (!EFI_ERROR (Status)) {
      SmcWriteData32Mmio (BaseAddress, (UINT32)Key);
      SmcWriteCommandMmio (BaseAddress, SmcCmdGetKeyInfo);

      Status = WaitForKeyDone (BaseAddress);

      if (!EFI_ERROR (Status)) {
        Result = (SMC_RESULT)SmcReadResultMmio (BaseAddress);

        if (!SMCERR (Result)) {
          *Type       = (SMC_KEY_TYPE)SmcReadData32Mmio ((UINTN)(BaseAddress + SMC_MMIO_READ_KEY_TYPE));
          *Size       = (SMC_DATA_SIZE)SmcReadData8Mmio ((UINTN)(BaseAddress + SMC_MMIO_READ_DATA_SIZE));
          *Attributes = (SMC_KEY_ATTRIBUTES)SmcReadData8Mmio ((UINTN)(BaseAddress + SMC_MMIO_READ_KEY_ATTRIBUTES));
        }

        goto ReturnResult;
      }
    }

    Result = SMC_SUCCESS;

    if (Status == EFI_TIMEOUT) {
      Status = EFI_SMC_TIMEOUT_ERROR;
    } else {
    ReturnResult:
      Status = EFI_STATUS_FROM_SMC_RESULT (Result);
    }
  }

  return Status;
}

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
  )
{
  EFI_STATUS Status;

  SMC_RESULT Result;

  Status = ClearArbitration (BaseAddress);

  if (!EFI_ERROR (Status)) {
    SmcWriteData8Mmio ((UINTN)(BaseAddress + SMC_MMIO_DATA_VARIABLE), (SMC_DATA)Type);
    SmcWriteCommandMmio (BaseAddress, SmcCmdFlashType);
  }

  WaitForKeyDone (BaseAddress);

  Result = (SMC_RESULT)SmcReadResultMmio (BaseAddress);

  return ((Status == EFI_TIMEOUT) ? EFI_SMC_TIMEOUT_ERROR : EFI_STATUS_FROM_SMC_RESULT (Result));
}

// MmioWriteSwapped32
/// 
///
/// @param 
///
/// @return 
/// @retval 
UINT32
MmioWriteSwapped32 (
  IN UINTN   Address,
  IN UINT32  Value
  )
{
  return MmioWrite32 (Address, SwapBytes32 (Value));
}

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
  )
{
  EFI_STATUS Status;

  UINT32     Offset;
  UINT32     TotalSize;
  UINT32     BytesWritten;
  UINT32     SizeWritten;
  SMC_RESULT Result;
  UINT32     RemainingSize;
  UINT32     IterartionDataSize;

  Status = EFI_INVALID_PARAMETER;

  if (((SMC_FLASH_SIZE)Size > 0) && ((SMC_FLASH_SIZE)Size <= SMC_FLASH_SIZE_MAX) && (Data != NULL)) {
    Status = ClearArbitration (BaseAddress);

    if (!EFI_ERROR (Status)) {
      MmioWriteSwapped32 ((UINTN)BaseAddress, Unknown);
      MmioWrite8 (((UINTN)BaseAddress + sizeof (Unknown)), BYTE (Size, 1));
      MmioWrite8 (((UINTN)BaseAddress + sizeof (Unknown) + sizeof (SMC_FLASH_SIZE)), BYTE (Size, 0));

      Offset       = (sizeof (Unknown) + sizeof (Size));
      TotalSize    = (UINT32)(UINT16)(Size + sizeof (Unknown) + sizeof (Size));
      BytesWritten = 0;
      SizeWritten  = 0;
      Result       = SMC_SUCCESS;

      do {
        while (BytesWritten < Size) {
          RemainingSize      = (TotalSize - SizeWritten);
          IterartionDataSize = SMC_MAX_DATA_SIZE;

          if (RemainingSize < SMC_MAX_DATA_SIZE) {
            IterartionDataSize = RemainingSize;
          }

          while (Offset < IterartionDataSize) {
            if (((Offset + sizeof (UINT32)) <= IterartionDataSize)
             && ((UINT32)((UINT16)BytesWritten + sizeof (UINT32)) <= Size)) {
              MmioWrite32 ((UINTN)(BaseAddress + SMC_MMIO_DATA_VARIABLE + Offset), DWORD_PTR (Data, BytesWritten));

              BytesWritten = (UINT32)((UINT16)BytesWritten + sizeof (UINT32));
              Offset      += sizeof (UINT32);
            } else {
              MmioWrite8 ((UINTN)(BaseAddress + SMC_MMIO_DATA_VARIABLE + Offset), BYTE_PTR (Data, BytesWritten));

              BytesWritten += sizeof (UINT8);
              Offset       += sizeof (UINT8);
            }

            Offset = (UINT32)(UINT16)Offset;
          }

          SmcWriteDataSizeMmio (BaseAddress, IterartionDataSize);
          SmcWriteCommandMmio (
            (UINTN)BaseAddress,
            ((BytesWritten <= SMC_MAX_DATA_SIZE) ? SmcCmdFlashWrite : SmcCmdFlashWriteMoreData)
            );

          Status = WaitLongForKeyDone (BaseAddress);

          if (EFI_ERROR (Status)) {
            break;
          }

          Result = (SMC_RESULT)SmcReadResultMmio (BaseAddress);

          if (Result != SMC_SUCCESS) {
            goto ReturnResult;
          }

          SizeWritten += (UINT32)(UINT16)IterartionDataSize;
          Offset       = 0;
        }
      } while (TRUE);

      if (Status == EFI_TIMEOUT) {
        Status = EFI_SMC_TIMEOUT_ERROR;
      } else {
      ReturnResult:
        Status = EFI_STATUS_FROM_SMC_RESULT (Result);
      }
    }
  }

  return Status;
}

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
  )
{
  EFI_STATUS Status;

  UINT32     Offset;
  UINT32     TotalSize;
  UINT32     BytesWritten;
  UINT32     SizeWritten;
  SMC_RESULT Result;
  UINT32     RemainingSize;
  UINT32     IterartionDataSize;

  Status = EFI_INVALID_PARAMETER;

  if (((SMC_FLASH_SIZE)Size > 0) && ((SMC_FLASH_SIZE)Size <= SMC_FLASH_SIZE_MAX) && (Data != NULL)) {
    Status = ClearArbitration (BaseAddress);

    if (!EFI_ERROR (Status)) {
      MmioWrite8 ((UINTN)BaseAddress, BYTE (Size, 1));
      MmioWrite8 (((UINTN)BaseAddress + sizeof (SMC_FLASH_SIZE)), BYTE (Size, 0));

      Offset           = sizeof (Size);
      TotalSize        = (UINT32)(UINT16)(Size + sizeof (Size));
      BytesWritten     = 0;
      SizeWritten      = 0;
      Result           = SMC_SUCCESS;

      do {
        while (BytesWritten < Size) {
          RemainingSize      = (TotalSize - SizeWritten);
          IterartionDataSize = SMC_MAX_DATA_SIZE;

          if (RemainingSize < SMC_MAX_DATA_SIZE) {
            IterartionDataSize = RemainingSize;
          }

          while (Offset < IterartionDataSize) {
            if (((Offset + sizeof (UINT32)) <= IterartionDataSize)
             && ((UINT32)((UINT16)BytesWritten + sizeof (UINT32)) <= Size)) {
              MmioWrite32 ((UINTN)(BaseAddress + SMC_MMIO_DATA_VARIABLE + Offset), DWORD_PTR (Data, BytesWritten));

              BytesWritten = (UINT32)((UINT16)BytesWritten + sizeof (UINT32));
              Offset      += sizeof (UINT32);
            } else {
              MmioWrite8 ((UINTN)(BaseAddress + SMC_MMIO_DATA_VARIABLE + Offset), BYTE_PTR (Data, BytesWritten));

              BytesWritten += sizeof (UINT8);
              Offset       += sizeof (UINT8);
            }

            Offset = (UINT32)(UINT16)Offset;
          }

          SmcWriteDataSizeMmio (BaseAddress, IterartionDataSize);
          SmcWriteCommandMmio (
            (UINTN)BaseAddress,
            ((BytesWritten <= SMC_MAX_DATA_SIZE) ? SmcCmdFlashAuth : SmcCmdFlashAuthMoreData)
            );

          Status = WaitLongForKeyDone (BaseAddress);

          if (EFI_ERROR (Status)) {
            break;
          }

          Result = (SMC_RESULT)SmcReadResultMmio (BaseAddress);

          if (Result != SMC_SUCCESS) {
            goto ReturnResult;
          }

          SizeWritten += (UINT32)(UINT16)IterartionDataSize;
          Offset       = 0;
        }
      } while (TRUE);

      if (Status == EFI_TIMEOUT) {
        Status = EFI_SMC_TIMEOUT_ERROR;
      } else {
      ReturnResult:
        Status = EFI_STATUS_FROM_SMC_RESULT (Result);
      }
    }
  }

  return Status;
}

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
  )
{
  BOOLEAN       Mmio;

  SMC_DATA_SIZE Size;
  SMC_DATA      Value;
  EFI_STATUS    Status;

  Mmio = FALSE;

  if (SmcReadKeyStatusMmio ((UINTN)BaseAddress) != 0xFF) {
    Size   = sizeof (Value);
    Status = SmcReadValueMmio (BaseAddress, SMC_KEY_LDKN, &Size, &Value);

    if (!EFI_ERROR (Status)) {
      Mmio = (Value > 1);
    }
  }

  return Mmio;
}

EFI_STATUS
SmcResetMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Mode
  )
{
  SMC_RESULT Result;

  EFI_STATUS Status;
  BOOLEAN    Mmio;

  SmcReadKeyStatusMmio ((UINTN)BaseAddress);

  Status = ClearArbitration (BaseAddress);

  if (!EFI_ERROR (Status)) {
    SmcWriteData8Mmio ((UINTN)(BaseAddress + SMC_MMIO_DATA_VARIABLE), (SMC_DATA)Mode);
    SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdReset);
    WaitForKeyDone (BaseAddress);
  }

  Result = (SMC_RESULT)SmcReadResultMmio ((UINTN)BaseAddress);
  Mmio   = SmcMmioInterface (BaseAddress);

  return (Mmio ? EFI_STATUS_FROM_SMC_RESULT (Result) : EFI_SUCCESS);
}
