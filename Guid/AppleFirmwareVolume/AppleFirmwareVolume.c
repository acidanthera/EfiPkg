/** @file
  Copyright (C) 2005 - 2017, Apple Inc.  All rights reserved.
  Portions Copyright (C) 2014 - 2017, CupertinoNet.  All rights reserved.<BR>

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
**/

#include <AppleEfi.h>

#include APPLE_GUID_DEFINITION (AppleFirmwareVolume)

// gAppleImageListGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleImageListGuid = APPLE_IMAGE_LIST_GUID;

EFI_GUID_STRING (
  &gAppleImageListGuid,
  "Image List",
  "Apple Image List"
  );

// gAppleArrowCursorImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleArrowCursorImageGuid = APPLE_ARROW_CURSOR_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleArrowCursorImageGuid,
  "Arrow Cursor Image",
  "Apple Arrow Cursor Image"
  );

// gAppleArrowCursor2xImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleArrowCursor2xImageGuid = APPLE_ARROW_CURSOR_2X_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleArrowCursor2xImageGuid,
  "HiDPI Arrow Cursor Image",
  "Apple HiDPI Arrow Cursor Image"
  );

// gAppleBackButtonSmallImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBackButtonSmallImageGuid = APPLE_BACK_BUTTON_SMALL_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBackButtonSmallImageGuid,
  "Back Button Small Image",
  "Apple Back Button Small Image"
  );

// gAppleBatteryState0ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBatteryState0ImageGuid = APPLE_BATTERY_STATE_0_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBatteryState0ImageGuid,
  "Battery State 0 Image",
  "Apple Battery State 0 Image"
  );

// gAppleBatteryState1ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBatteryState1ImageGuid = APPLE_BATTERY_STATE_1_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBatteryState1ImageGuid,
  "Battery State 1 Image",
  "Apple Battery State 1 Image"
  );

// gAppleBatteryState2ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBatteryState2ImageGuid = APPLE_BATTERY_STATE_2_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBatteryState2ImageGuid,
  "Battery State 2 Image",
  "Apple Battery State 2 Image"
  );

// gAppleBatteryState3ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBatteryState3ImageGuid = APPLE_BATTERY_STATE_3_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBatteryState3ImageGuid,
  "Battery State 3 Image",
  "Apple Battery State 3 Image"
  );

// gAppleBatteryState4ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBatteryState4ImageGuid = APPLE_BATTERY_STATE_4_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBatteryState4ImageGuid,
  "Battery State 4 Image",
  "Apple Battery State 4 Image"
  );

// gAppleBatteryState5ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBatteryState5ImageGuid = APPLE_BATTERY_STATE_5_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBatteryState5ImageGuid,
  "Battery State 5 Image",
  "Apple Battery State 5 Image"
  );

// gAppleBatteryState6ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBatteryState6ImageGuid = APPLE_BATTERY_STATE_6_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBatteryState6ImageGuid,
  "Battery State 6 Image",
  "Apple Battery State 6 Image"
  );

// gAppleBeginBootButtonImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBeginBootButtonImageGuid = APPLE_BEGIN_BOOT_BUTTON_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBeginBootButtonImageGuid,
  "Begin Boot Button Image",
  "Apple Begin Boot Button Image"
  );

// gAppleBeginStickyBootButtonImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBeginStickyBootButtonImageGuid = APPLE_BEGIN_STICKY_BOOT_BUTTON_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBeginStickyBootButtonImageGuid,
  "Begin Sticky Boot Button Image",
  "Apple Sticky Begin Boot Button Image"
  );

// gAppleContinueButtonSmallImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleContinueButtonSmallImageGuid = APPLE_CONTINUE_BUTTON_SMALL_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleContinueButtonSmallImageGuid,
  "Continue Button Small Image",
  "Apple Continue Button Small Image"
  );

// gAppleBootNameLabelImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBootNameLabelImageGuid = APPLE_BOOT_NAME_LABEL_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBootNameLabelImageGuid,
  "Boot Name Label Image",
  "Apple Boot Name Label Image"
  );

// gAppleBrokenBootImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleBrokenBootImageGuid = APPLE_BROKEN_BOOT_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleBrokenBootImageGuid,
  "Broken Boot Image",
  "Apple Broken Boot Image"
  );

// gAppleFireWireHDImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleFireWireHDImageGuid = APPLE_FIREWIRE_HD_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleFireWireHDImageGuid,
  "FireWire HD Image",
  "Apple FireWire HD Image"
  );

// gAppleGenericCDImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleGenericCDImageGuid = APPLE_GENERIC_CD_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleGenericCDImageGuid,
  "Generic CD Image",
  "Apple Generic CD Image"
  );

// gAppleGenericExternalHDImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleGenericExternalHDImageGuid = APPLE_GENERIC_EXTERNAL_HD_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleGenericExternalHDImageGuid,
  "Generic External HD Image",
  "Apple Generic External HD Image"
  );

// gAppleInternalHDImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleInternalHDImageGuid = APPLE_INTERNAL_HD_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleInternalHDImageGuid,
  "Internal HD Image",
  "Apple Internal HD Image"
  );

// gAppleNetBootImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleNetBootImageGuid = APPLE_NETBOOT_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleNetBootImageGuid,
  "NetBoot Image",
  "Apple NetBoot Image"
  );

// gAppleNetworkRecoveryImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleNetworkRecoveryImageGuid = APPLE_NETWORK_RECOVERY_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleNetworkRecoveryImageGuid,
  "Network Recovery Image",
  "Apple Network Recovery Image"
  );

// gAppleNetworkVolumeImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleNetworkVolumeImageGuid = APPLE_NETWORK_VOLUME_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleNetworkVolumeImageGuid,
  "Network Volume Image",
  "Apple Network Volume Image"
  );

// gApplePasswordLockImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gApplePasswordLockImageGuid = APPLE_PASSWORD_LOCK_IMAGE_GUID;

EFI_GUID_STRING (
  &gApplePasswordLockImageGuid,
  "Firmware Password Lock Image",
  "Apple Firmware Password Lock Image"
  );

// gAppleSDImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleSDImageGuid = APPLE_SD_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleSDImageGuid,
  "SD Card Image",
  "Apple SD Card Image"
  );

// gAppleSelectedImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleSelectedImageGuid = APPLE_SELECTED_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleSelectedImageGuid,
  "Selected Image",
  "Apple Selected Image"
  );

// gAppleUsbHDImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleUsbHDImageGuid = APPLE_USB_HD_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleUsbHDImageGuid,
  "USB HD Image",
  "Apple USB HD Image"
  );

// gAppleWirelessSmallImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleWirelessSmallImageGuid = APPLE_WIRELESS_SMALL_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleWirelessSmallImageGuid,
  "Wireless Small Image",
  "Apple Wireless Small Image"
  );

// gAppleLogoImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleLogoImageGuid = APPLE_LOGO_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleLogoImageGuid,
  "Apple Logo Image",
  "Apple Logo Image"
  );

// gApplePasswordEmptyImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gApplePasswordEmptyImageGuid = APPLE_PASSWORD_EMPTY_IMAGE_GUID;

EFI_GUID_STRING (
  &gApplePasswordEmptyImageGuid,
  "Password Empty Image",
  "Apple Password Empty Image"
  );

// gApplePasswordFillImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gApplePasswordFillImageGuid = APPLE_PASSWORD_FILL_IMAGE_GUID;

EFI_GUID_STRING (
  &gApplePasswordFillImageGuid,
  "Password Fill Image",
  "Apple Password Fill Image"
  );

// gApplePasswordProceedImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gApplePasswordProceedImageGuid = APPLE_PASSWORD_PROCEED_IMAGE_GUID;

EFI_GUID_STRING (
  &gApplePasswordProceedImageGuid,
  "Password Proceed Image",
  "Apple Password Proceed Image"
  );

// gAppleLogo1394ImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleLogo1394ImageGuid = APPLE_LOGO_1394_IMAGE_GUID;

EFI_GUID_STRING (
  &gApplePasswordProceedImageGuid,
  "FireWire Logo Image",
  "Apple FireWire Logo Image"
  );

// gAppleLogoThunderboltImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleLogoThunderboltImageGuid = APPLE_LOGO_THUNDERBOLT_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleLogoThunderboltImageGuid,
  "Thunderbolt Logo Image",
  "Apple Thunderbolt Logo Image"
  );

// gAppleClockImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleClockImageGuid = APPLE_CLOCK_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleClockImageGuid,
  "Clock Image",
  "Apple Clock Image"
  );

// gAppleErrorGlobeBorderImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleErrorGlobeBorderImageGuid = APPLE_ERROR_GLOBE_BORDER_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleErrorGlobeBorderImageGuid,
  "Error Globe Border Image",
  "Apple Error Globe Border Image"
  );

// gAppleErrorGlobeTitleImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleErrorGlobeTitleImageGuid = APPLE_ERROR_GLOBE_TITLE_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleErrorGlobeTitleImageGuid,
  "Error Globe Title Image",
  "Apple Error Globe Title Image"
  );

// gAppleErrorTriangleImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleErrorTriangleImageGuid = APPLE_ERROR_TRIANGLE_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleErrorTriangleImageGuid,
  "Triangle Error Image",
  "Apple Triangle Error Image"
  );

// gAppleGlobeBorderImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleGlobeBorderImageGuid = APPLE_GLOBE_BORDER_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleGlobeBorderImageGuid,
  "Globe Border Image",
  "Apple Globe Border Image"
  );

// gAppleGlobeMaskImageGuid
GLOBAL_REMOVE_IF_UNREFERENCED
EFI_GUID
gAppleGlobeMaskImageGuid = APPLE_GLOBE_MASK_IMAGE_GUID;

EFI_GUID_STRING (
  &gAppleGlobeMaskImageGuid,
  "Globe Mask Image",
  "Apple Globe Mask Image"
  );
