/** @file
  Copyright (C) 2005 - 2015, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_SMC_H_
#define APPLE_SMC_H_

// PMIO
/// @{
#define SMC_PORT_BASE            0x0300
#define SMC_PORT_LENGTH          0x0020

#define SMC_PORT_OFFSET_DATA     0x00
#define SMC_PORT_OFFSET_COMMAND  0x04
#define SMC_PORT_OFFSET_STATUS   SMC_PORT_OFFSET_COMMAND
#define SMC_PORT_OFFSET_RESULT   0x1E
#define	SMC_PORT_OFFSET_DEBUG    0x1F
/// @}

// MMIO
/// @{
#define	SMC_MMIO_BASE_ADDRESS  0xFEF00000
#define	SMC_MMIO_LENGTH        0x00010000

#define SMC_MMIO_DATA_VARIABLE  0x00
#define SMC_MMIO_DATA_FIXED     0x78

#define SMC_MMIO_OFFSET_KEY             0x00
#define SMC_MMIO_OFFSET_KEY_TYPE        SMC_MMIO_OFFSET_KEY
#define SMC_MMIO_OFFSET_SMC_MODE        SMC_MMIO_OFFSET_KEY
#define SMC_MMIO_OFFSET_DATA_SIZE       0x05
#define SMC_MMIO_OFFSET_KEY_ATTRIBUTES  0x06
#define SMC_MMIO_OFFSET_COMMAND         0x07
#define SMC_MMIO_OFFSET_RESULT          SMC_MMIO_OFFSET_COMMAND

#define SMC_MMIO_READ_KEY              (SMC_MMIO_DATA_VARIABLE + SMC_MMIO_OFFSET_KEY)
#define SMC_MMIO_READ_KEY_TYPE         (SMC_MMIO_DATA_VARIABLE + SMC_MMIO_OFFSET_KEY_TYPE)
#define SMC_MMIO_READ_DATA_SIZE        (SMC_MMIO_DATA_VARIABLE + SMC_MMIO_OFFSET_DATA_SIZE)
#define SMC_MMIO_READ_KEY_ATTRIBUTES   (SMC_MMIO_DATA_VARIABLE + SMC_MMIO_OFFSET_KEY_ATTRIBUTES)
#define SMC_MMIO_READ_RESULT           (SMC_MMIO_DATA_FIXED + SMC_MMIO_OFFSET_RESULT)
#define SMC_MMIO_READ_UNKNOWN1         0x4004
#define SMC_MMIO_READ_KEY_STATUS       0x4005

#define SMC_MMIO_WRITE_MODE            (SMC_MMIO_DATA_VARIABLE + SMC_MMIO_OFFSET_SMC_MODE)
#define SMC_MMIO_WRITE_KEY             (SMC_MMIO_DATA_FIXED + SMC_MMIO_OFFSET_KEY)
#define SMC_MMIO_WRITE_INDEX           (SMC_MMIO_DATA_FIXED + SMC_MMIO_OFFSET_KEY_TYPE)
#define SMC_MMIO_WRITE_DATA_SIZE       (SMC_MMIO_DATA_FIXED + SMC_MMIO_OFFSET_DATA_SIZE)
#define SMC_MMIO_WRITE_KEY_ATTRIBUTES  (SMC_MMIO_DATA_FIXED + SMC_MMIO_OFFSET_KEY_ATTRIBUTES)
#define SMC_MMIO_WRITE_COMMAND         (SMC_MMIO_DATA_FIXED + SMC_MMIO_OFFSET_COMMAND)
/// @}

typedef UINT32 SMC_ADDRESS;

// Modes
/// @{
#define SMC_MODE_APPCODE  'A'
#define SMC_MODE_UPDATE   'U'
#define SMC_MODE_BASE     'B'

// SMC_MODE
typedef CHAR8 *SMC_MODE;

enum {
  SmcResetModeMaster  = 0,
  SmcResetModeAppCode = 1,
  SmcResetModeUpdate  = 2,
  SmcResetModeBase    = 3
};

typedef UINT8 SMC_RESET_MODE;

enum {
  SmcFlashTypeAppCode = 1,
  SmcFlashTypeBase    = 2,
  SmcFlashTypeUpdate  = 3,
  SmcFlashTypeEpm     = 4
};

typedef UINT8 SMC_FLASH_TYPE;

enum {
  SmcFlashModeAppCode = SmcResetModeMaster,
  SmcFlashModeUpdate  = SmcResetModeBase,
  SmcFlashModeBase    = SmcResetModeUpdate,
  SmcFlashModeEpm     = SmcResetModeMaster
};

typedef UINT8 SMC_FLASH_MODE;
/// @}

// Commands
/// @{
enum {
  SmcCmdReadValue            = 0x10,
  SmcCmdWriteValue           = 0x11,
  SmcCmdGetKeyFromIndex      = 0x12,
  SmcCmdGetKeyInfo           = 0x13,
  SmcCmdReset                = 0x14,
  SmcCmdAttributedWriteValue = 0x15,
  SmcCmdAttributedReadValue  = 0x16,
  SmcCmdUnknown1             = 0x77,
  SmcCmdFlashWrite           = 0xF1,
  SmcCmdFlashAuth            = 0xF2,
  SmcCmdFlashType            = 0xF4,
  SmcCmdFlashWriteMoreData   = 0xF5, // write more data than the 0x78 data available
  SmcCmdFlashAuthMoreData    = 0xF6  // write more data than the 0x78 data available
};

typedef UINT8 SMC_COMMAND;
/// @}

// Reports
/// @{
#define SMC_STATUS_AWAITING_MORE_BYTES  BIT (0)
#define SMC_STATUS_IB_CLOSED            BIT (1)
#define SMC_STATUS_BUSY                 BIT (2)
#define SMC_STATUS_COMMAND_RECEIVED     BIT (3)
#define SMC_STATUS_UKN_0x16             BIT (4)
#define SMC_STATUS_KEY_DONE             BIT (5)
#define SMC_STATUS_UKN_0x40             BIT (6)  // error
#define SMC_STATUS_UKN_0x80             BIT (7)  // error

// SMC_STATUS
typedef UINT8 SMC_STATUS;

#define SMC_SUCCESS                 0
#define SMC_ERROR                   1

#define SMC_COMM_COLLISION          128
#define SMC_SPURIOUS_DATA           129
#define SMC_BAD_COMMAND             130
#define SMC_BAD_PARAMETER           131
#define SMC_KEY_NOT_FOUND           132
#define SMC_KEY_NOT_READABLE        133
#define SMC_KEY_NOT_WRITABLE        134
#define SMC_KEY_SIZE_MISMATCH       135
#define SMC_FRAMING_ERROR           136
#define SMC_BAD_ARGUMENT_ERROR      137

#define SMC_TIMEOUT_ERROR           183
#define SMC_KEY_INDEX_RANGE_ERROR   184

#define SMC_BAD_FUNC_PARAMETER      192
#define SMC_EVENT_BUFF_WRONG_ORDER  196
#define SMC_EVENT_BUFF_READ_ERROR   197
#define SMC_DEVICE_ACCESS_ERROR     199
#define SMC_UNSUPPORTED_FEATURE     203
#define SMC_SMB_ACCESS_ERROR        204

#define SMC_INVALID_SIZE  206

#define SMCERR(a)                     (((UINTN)(a)) > 0)
#define EFI_STATUS_FROM_SMC_RESULT(x) ((((UINTN)(x)) == SMC_SUCCESS) ? EFI_SUCCESS : EFIERR ((UINTN)(x)))

#define EFI_SMC_SUCCESS                 SMC_SUCCESS
#define EFI_SMC_ERROR                   EFIERR (SMC_ERROR)

#define EFI_SMC_COMM_COLLISION          EFIERR (SMC_COMM_COLLISION)
#define EFI_SMC_SPURIOUS_DATA           EFIERR (SMC_SPURIOUS_DATA)
#define EFI_SMC_BAD_COMMAND             EFIERR (SMC_BAD_COMMAND)
#define EFI_SMC_BAD_PARAMETER           EFIERR (SMC_BAD_PARAMETER)
#define EFI_SMC_KEY_NOT_FOUND           EFIERR (SMC_KEY_NOT_FOUND)
#define EFI_SMC_KEY_NOT_READABLE        EFIERR (SMC_KEY_NOT_READABLE)
#define EFI_SMC_KEY_NOT_WRITABLE        EFIERR (SMC_KEY_NOT_WRITABLE)
#define EFI_SMC_KEY_SIZE_MISMATCH       EFIERR (SMC_KEY_SIZE_MISMATCH)
#define EFI_SMC_FRAMING_ERROR           EFIERR (SMC_FRAMING_ERROR)
#define EFI_SMC_BAD_ARGUMENT_ERROR      EFIERR (SMC_BAD_ARGUMENT_ERROR)

#define EFI_SMC_TIMEOUT_ERROR           EFIERR (SMC_TIMEOUT_ERROR)
#define EFI_SMC_KEY_INDEX_RANGE_ERROR   EFIERR (SMC_KEY_INDEX_RANGE_ERROR)

#define EFI_SMC_BAD_FUNC_PARAMETER      EFIERR (SMC_BAD_FUNC_PARAMETER)
#define EFI_SMC_EVENT_BUFF_WRONG_ORDER  EFIERR (SMC_EVENT_BUFF_WRONG_ORDER)
#define EFI_SMC_EVENT_BUFF_READ_ERROR   EFIERR (SMC_EVENT_BUFF_READ_ERROR)
#define EFI_SMC_DEVICE_ACCESS_ERROR     EFIERR (SMC_DEVICE_ACCESS_ERROR)
#define EFI_SMC_UNSUPPORTED_FEATURE     EFIERR (SMC_UNSUPPORTED_FEATURE)
#define EFI_SMC_SMB_ACCESS_ERROR        EFIERR (SMC_SMB_ACCESS_ERROR)

#define EFI_SMC_INVALID_SIZE  EFIERR (SMC_INVALID_SIZE)

// SMC_RESULT
typedef UINT8 SMC_RESULT;
/// @}

// Key Types
/// @{
#define SMC_KEY_TYPE_FP1F      "fp1f"
#define SMC_KEY_TYPE_FP4C      "fp4c"
#define SMC_KEY_TYPE_FP5B      "fp5b"
#define SMC_KEY_TYPE_FP6A      "fp6a"
#define SMC_KEY_TYPE_FP79      "fp79"
#define SMC_KEY_TYPE_FP88      "fp88"
#define SMC_KEY_TYPE_FPA6      "fpa6"
#define SMC_KEY_TYPE_FPC4      "fpc4"
#define SMC_KEY_TYPE_FPE2      "fpe2"

#define SMC_KEY_TYPE_SP1E      "sp1e"
#define SMC_KEY_TYPE_SP3C      "sp3c"
#define SMC_KEY_TYPE_SP4B      "sp4b"
#define SMC_KEY_TYPE_SP5A      "sp5a"
#define SMC_KEY_TYPE_SP69      "sp69"
#define SMC_KEY_TYPE_SP78      "sp78"
#define SMC_KEY_TYPE_SP87      "sp87"
#define SMC_KEY_TYPE_SP96      "sp96"
#define SMC_KEY_TYPE_SPB4      "spb4"
#define SMC_KEY_TYPE_SPF0      "spf0"

#define SMC_KEY_TYPE_UINT8     "ui8 "
#define SMC_KEY_TYPE_UINT16    "ui16"
#define SMC_KEY_TYPE_UINT32    "ui32"

#define SMC_KEY_TYPE_SI8       "si8 "
#define SMC_KEY_TYPE_SI16      "si16"

#define SMC_KEY_TYPE_FLAG      "flag"
#define SMC_KEY_TYPE_CHARSTAR  "ch8*"
#define SMC_KEY_TYPE_PWM       "{pwm"

// SMC_KEY_TYPE
typedef UINT32 SMC_KEY_TYPE;
/// @}

// Key Attributes
/// @{
#define	SMC_KEY_ATTRIBUTE_PRIVATE   BIT (0)
#define	SMC_KEY_ATTRIBUTE_UKN_0x02  BIT (1)
#define	SMC_KEY_ATTRIBUTE_UKN_0x04  BIT (2)
#define	SMC_KEY_ATTRIBUTE_CONST     BIT (3)
#define	SMC_KEY_ATTRIBUTE_FUNCTION  BIT (4)
#define	SMC_KEY_ATTRIBUTE_UKN_0x20  BIT (5)
#define	SMC_KEY_ATTRIBUTE_WRITE     BIT (6)
#define	SMC_KEY_ATTRIBUTE_READ      BIT (7)

// SMC_KEY_ATTRIBUTES
typedef UINT8 SMC_KEY_ATTRIBUTES;
/// @}

// Data
/// @{
#define SMC_MAX_DATA_SIZE  (SMC_MMIO_DATA_FIXED - SMC_MMIO_DATA_VARIABLE)

typedef UINT8 SMC_DATA;
typedef UINT8 SMC_DATA_SIZE;
/// @}

// Keys
/// @{
// SMC_KEY_IS_VALID_CHAR
#define SMC_KEY_IS_VALID_CHAR(x) (((x) >= 0x20) && ((x) <= 0x7E))

// SMC_MAKE_KEY
#define SMC_MAKE_KEY(A, B, C, D) (((A) << 24) | ((B) << 16) | ((C) << 8) | (D))

#define SMC_KEY_NUM      SMC_MAKE_KEY ('$', 'N', 'u', 'm')
#define SMC_KEY_ADR      SMC_MAKE_KEY ('$', 'A', 'd', 'r')
#define SMC_KEY_NO_KEYS  SMC_MAKE_KEY ('#', 'K', 'e', 'y')
#define SMC_KEY_LDKN     SMC_MAKE_KEY ('L', 'D', 'K', 'N')

typedef UINT32 SMC_KEY;
typedef UINT32 SMC_INDEX;
/// @}

// Flash data
/// @{
// SMC_FLASH_SIZE_MAX
#define SMC_FLASH_SIZE_MAX  0x0800

// SMC_FLASH_SIZE
typedef UINT16 SMC_FLASH_SIZE;
/// @}

#endif // APPLE_SMC_H_
