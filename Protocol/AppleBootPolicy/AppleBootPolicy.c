///
/// @file      Protocol/AppleBootPolicy/AppleBootPolicy.c
///
///            Apple protocol to get a volume's bootable file.
///
/// @author    Download-Fritz
/// @date      19/12/2014: Initial version
/// @date      23/02/2015: Minor tweaks
/// @date      15/03/2015: Updated documentation and restructuring
/// @copyright The decompilation is of an educational purpose to better understand the behavior of the
///            Apple EFI implementation and making use of it. In no way is the content's usage licensed
///            or allowed. All rights remain at Apple Inc. To be used under the terms of 'Fair use'.
///

//
// CREDITS:
//   Reversed from AppleBootPolicy.efi, which is Apple Inc. property
//   Relies on HFSPlus.efi which is Apple Inc. property as well
//   Decompiled by Download-Fritz
//

#include <AppleEfi.h>

#include <Protocol/AppleBootPolicy.h>

// gAppleBootPolicyProtocolGuid
EFI_GUID gAppleBootPolicyProtocolGuid = APPLE_BOOT_POLICY_PROTOCOL_GUID;

EFI_GUID_STRING (&gAppleBootPolicyProtocolGuid, "Boot Policy", "Apple Boot Policy Protocol");
