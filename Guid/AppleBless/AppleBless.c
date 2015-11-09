#include <AppleEfi.h>

#include <Guid/AppleBless.h>

// gAppleBlessedFileInfoId
/// A global variable storing the GUID of the APPLE_BLESSED_FILE_INFO_ID.
EFI_GUID gAppleBlessedFileInfoId = APPLE_BLESSED_FILE_INFO_ID;

// gAppleBlessedFolderInfoId
/// A global variable storing the GUID of the APPLE_BLESSED_FOLDER_INFO_ID.
EFI_GUID gAppleBlessedFolderInfoId = APPLE_BLESSED_FOLDER_INFO_ID;
