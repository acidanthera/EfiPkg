#include <AppleEfi.h>

#include <Guid/AppleNvram.h>

// gAppleVendorNvramGuid
/// A global variable storing the GUID of the APPLE_VENDOR_NVRAM EFI variable scope.
EFI_GUID gAppleVendorNvramGuid = APPLE_VENDOR_NVRAM_GUID;

// gAppleBootGuid
/// A global variable storing the GUID of the APPLE_BOOT EFI variable scope.
EFI_GUID gAppleBootGuid = APPLE_BOOT_GUID;

// gAppleCoreStorageGuid
/// A global variable storing the GUID of the APPLE_CORE_STORAGE EFI variable scope.
EFI_GUID gAppleCoreStorageGuid = APPLE_CORE_STORAGE_NVRAM_GUID;

// gAppleEfiNvramTrbStagingCommandGuid
/// A global variable storing the GUID of the APPLE_EFI_NVRAM_TRB_SECURE EFI variable scope.
EFI_GUID gAppleEfiNvramTrbStagingCommandGuid = APPLE_EFI_NVRAM_TRB_STAGING_COMMAND_GUID;

// AppleWirelessNetworkNvramGuid
/// A global variable storing the GUID of the APPLE_WIRELESS_NETWORK EFI variable scope.
EFI_GUID gAppleWirelessNetworkNvramGuid = APPLE_WIRELESS_NETWORK_NVRAM_GUID;

// AppleEfiAppearanceNvramGuid
/// A global variable storing the GUID of the APPLE_EFI_APPEARANCE EFI variable scope.
EFI_GUID gAppleEfiAppearanceNvramGuid = APPLE_EFI_APPEARANCE_NVRAM_GUID;

// gAppleEfiNvramResetGuid
/// A global variable storing the GUID of the APPLE_EFI_NVRAM_TRB_SECURE EFI variable scope.
EFI_GUID gAppleEfiNvramTrbSecureVariableGuid = APPLE_EFI_NVRAM_TRB_SECURE_VARIABLE_GUID;
