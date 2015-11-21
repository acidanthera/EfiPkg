## @file
#
#
##

[Defines]
  PLATFORM_NAME             = ApplePkg
  PLATFORM_GUID             = 0adcc78e-2fdc-4481-998d-8684a7b602e9
  PLATFORM_VERSION          = 2015-001
  DSC_SPECIFICATION         = 0x00010018
  OUTPUT_DIRECTORY          = Build/ApplePkg
  SUPPORTED_ARCHITECTURES   = IA32|IPF|X64|EBC|ARM|AARCH64
  BUILD_TARGETS             = RELEASE|DEBUG
  SKUID_IDENTIFIER          = DEFAULT
  EFI_SPECIFICATION_VERSION = 0x0001000A
  PI_SPECIFICATION_VERSION  = 0x00000009
  TIANO_RELEASE_VERSION     = 0x00080006

[LibraryClasses]
  AppleKeyMapAggregatorLib|ApplePkg/Library/AppleKeyMapAggregatorLib/AppleKeyMapAggregatorLib.inf
  AppleKeyMapLib|ApplePkg/Library/AppleKeyMapLib/AppleKeyMapLib.inf
  AppleMathLib|ApplePkg/Library/AppleMathLib/AppleMathLib.inf
  UsbDxeLib|ApplePkg/Library/UsbDxeLib/UsbDxeLib.inf

[Components]
  ApplePkg/Guid/AppleGuidLib.inf
  ApplePkg/Protocol/AppleProtocolLib.inf
  ApplePkg/Library/AppleKeyMapLib/AppleKeyMapLib.inf
  ApplePkg/Library/AppleKeyMapAggregatorLib/AppleKeyMapAggregatorLib.inf
  ApplePkg/Library/AppleMathLib/AppleMathLib.inf
  ApplePkg/Library/UsbDxeLib/UsbDxeLib.inf

[BuildOptions]
  INTEL:DEBUG_*_*_CC_FLAGS   = /D EFI_DEBUG
  INTEL:RELEASE_*_*_CC_FLAGS = /D MDEPKG_NDEBUG /D EFI_NDEBUG
  GCC:DEBUG_*_*_CC_FLAGS     = -DEFI_DEBUG
  GCC:RELEASE_*_*_CC_FLAGS   = -DMDEPKG_NDEBUG -DEFI_NDEBUG
  MSFT:DEBUG_*_*_CC_FLAGS    = -DEFI_DEBUG
  MSFT:RELEASE_*_*_CC_FLAGS  = /D MDEPKG_NDEBUG /D EFI_NDEBUG
  XCODE:DEBUG_*_*_CC_FLAGS   = -DEFI_DEBUG
  XCODE:RELEASE_*_*_CC_FLAGS = -DMDEPKG_NDEBUG -DEFI_NDEBUG
