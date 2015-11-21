// 31/10/2015

#include <AppleEfi.h>

#include <IndustryStandard/AppleSmc.h>

#include <Library/EdkIIGlueBaseLib.h>
#include <Library/EdkIIGlueIoLib.h>

SMC_STATUS
SmcReadKeyStatusMmio (
  IN UINTN  BaseAddress
  )
{
  return (SMC_STATUS)MmioRead8 ((UINTN)(BaseAddress + SMC_MMIO_READ_KEY_STATUS));
}

SMC_RESULT
SmcReadResultMmio (
  IN UINTN  BaseAddress
  )
{
  return (SMC_RESULT)MmioRead8 ((UINTN)(BaseAddress + SMC_MMIO_READ_RESULT));
}

UINT8
SmcWriteCommandMmio (
  IN UINTN        BaseAddress,
  IN SMC_COMMAND  Command
  )
{
  return MmioWrite8 ((UINTN)(BaseAddress + SMC_MMIO_WRITE_COMMAND), (UINT8)Command);
}

UINT8
SmcWriteAttributesMmio (
  IN UINTN               BaseAddress,
  IN SMC_KEY_ATTRIBUTES  Attributes
  )
{
  return MmioWrite8 ((UINTN)(BaseAddress + SMC_MMIO_WRITE_KEY_ATTRIBUTES), (UINT8)Attributes);
}

SMC_DATA_SIZE
SmcReadKeySizeMmio (
  IN SMC_ADDRESS  BaseAddress
  )
{
  return (SMC_DATA_SIZE)MmioRead8 ((UINTN)(BaseAddress + SMC_MMIO_READ_KEY_SIZE));
}

UINT8
SmcWriteKeySizeMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN SMC_DATA_SIZE      Size
  )
{
  return MmioWrite8 ((UINTN)(BaseAddress + SMC_MMIO_WRITE_KEY_SIZE), (UINT8)Size);
}

SMC_DATA
SmcReadData8Mmio (
  IN SMC_ADDRESS  Address
  )
{
  return (SMC_DATA)MmioRead8 ((UINTN)Address);
}

UINT8
SmcWriteData8Mmio (
  IN UINTN     Address,
  IN SMC_DATA  Data
  )
{
  return MmioWrite8 ((UINTN)Address, (UINT8)Data);
}

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

UINT32
SmcReadData32Mmio (
  IN UINTN  Address
  )
{
  UINT32 Data;

  Data  = (MmioRead8 (Address) << 24);
  Data |= (MmioRead8 (Address + 1 * sizeof (UINT8)) << 16);
  Data |= (MmioRead8 (Address + 2 * sizeof (UINT8)) << 8);
  Data |= MmioRead8 (Address + 3 * sizeof (UINT8));

  return Data;
}

EFI_STATUS
ClearArbitration (
  IN SMC_ADDRESS  BaseAddress
  )
{

}

