//********************************************************************
//	created:	29:9:2012   13:49
//	filename: 	AppleSMC.h
//	author:		tiamo
//	purpose:	apple smc
//********************************************************************

#ifndef _APPLE_SMC_IO_H_
#define _APPLE_SMC_IO_H_

// APPLE_SMC_PROTOCOL_GUID
#define APPLE_SMC_IO_PROTOCOL_GUID \
  { 0x17407E5A, 0xAF6C, 0x4EE8, { 0x98, 0xA8, 0x00, 0x21, 0x04, 0x53, 0xCD, 0xD9 } }

FORWARD_DECLARATION (APPLE_SMC_IO_PROTOCOL);

// APPLE_SMC_READ_DATA
typedef
EFI_STATUS
(EFIAPI *SMC_READ_VALUE)(
  IN  APPLE_SMC_IO_PROTOCOL  *This,
  IN  UINT32                 DataId,
  IN  UINT32                 DataLength,
  OUT VOID                   *DataBuffer
  );

// _APPLE_SMC_IO_PROTOCOL
struct _APPLE_SMC_IO_PROTOCOL {
  UINT64         Revision;
  SMC_READ_VALUE SmcReadValue;
};

// gAppleSmcIoProtocolGuid
extern EFI_GUID gAppleSmcIoProtocolGuid;

#endif // ifndef _APPLE_SMC_IO_H_
