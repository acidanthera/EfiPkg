#ifndef _APPLE_SYSTEM_INFO_H_
#define _APPLE_SYSTEM_INFO_H_

// APPLE_SYSTEM_INFO_PRODUCER_NAME_GUID
#define APPLE_SYSTEM_INFO_PRODUCER_NAME_GUID \
  { 0x64517CC8, 0x6561, 0x4051, { 0xB0, 0x3C, 0x59, 0x64, 0xB6, 0x0F, 0x4C, 0x7A } }

// _APPLE_SYSTEM_INFO_DATA_RECORD
typedef struct _APPLE_SYSTEM_INFO_DATA_RECORD {
  EFI_SUBCLASS_TYPE1_HEADER Header;
  UINT32                    NameSize;
  UINT32                    ValueSize;
} APPLE_SYSTEM_INFO_DATA_RECORD;

// gAppleSystemInfoProducerNameGuid
extern EFI_GUID gAppleSystemInfoProducerNameGuid;

#endif // ifndef _APPLE_SYSTEM_INFO_H_
