//********************************************************************
//	created:	26:8:2012   17:08
//	filename: 	AppleFirmwarePassword.h
//	author:		tiamo
//	purpose:	apple firmware password
//********************************************************************

#ifndef __APPLE_FIRMWARE_PASSWORD_H__
#define __APPLE_FIRMWARE_PASSWORD_H__

// APPLE_FIRMWARE_PASSWORD_PROTOCOL_GUID
#define APPLE_FIRMWARE_PASSWORD_PROTOCOL_GUID \
  { 0x8FFEEB3A, 0x4C98, 0x4630, { 0x80, 0x3F, 0x74, 0x0F, 0x95, 0x67, 0x09, 0x1D } }

FORWARD_DECLARATION (APPLE_FIRMWARE_PASSWORD_PROTOCOL);

// CHECK
typedef
EFI_STATUS
(EFIAPI *CHECK)(
  IN  APPLE_FIRMWARE_PASSWORD_PROTOCOL  *This,
  OUT UINTN                             *CheckValue
  );

// _APPLE_FIRMWARE_PASSWORD_PROTOCOL
struct _APPLE_FIRMWARE_PASSWORD_PROTOCOL {
  UINT64 Revision;
  UINTN  Unknown[3];
  CHECK  Check;
};

// gAppleFirmwarePasswordProtocolGuid
extern EFI_GUID gAppleFirmwarePasswordProtocolGuid;

#endif // ifndef __APPLE_FIRMWARE_PASSWORD_H__
