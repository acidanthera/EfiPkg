//********************************************************************
//	created:	28:8:2012   18:10
//	filename: 	AppleDeviceControl.h
//	author:		tiamo
//	purpose:	apple device control
//********************************************************************

#ifndef _APPLE_DEVICE_CONTROL_H_
#define _APPLE_DEVICE_CONTROL_H_

// APPLE_DEVICE_CONTROL_PROTOCOL_GUID
#define APPLE_DEVICE_CONTROL_PROTOCOL_GUID \
  { 0x8ECE08D8, 0xA6D4, 0x430B, { 0xA7, 0xB0, 0x2D, 0xF3, 0x18, 0xE7, 0x88, 0x4A } }

// CONNECT_ALL
typedef
EFI_STATUS
(EFIAPI *CONNECT_DISPLAY)(
  VOID
  );

// CONNECT_ALL
typedef
EFI_STATUS
(EFIAPI *CONNECT_ALL)(
  VOID
  );

// _APPLE_DEVICE_CONTROL_PROTOCOL
typedef struct _APPLE_DEVICE_CONTROL_PROTOCOL {
  UINTN           Unknown0;
  CONNECT_DISPLAY ConnectDisplay;
  UINTN           Unknown2;
  CONNECT_ALL     ConnectAll;
} APPLE_DEVICE_CONTROL_PROTOCOL;

// gAppleDeviceControlProtocolGuid
extern EFI_GUID gAppleDeviceControlProtocolGuid;

#endif // ifndef _APPLE_DEVICE_CONTROL_H_

//********************************************************************
//	created:	28:8:2012   18:15
//	filename: 	AppleDeviceControl.h
//	author:		tiamo
//	purpose:	graph config
//********************************************************************

#ifndef _APPLE_DEVICE_CONTROL_H_
#define _APPLE_DEVICE_CONTROL_H_

// APPLE_DEVICE_CONTROL_PROTOCOL_GUID
#define APPLE_DEVICE_CONTROL_PROTOCOL_GUID \
  { 0x8ECE08D8, 0xA6D4, 0x430B, { 0xA7, 0xB0, 0x2D, 0xF3, 0x18, 0xE7, 0x88, 0x4A } }

typedef struct _APPLE_DEVICE_CONTROL_PROTOCOL APPLE_DEVICE_CONTROL_PROTOCOL;

// RESTORE_CONFIG
typedef
EFI_STATUS
(EFIAPI *RESTORE_CONFIG)(
  APPLE_DEVICE_CONTROL_PROTOCOL *This,
  UINT32                            Param1,
  UINT32                            Param2,
  VOID                              *Param3,
  VOID                              *Param4,
  VOID                              *Param5
  );

// _APPLE_DEVICE_CONTROL_PROTOCOL
struct _APPLE_DEVICE_CONTROL_PROTOCOL {
  UINTN          Unknown0;
  RESTORE_CONFIG RestoreConfig;
};

// gAppleDeviceControlProtocolGuid
extern EFI_GUID gAppleDeviceControlProtocolGuid;

#endif // ifndef _APPLE_DEVICE_CONTROL_H_
