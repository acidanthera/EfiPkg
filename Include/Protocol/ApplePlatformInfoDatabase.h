#ifndef __APPLE_PLATFORM_INFO_DATABASE_H__
#define __APPLE_PLATFORM_INFO_DATABASE_H__

// APPLE_PLATFORM_INFO_DATABASE_PROTOCOL_GUID
#define APPLE_PLATFORM_INFO_DATABASE_PROTOCOL_GUID \
  { 0xAC5E4829, 0xA8FD, 0x440B, { 0xAF, 0x33, 0x9F, 0xFE, 0x01, 0x3B, 0x12, 0xD8 } }

FORWARD_DECLARATION (APPLE_PLATFORM_INFO_DATABASE_PROTOCOL);

// GET_FIRST_PLATFORM_INFO_DATA
typedef
EFI_STATUS
(EFIAPI *GET_FIRST_PLATFORM_INFO_DATA)(
  IN     APPLE_PLATFORM_INFO_DATABASE_PROTOCOL  *This,
  IN     EFI_GUID                               *NameGuid,
  IN OUT VOID                                   *Data,
  IN OUT UINTN                                  *Size
  );

// GET_FIRST_PLATFORM_INFO_DATA_SIZE
typedef
EFI_STATUS
(EFIAPI *GET_FIRST_PLATFORM_INFO_DATA_SIZE)(
  IN     APPLE_PLATFORM_INFO_DATABASE_PROTOCOL  *This,
  IN     EFI_GUID                               *NameGuid,
  IN OUT UINTN                                  *Size
  );

// GET_PLATFORM_INFO_DATA
typedef
EFI_STATUS
(EFIAPI *GET_PLATFORM_INFO_DATA)(
  IN     APPLE_PLATFORM_INFO_DATABASE_PROTOCOL  *This,
  IN     EFI_GUID                               *NameGuid,
  IN     UINTN                                  Index,
  IN OUT VOID                                   *Data,
  IN OUT UINTN                                  *Size
  );

// GET_PLATFORM_INFO_DATA_SIZE
typedef
EFI_STATUS
(EFIAPI *GET_PLATFORM_INFO_DATA_SIZE)(
  IN     APPLE_PLATFORM_INFO_DATABASE_PROTOCOL  *This,
  IN     EFI_GUID                               *NameGuid,
  IN     UINTN                                  XorValue,
  IN OUT UINTN                                  *Size
  );

// _APPLE_PLATFORM_INFO_DATABASE_PROTOCOL
struct _APPLE_PLATFORM_INFO_DATABASE_PROTOCOL {
  UINTN                             Revision;                      ///<
  GET_FIRST_PLATFORM_INFO_DATA      GetFirstPlatformInfoData;      ///<
  GET_FIRST_PLATFORM_INFO_DATA_SIZE GetFirstPlatformInfoDataSize;  ///<
  GET_PLATFORM_INFO_DATA            GetPlatformInfoData;           ///<
  GET_PLATFORM_INFO_DATA_SIZE       GetPlatformInfoDataSize;       ///<
};

// gApplePlatformInfoDatabaseProtocolGuid
extern EFI_GUID gApplePlatformInfoDatabaseProtocolGuid;

#endif // ifndef __APPLE_PLATFORM_INFO_DATABASE_H__
