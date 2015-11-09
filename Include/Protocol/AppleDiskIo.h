#ifndef _APPLE_DISK_IO_H_
#define _APPLE_DISK_IO_H_

// APPLE_DISK_IO_PROTOCOL_GUID
#define APPLE_DISK_IO_PROTOCOL_GUID \
  { 0x5B27263B, 0x9083, 0x415E, { 0x88, 0x9E, 0x64, 0x32, 0xCA, 0xA9, 0xB8, 0x13 } }

FORWARD_DECLARATION (APPLE_DISK_IO_PROTOCOL);

// APPLE_DISK_READ
typedef
EFI_STATUS
(EFIAPI *APPLE_DISK_READ)(
  IN  APPLE_DISK_IO_PROTOCOL  *This,
  IN  UINT32                  MediaId,
  IN  UINT64                  LBA,
  IN  UINTN                   BufferSize,
  OUT VOID                    *Buffer
  );

// APPLE_DISK_FLUSH
typedef
EFI_STATUS
(EFIAPI *APPLE_DISK_FLUSH)(
  IN APPLE_DISK_IO_PROTOCOL  *This
  );

// _APPLE_DISK_IO_PROTOCOL
struct _APPLE_DISK_IO_PROTOCOL {
  APPLE_DISK_READ  ReadDisk;
  APPLE_DISK_FLUSH Flush;
};

// gAppleDiskIoProtocolGuid
extern EFI_GUID gAppleDiskIoProtocolGuid;

#endif // ifndef _APPLE_DISK_IO_H_