EFI_STATUS
WaitForKeyDone (
  IN SMC_ADDRESS  BaseAddress
  )
{

}

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
      Result = SmcReadResultMmio ((UINTN)BaseAddress);

      if (!SMC_ERROR (Result)) {
        KeySize = SmcReadKeySizeMmio (BaseAddress);
        *Size   = KeySize;

        if ((KeySize > SMC_MAX_DATA_SIZE) || (KeySize == 0)) {
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

EFI_STATUS
SmcWriteValueMmio (
  IN SMC_ADDRESS    BaseAddress,
  IN SMC_KEY        Key,
  IN SMC_DATA_SIZE  Size,
  IN SMC_DATA       *Value
  )
{
  EFI_STATUS Status;

  UINTN      Index;
  SMC_RESULT Result;

  Status = EFI_INVALID_PARAMETER;

  if ((Size != 0) && (Size <= SMC_MAX_DATA_SIZE) && (Value != NULL)) {
    Status = ClearArbitration (BaseAddress);
    Index  = 0;

    do {
      SmcWriteData8Mmio ((UINTN)BaseAddress, Value[Index]);

      ++Index;
    } while (Index < Size);

    SmcWriteData32Mmio (BaseAddress, (UINT32)Key);
    SmcWriteAttributesMmio (BaseAddress, 0);
    SmcWriteKeySizeMmio (BaseAddress, Size);
    SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdWriteValue);

    Status = WaitForKeyDone (BaseAddress);
    Result = SmcReadResultMmio ((UINTN)BaseAddress);
    Status = ((Status == EFI_TIMEOUT) ? EFI_SMC_TIMEOUT_ERROR : EFI_STATUS_FROM_SMC_RESULT (Result));
  }

  return Status;
}

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

  if (Index != 0) {
    Status = ClearArbitration (BaseAddress);

    if (!EFI_ERROR (Status)) {
      SmcWriteData32Mmio (BaseAddress, (UINT32)Index);
      SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdGetKeyFromIndex);
      
      Status = WaitForKeyDone (BaseAddress);

      if (!EFI_ERROR (Status)) {
        Result = SmcReadResultMmio ((UINTN)BaseAddress);

        if (!SMC_ERROR (Result)) {
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
        Result = SmcReadResultMmio (BaseAddress);

        if (!SMC_ERROR (Result)) {
          *Type       = (SMC_KEY_TYPE)SmcReadData32Mmio ((UINTN)(BaseAddress + SMC_MMIO_READ_KEY_TYPE));
          *Size       = (SMC_DATA_SIZE)SmcReadData8Mmio ((UINTN)(BaseAddress + SMC_MMIO_READ_KEY_SIZE));
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

  Result = SmcReadResultMmio (BaseAddress);

  return ((Status == EFI_TIMEOUT) ? EFI_SMC_TIMEOUT_ERROR : EFI_STATUS_FROM_SMC_RESULT (Result));
}

UINT32
MmioWriteSwapped32 (
  IN UINTN   Address,
  IN UINT32  Value
  )
{
  return MmioWrite32 (Address, SwapBytes32 (Value));
}

EFI_STATUS
SmcFlashWriteMmio (
  IN SMC_ADDRESS  BaseAddress,
  IN UINT32       Unknown,
  IN UINT32       Size,
  IN SMC_DATA     *Data
  )
{
  EFI_STATUS Status;

  UINT32     TotalSize;
  UINT32     SizeWritten;
  UINT32     RemainingSize;
  UINT32     Offset;
  UINT32     TotalSizeWritten;

  Status = EFI_INVALID_PARAMETER;

  if (((UINT16)Size != 0) && ((UINT16)Size <= 0x800) && (Data != NULL)) {
    Status = ClearArbitration (BaseAddress);

    if (!EFI_ERROR (Status)) {
      MmioWriteSwapped32 ((UINTN)BaseAddress, Unknown);
      MmioWrite8 (((UINTN)BaseAddress + sizeof (Unknown)), ((UINT8 *)&(UINT16)Size)[1]); // macros?
      MmioWrite8 (((UINTN)BaseAddress + sizeof (Unknown) + sizeof (UINT8)), ((UINT8 *)&(UINT16)Size)[0]);

      TotalSize        = (UINTN)(Size + sizeof (Unknown) + sizeof (Size));
      SizeWritten      = 0;
      TotalSizeWritten = 0;
      Offset           = (sizeof (Unknown) + sizeof (Size));

      do {
        RemainingSize = (TotalSize - SizeWritten);

        if (RemainingSize > SMC_MAX_DATA_SIZE) {
          RemainingSize = SMC_MAX_DATA_SIZE;
        }

        for (; Offset < RemainingSize; Offset = (UINT32)(UINT16)Offset) {
          if (((Offset + sizeof (UINT32)) <= RemainingSize) && ((TotalSizeWritten + sizeof (UINT32)) <= Size)) {
            MmioWrite32 ((BaseAddress + SMC_MMIO_DATA_VARIABLE + Offset), Data[]);
          } else {
            
          }
        }
      } while (TRUE); // muh
    }
  }

  return Status;
}

EFI_STATUS
SmcFlashAuthMmio (
  IN SMC_ADDRESS  BaseAddress
  )
{
  EFI_STATUS Status;

  Status = EFI_INVALID_PARAMETER;

  //if ()

  return Status;
}

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
    Status = SmcReadValueMmio (BaseAddress, 'LDKN', &Size, &Value);

    if (!EFI_ERROR (Status)) {
      Mmio = (Value > 1);
    }
  }

  return Mmio;
}

EFI_STATUS
SmcResetMmio (
  IN SMC_ADDRESS     BaseAddress,
  IN SMC_RESET_MODE  Mode
  )
{
  EFI_STATUS Status;
  SMC_RESULT Result;
  BOOLEAN    Mmio;

  SmcReadKeyStatusMmio ((UINTN)BaseAddress);

  Status = ClearArbitration (BaseAddress);

  if (!EFI_ERROR (Status)) {
    SmcWriteData8Mmio ((UINTN)(BaseAddress + SMC_MMIO_DATA_VARIABLE), (SMC_DATA)Mode);
    SmcWriteCommandMmio ((UINTN)BaseAddress, SmcCmdReset);
    WaitForKeyDone (BaseAddress);
  }

  Result = SmcReadResultMmio ((UINTN)BaseAddress);
  Mmio   = SmcMmioInterface (BaseAddress);

  return (Mmio ? EFI_STATUS_FROM_SMC_RESULT (Result) : EFI_SUCCESS);
}
