[Defines]
  PLATFORM_NAME             = ApplePkg
  PLATFORM_GUID             = 0adcc78e-2fdc-4481-998d-8684a7b602e9
  PLATFORM_VERSION          = 1.0
  DSC_SPECIFICATION         = 0x00010018
  OUTPUT_DIRECTORY          = Build/ApplePkg
  SUPPORTED_ARCHITECTURES   = X64|IA32
  BUILD_TARGETS             = RELEASE|DEBUG
  SKUID_IDENTIFIER          = DEFAULT
  EFI_SPECIFICATION_VERSION = 0x0001000A

[Libraries]
!include ApplePkg/ApplePkgLibs.dsc
  EdkCompatibilityPkg/Foundation/Library/Dxe/EfiDriverLib/EfiDriverLib_Edk2.inf

[Components]
  ApplePkg/Protocol/AppleProtocolLib.inf
  ApplePkg/Library/AppleKeyMapLib/AppleKeyMapLib.inf
  ApplePkg/Library/AppleKeyMapAggregatorLib/AppleKeyMapAggregatorLib.inf
  ApplePkg/Library/UsbDxeLib/UsbDxeLib.inf

!include ApplePkg/ApplePkgBuild.dsc
