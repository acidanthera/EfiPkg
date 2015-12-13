## @file ApplePkg.dsc
#
# 
#
# Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
#
# This program and the accompanying materials have not been licensed.
# Neither is its usage, its redistribution, in source or binary form,
# licensed, nor implicitely or explicitely permitted, except when
# required by applicable law.
#
# Unless required by applicable law or agreed to in writing, software
# distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
# OR CONDITIONS OF ANY KIND, either express or implied.
#
#  
##

[Defines]
  PLATFORM_NAME             = Apple
  PLATFORM_GUID             = 0ADCC78E-2FDC-4481-998D-8684A7B602E9
  PLATFORM_VERSION          = 2015-001
  DSC_SPECIFICATION         = 0x00010006
  OUTPUT_DIRECTORY          = Build/$(PLATFORM_NAME)
  SUPPORTED_ARCHITECTURES   = IA32|IPF|X64|EBC|ARM|AARCH64
  BUILD_TARGETS             = RELEASE|DEBUG
  SKUID_IDENTIFIER          = DEFAULT
  EFI_SPECIFICATION_VERSION = 0x0001000A
  PI_SPECIFICATION_VERSION  = 0x00000009
  TIANO_RELEASE_VERSION     = 0x00080006

[LibraryClasses]
  AppleDriverLib|ApplePkg/Library/AppleDriverLib/AppleDriverLib.inf
  AppleKeyMapAggregatorLib|ApplePkg/Library/AppleKeyMapAggregatorLib/AppleKeyMapAggregatorLib.inf
  AppleKeyMapLib|ApplePkg/Library/AppleKeyMapLib/AppleKeyMapLib.inf
  AppleMathLib|ApplePkg/Library/AppleMathLib/AppleMathLib.inf
  AppleSmcMmioLib|ApplePkg/Library/AppleSmcMmioLib/AppleSmcMmioLib.inf
  MmioLib|ApplePkg/Library/BaseMmioLib/BaseMmioLib.inf
  UsbDxeLib|ApplePkg/Library/UsbDxeLib/UsbDxeLib.inf

[Components]
  ApplePkg/Library/AppleDriverLib/AppleDriverLib.inf
  ApplePkg/Guid/AppleGuidLib.inf
  ApplePkg/Protocol/AppleProtocolLib.inf
  ApplePkg/Library/BaseMmioLib/BaseMmioLib.inf
  ApplePkg/Library/AppleKeyMapLib/AppleKeyMapLib.inf
  ApplePkg/Library/AppleKeyMapAggregatorLib/AppleKeyMapAggregatorLib.inf
  ApplePkg/Library/AppleMathLib/AppleMathLib.inf
  ApplePkg/Library/AppleSmcMmioLib/AppleSmcMmioLib.inf
  ApplePkg/Library/UsbDxeLib/UsbDxeLib.inf

[BuildOptions]
DEFINE MSFT_MACRO  = /D EFI_SPECIFICATION_VERSION=$(EFI_SPECIFICATION_VERSION) /D PI_SPECIFICATION_VERSION=$(PI_SPECIFICATION_VERSION) /D TIANO_RELEASE_VERSION=$(TIANO_RELEASE_VERSION)
DEFINE INTEL_MACRO = /D EFI_SPECIFICATION_VERSION=$(EFI_SPECIFICATION_VERSION) /D PI_SPECIFICATION_VERSION=$(PI_SPECIFICATION_VERSION) /D TIANO_RELEASE_VERSION=$(TIANO_RELEASE_VERSION)
DEFINE GCC_MACRO   = -DEFI_SPECIFICATION_VERSION=$(EFI_SPECIFICATION_VERSION) -DPI_SPECIFICATION_VERSION=$(PI_SPECIFICATION_VERSION) -DTIANO_RELEASE_VERSION=$(TIANO_RELEASE_VERSION) -DNO_BUILTIN_VA_FUNCS -Wno-unused-but-set-variable -fno-stack-protector
DEFINE XCODE_MACRO = -DEFI_SPECIFICATION_VERSION=$(EFI_SPECIFICATION_VERSION) -DPI_SPECIFICATION_VERSION=$(PI_SPECIFICATION_VERSION) -DTIANO_RELEASE_VERSION=$(TIANO_RELEASE_VERSION)

  INTEL:DEBUG_*_*_CC_FLAGS   = $(INTEL_MACRO) /D EFI_DEBUG
  INTEL:RELEASE_*_*_CC_FLAGS = $(INTEL_MACRO) /D MDEPKG_NDEBUG /D EFI_NDEBUG
  GCC:DEBUG_*_*_CC_FLAGS     = $(GCC_MACRO) -DEFI_DEBUG
  GCC:RELEASE_*_*_CC_FLAGS   = $(GCC_MACRO) -DMDEPKG_NDEBUG -DEFI_NDEBUG
  MSFT:DEBUG_*_*_CC_FLAGS    = $(MSFT_MACRO) -DEFI_DEBUG
  MSFT:RELEASE_*_*_CC_FLAGS  = $(MSFT_MACRO) /D MDEPKG_NDEBUG /D EFI_NDEBUG
  XCODE:DEBUG_*_*_CC_FLAGS   = $(XCODE_MACRO) -DEFI_DEBUG
  XCODE:RELEASE_*_*_CC_FLAGS = $(XCODE_MACRO) -DMDEPKG_NDEBUG -DEFI_NDEBUG
