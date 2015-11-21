#ifndef _APPLE_SMC_IO_H_
#define _APPLE_SMC_IO_H_

#include <IndustryStandard/AppleSmc.h>

// APPLE_SMC_IO_PROTOCOL_GUID
#define APPLE_SMC_IO_PROTOCOL_GUID \
  { 0x17407E5A, 0xAF6C, 0x4EE8, { 0x98, 0xA8, 0x00, 0x21, 0x04, 0x53, 0xCD, 0xD9 } }

FORWARD_DECLARATION (APPLE_SMC_IO_PROTOCOL);

// SMC_READ_VALUE
typedef
EFI_STATUS
(EFIAPI *SMC_READ_VALUE)(
  IN  APPLE_SMC_IO_PROTOCOL  *This,
  IN  SMC_KEY                Key,
  IN  SMC_DATA_SIZE          Size,
  OUT VOID                   *Value
  );

// SMC_WRITE_VALUE
typedef
EFI_STATUS
(EFIAPI *SMC_WRITE_VALUE)(
  IN  APPLE_SMC_IO_PROTOCOL  *This,
  IN  SMC_KEY                Key,
  IN  SMC_DATA_SIZE          Size,
  OUT VOID                   *Value
  );

// SMC_GET_KEY_COUNT
typedef
EFI_STATUS
(EFIAPI *SMC_GET_KEY_COUNT)(
  IN  APPLE_SMC_IO_PROTOCOL  *This,
  OUT UINT32                 *Count
  );

// SMC_MAKE_KEY
typedef
EFI_STATUS
(EFIAPI *SMC_MAKE_KEY)(
  IN  CHAR8    *Name,
  OUT SMC_KEY  *Key
  );

// SMC_GET_KEY_FROM_INDEX
typedef
EFI_STATUS
(EFIAPI *SMC_GET_KEY_FROM_INDEX)(
  IN  APPLE_SMC_IO_PROTOCOL  *This,
  IN  SMC_INDEX              Index,
  OUT SMC_KEY                *Key
  );

// SMC_GET_KEY_INFO
typedef
EFI_STATUS
(EFIAPI *SMC_GET_KEY_INFO)(
  IN     APPLE_SMC_IO_PROTOCOL  *This,
  IN     SMC_KEY                Key,
  IN OUT SMC_DATA_SIZE          *Size,
  IN OUT SMC_KEY_TYPE           *Type,
  IN OUT SMC_KEY_ATTRIBUTES     *Attributes
  );

typedef
EFI_STATUS
(EFIAPI *SMC_RESET)(
  IN APPLE_SMC_IO_PROTOCOL  *This,
  IN SMC_RESET_MODE         Mode
  );

typedef
EFI_STATUS
(EFIAPI *SMC_FLASH_TYPE)(
  IN APPLE_SMC_IO_PROTOCOL  *This,
  IN UINT32                 Type
  );

typedef
EFI_STATUS
(EFIAPI *SMC_FLASH_WRITE)(
  IN APPLE_SMC_IO_PROTOCOL  *This,
  IN UINT32                 Unknown,
  IN UINT16                 Size,
  IN SMC_DATA               *Data
  );

typedef
EFI_STATUS
(EFIAPI *SMC_FLASH_AUTH)(
  IN APPLE_SMC_IO_PROTOCOL  *This,
  IN UINT16                 Size,
  IN SMC_DATA               *Data
  );

typedef
EFI_STATUS
(EFIAPI *SMC_UNSUPPORTED)(
  VOID
  );

// _APPLE_SMC_IO_PROTOCOL
struct _APPLE_SMC_IO_PROTOCOL {
  UINT64                 Revision;
  SMC_READ_VALUE         SmcReadValue;
  SMC_WRITE_VALUE        SmcWriteValue;
  SMC_GET_KEY_COUNT      SmcGetKeyCount;
  SMC_MAKE_KEY           SmcMakeKey;
  SMC_GET_KEY_FROM_INDEX SmcGetKeyFromIndex;
  SMC_GET_KEY_INFO       SmcGetKeyInfo;
  SMC_RESET              SmcReset;
  SMC_FLASH_TYPE         SmcFlashType;
  SMC_UNSUPPORTED        SmcUnsupported;
  SMC_FLASH_WRITE        SmcFlashWrite;
  SMC_FLASH_AUTH         SmcFlashAuth;
  SMC_INDEX              Index;
  SMC_ADDRESS            Address;
  BOOLEAN                Mmio;
  UINTN                  Functions[5];
};

// gAppleSmcIoProtocolGuid
extern EFI_GUID gAppleSmcIoProtocolGuid;

#endif // ifndef _APPLE_SMC_IO_H_
