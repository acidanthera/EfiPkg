#ifndef _APPLE_BOOT_BEEP_GEN_H_
#define _APPLE_BOOT_BEEP_GEN_H_

// APPLE_BOOT_BEEP_GEN_PROTOCOL_GUID
#define APPLE_BOOT_BEEP_GEN_PROTOCOL_GUID \
  { 0xC32332DF, 0xFC56, 0x4FE1, { 0x93, 0x58, 0xBA, 0x0D, 0x52, 0x9B, 0x24, 0xCD } }

// APPLE_BEEP_GEN_BEEP
typedef
EFI_STATUS
(EFIAPI *APPLE_BEEP_GEN_BEEP)(
  IN UINTN  NoProtocolCallsStalls,
  IN UINTN  StallMicrosecs1, 
  IN UINTN  StallMicrosecs2
  );

// _APPLE_BOOT_BEEP_GEN_PROTOCOL
typedef struct _APPLE_BOOT_BEEP_GEN_PROTOCOL {
  APPLE_BEEP_GEN_BEEP AppleBeepGenBeep;  ///< Pointer to the function generating the boot beep.
} APPLE_BOOT_BEEP_GEN_PROTOCOL;

// gAppleBootBeepGenProtocolGuid
extern EFI_GUID gAppleBootBeepGenProtocolGuid;

#endif // ifndef _APPLE_BOOT_BEEP_GEN_H_
