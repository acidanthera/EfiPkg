/** @file
  Copyright (C) 2005 - 2015, Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#ifndef APPLE_HID_H_
#define APPLE_HID_H_

#include <IndustryStandard/UsbHid.h>

// APPLE_USAGE
#define APPLE_HID_GENERIC_USAGE(UsageId, PageId) (((PageId) << 12) | (UsageId))

/// @{
#define APPLE_HID_USB_KB_KP_USGAE(UsbHidUsageIdKbKp) \
  APPLE_HID_GENERIC_USAGE ((UsbHidUsageIdKbKp), AppleHidKeyboardKeypadPage)

#define APPLE_HID_KP_SCAN_USAGE(UsbHidUsageIdKbKp) \
  APPLE_HID_GENERIC_USAGE ((UsbHidUsageIdKbKp), AppleHidUsbKbUsageKeypadScanPage)

#define APPLE_HID_REMOTE_USAGE(AppleRemoteUsageId)  \
  APPLE_HID_GENERIC_USAGE ((AppleRemoteUsageId), AppleHidRemotePage)
/// @}

// IS_APPLE_KEY_LETTER
#define IS_APPLE_KEY_LETTER(Usage)                           \
  ((((APPLE_HID_USAGE)(Usage)) >= AppleHidUsbKbUsageKeyA)    \
 && (((APPLE_HID_USAGE)(Usage)) <= AppleHidUsbKbUsageKeyZ))

// APPLE_HID_USAGE_ID
typedef UINT8 APPLE_HID_USAGE_ID;

// APPLE_HID_USAGE
typedef UINT16 APPLE_HID_USAGE;

// APPLE_HID_PAGE_ID
enum {
  AppleHidKeyboardKeypadPage       = UsbHidKeyboardKeypadPage,
  AppleHidUsbKbUsageKeypadScanPage = 0x08,
  AppleHidRemotePage               = 0x08
};

// APPLE_HID_PAGE_ID
typedef UINT8 APPLE_HID_PAGE_ID;

// APPLE_SCAN_CODE
enum {
  AppleScanCodeKeypadSlash    = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeySlash),
  AppleScanCodeKeypadAsterisk = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyAsterisk),
  AppleScanCodeKeypadMinus    = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyMinus),
  AppleScanCodeKeypadPlus     = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyPlus),
  AppleScanCodeKeypadEnter    = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyEnter),
  AppleScanCodeKeypadOne      = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyOne),
  AppleScanCodeKeypadTwo      = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyTwo),
  AppleScanCodeKeypadThree    = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyThree),
  AppleScanCodeKeypadFour     = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyFour),
  AppleScanCodeKeypadFive     = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyFive),
  AppleScanCodeKeypadSix      = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeySix),
  AppleScanCodeKeypadSeven    = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeySeven),
  AppleScanCodeKeypadEight    = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyEight),
  AppleScanCodeKeypadNine     = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyNine),
  AppleScanCodeKeypadIns      = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyIns),
  AppleScanCodeKeypadDel      = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyDel),
  AppleScanCodeKeypadEquals   = APPLE_HID_KP_SCAN_USAGE (UsbHidUsageIdKbKpPadKeyEquals)
};

// Apple modifers
/// @{
#define APPLE_MODIFIER_LEFT_CONTROL   USB_HID_KB_KP_MODIFIERS_CONTROL
#define APPLE_MODIFIER_LEFT_SHIFT     USB_HID_KB_KP_MODIFIER_LEFT_SHIFT
#define APPLE_MODIFIER_LEFT_OPTION    USB_HID_KB_KP_MODIFIER_LEFT_ALT
#define APPLE_MODIFIER_LEFT_COMMAND   USB_HID_KB_KP_MODIFIER_LEFT_GUI
#define APPLE_MODIFIER_RIGHT_CONTROL  USB_HID_KB_KP_MODIFIER_RIGHT_CONTROL
#define APPLE_MODIFIER_RIGHT_SHIFT    USB_HID_KB_KP_MODIFIER_RIGHT_SHIFT
#define APPLE_MODIFIER_RIGHT_OPTION   USB_HID_KB_KP_MODIFIER_RIGHT_ALT
#define APPLE_MODIFIER_RIGHT_COMMAND  USB_HID_KB_KP_MODIFIER_RIGHT_GUI
/// @}

// Shortcuts for multiple Apple modifers
/// @{
#define APPLE_MODIFIERS_CONTROL  \
  (APPLE_MODIFIER_LEFT_CONTROL | APPLE_MODIFIER_RIGHT_CONTROL)

#define APPLE_MODIFIERS_SHIFT  \
  (APPLE_MODIFIER_LEFT_CONTROL | APPLE_MODIFIER_RIGHT_CONTROL)

#define APPLE_MODIFIERS_ALT  \
  (APPLE_MODIFIER_LEFT_CONTROL | APPLE_MODIFIER_RIGHT_CONTROL)

#define APPLE_MODIFIERS_GUI  \
  (APPLE_MODIFIER_LEFT_CONTROL | APPLE_MODIFIER_RIGHT_CONTROL)
/// @}

// APPLE_MODIFIER_MAP
typedef UINT16 APPLE_MODIFIER_MAP;

// APPLE_HID_USB_KB_USAGE
/// A set of Apple keys used with the AppleKeyMap protocols.
enum {
  AppleHidUsbKbUsageKeyA                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyA),
  AppleHidUsbKbUsageKeyB                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyB),
  AppleHidUsbKbUsageKeyC                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyC),
  AppleHidUsbKbUsageKeyD                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyD),
  AppleHidUsbKbUsageKeyE                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyE),
  AppleHidUsbKbUsageKeyF                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF),
  AppleHidUsbKbUsageKeyG                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyG),
  AppleHidUsbKbUsageKeyH                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyH),
  AppleHidUsbKbUsageKeyI                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyI),
  AppleHidUsbKbUsageKeyJ                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyJ),
  AppleHidUsbKbUsageKeyK                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyK),
  AppleHidUsbKbUsageKeyL                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyL),
  AppleHidUsbKbUsageKeyM                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyM),
  AppleHidUsbKbUsageKeyN                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyN),
  AppleHidUsbKbUsageKeyO                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyO),
  AppleHidUsbKbUsageKeyP                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyP),
  AppleHidUsbKbUsageKeyQ                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyQ),
  AppleHidUsbKbUsageKeyR                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyR),
  AppleHidUsbKbUsageKeyS                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyS),
  AppleHidUsbKbUsageKeyT                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyT),
  AppleHidUsbKbUsageKeyU                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyU),
  AppleHidUsbKbUsageKeyV                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyV),
  AppleHidUsbKbUsageKeyW                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyW),
  AppleHidUsbKbUsageKeyX                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyX),
  AppleHidUsbKbUsageKeyY                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyY),
  AppleHidUsbKbUsageKeyZ                    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyZ),
  AppleHidUsbKbUsageKeyOne                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyOne),
  AppleHidUsbKbUsageKeyTwo                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyTwo),
  AppleHidUsbKbUsageKeyThree                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyThree),
  AppleHidUsbKbUsageKeyFour                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyFour),
  AppleHidUsbKbUsageKeyFive                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyFive),
  AppleHidUsbKbUsageKeySix                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySix),
  AppleHidUsbKbUsageKeySeven                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySeven),
  AppleHidUsbKbUsageKeyEight                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyEight),
  AppleHidUsbKbUsageKeyNine                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyNine),
  AppleHidUsbKbUsageKeyZero                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyZero),
  AppleHidUsbKbUsageKeyEnter                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyEnter),
  AppleHidUsbKbUsageKeyEscape               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyEsc),
  AppleHidUsbKbUsageKeyBackSpace            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyBackSpace),
  AppleHidUsbKbUsageKeyTab                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyTab),
  AppleHidUsbKbUsageKeySpaceBar             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySpaceBar),
  AppleHidUsbKbUsageKeyMinus                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyMinus),
  AppleHidUsbKbUsageKeyEquals               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyEquals),
  AppleHidUsbKbUsageKeyLeftBracket          = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLeftBracket),
  AppleHidUsbKbUsageKeyRightBracket         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyRightBracket),
  AppleHidUsbKbUsageKeyBackslash            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyBackslash),
  AppleHidUsbKbUsageKeyNonUsHash            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyNonUsHash),
  AppleHidUsbKbUsageKeySemicolon            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySemicolon),
  AppleHidUsbKbUsageKeyQuotation            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyQuotation),
  AppleHidUsbKbUsageKeyAcute                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyAcute),
  AppleHidUsbKbUsageKeyComma                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyComma),
  AppleHidUsbKbUsageKeyPeriod               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyPeriod),
  AppleHidUsbKbUsageKeySlash                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySlash),
  AppleHidUsbKbUsageKeyCLock                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyCLock),
  AppleHidUsbKbUsageKeyF1                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF1),
  AppleHidUsbKbUsageKeyF2                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF2),
  AppleHidUsbKbUsageKeyF3                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF3),
  AppleHidUsbKbUsageKeyF4                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF4),
  AppleHidUsbKbUsageKeyF5                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF5),
  AppleHidUsbKbUsageKeyF6                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF6),
  AppleHidUsbKbUsageKeyF7                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF7),
  AppleHidUsbKbUsageKeyF8                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF8),
  AppleHidUsbKbUsageKeyF9                   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF9),
  AppleHidUsbKbUsageKeyF10                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF10),
  AppleHidUsbKbUsageKeyF11                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF11),
  AppleHidUsbKbUsageKeyF12                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF12),
  AppleHidUsbKbUsageKeyPrint                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyPrint),
  AppleHidUsbKbUsageKeySLock                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySLock),
  AppleHidUsbKbUsageKeyPause                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyPause),
  AppleHidUsbKbUsageKeyIns                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyIns),
  AppleHidUsbKbUsageKeyHome                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyHome),
  AppleHidUsbKbUsageKeyPgUp                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyPgUp),
  AppleHidUsbKbUsageKeyDel                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyDel),
  AppleHidUsbKbUsageKeyEnd                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyEnd),
  AppleHidUsbKbUsageKeyPgDn                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyPgDn),
  AppleHidUsbKbUsageKeyRightArrow           = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyRightArrow),
  AppleHidUsbKbUsageKeyLeftArrow            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLeftArrow),
  AppleHidUsbKbUsageKeyDownArrow            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyDownArrow),
  AppleHidUsbKbUsageKeyUpArrow              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyUpArrow),
  AppleHidUsbKbUsageKeyPadNLck              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyNLck),
  AppleHidUsbKbUsageKeyPadSlash             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeySlash),
  AppleHidUsbKbUsageKeyPadAsterisk          = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyAsterisk),
  AppleHidUsbKbUsageKeyPadMinus             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMinus),
  AppleHidUsbKbUsageKeyPadPlus              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyPlus),
  AppleHidUsbKbUsageKeyPadEnter             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyEnter),
  AppleHidUsbKbUsageKeyPadOne               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyOne),
  AppleHidUsbKbUsageKeyPadTwo               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyTwo),
  AppleHidUsbKbUsageKeyPadThree             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyThree),
  AppleHidUsbKbUsageKeyPadFour              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyFour),
  AppleHidUsbKbUsageKeyPadFive              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyFive),
  AppleHidUsbKbUsageKeyPadSix               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeySix),
  AppleHidUsbKbUsageKeyPadSeven             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeySeven),
  AppleHidUsbKbUsageKeyPadEight             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyEight),
  AppleHidUsbKbUsageKeyPadNine              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyNine),
  AppleHidUsbKbUsageKeyPadIns               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyIns),
  AppleHidUsbKbUsageKeyPadDel               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyDel),
  AppleHidUsbKbUsageKeyPadNonUsBackslash    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyNonUsBackslash),
  AppleHidUsbKbUsageKeyPadApplication       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyApplication),
  AppleHidUsbKbUsageKeyPadPower             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyPower),
  AppleHidUsbKbUsageKeyPadEquals            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyEquals),
  AppleHidUsbKbUsageKeyF13                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF13),
  AppleHidUsbKbUsageKeyF14                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF14),
  AppleHidUsbKbUsageKeyF15                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF15),
  AppleHidUsbKbUsageKeyF16                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF16),
  AppleHidUsbKbUsageKeyF17                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF17),
  AppleHidUsbKbUsageKeyF18                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF18),
  AppleHidUsbKbUsageKeyF19                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF19),
  AppleHidUsbKbUsageKeyF20                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF20),
  AppleHidUsbKbUsageKeyF21                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF21),
  AppleHidUsbKbUsageKeyF22                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF22),
  AppleHidUsbKbUsageKeyF23                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF23),
  AppleHidUsbKbUsageKeyF24                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyF24),
  AppleHidUsbKbUsageKeyExecute              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyExecute),
  AppleHidUsbKbUsageKeyHelp                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyHelp),
  AppleHidUsbKbUsageKeyMenu                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyMenu),
  AppleHidUsbKbUsageKeySelect               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySelect),
  AppleHidUsbKbUsageKeyStop                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyStop),
  AppleHidUsbKbUsageKeyAgain                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyAgain),
  AppleHidUsbKbUsageKeyUndo                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyUndo),
  AppleHidUsbKbUsageKeyCut                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyCut),
  AppleHidUsbKbUsageKeyCopy                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyCopy),
  AppleHidUsbKbUsageKeyPaste                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyPaste),
  AppleHidUsbKbUsageKeyFind                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyFind),
  AppleHidUsbKbUsageKeyMute                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyMute),
  AppleHidUsbKbUsageKeyVolumeUp             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyVolumeUp),
  AppleHidUsbKbUsageKeyVolumeDown           = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyVolumeDown),
  AppleHidUsbKbUsageLockingKeyCLock         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpLockKeyCLock),
  AppleHidUsbKbusageLockingKeyNLock         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpLockKeyNLock),
  AppleHidUsbKbUsageLockingKeySLock         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpLockKeySLock),
  AppleHidUsbKbUsageKeyPadComma             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyComma),
  AppleHidUsbKbUsageKeyPadEqualSign         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyEqualSign),
  AppleHidUsbKbUsageKeyInternational1       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational1),
  AppleHidUsbKbUsageKeyInternational2       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational2),
  AppleHidUsbKbUsageKeyInternational3       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational3),
  AppleHidUsbKbUsageKeyInternational4       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational4),
  AppleHidUsbKbUsageKeyInternational5       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational5),
  AppleHidUsbKbUsageKeyInternational6       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational6),
  AppleHidUsbKbUsageKeyInternational7       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational7),
  AppleHidUsbKbUsageKeyInternational8       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational8),
  AppleHidUsbKbUsageKeyInternational9       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyInternational9),
  AppleHidUsbKbUsageKeyLang1                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang1),
  AppleHidUsbKbUsageKeyLang2                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang2),
  AppleHidUsbKbUsageKeyLang3                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang3),
  AppleHidUsbKbUsageKeyLang4                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang4),
  AppleHidUsbKbUsageKeyLang5                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang5),
  AppleHidUsbKbUsageKeyLang6                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang6),
  AppleHidUsbKbUsageKeyLang7                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang7),
  AppleHidUsbKbUsageKeyLang8                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang8),
  AppleHidUsbKbUsageKeyLang9                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyLang9),
  AppleHidUsbKbUsageKeyAlternateErase       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyAlternateErase),
  AppleHidUsbKbUsageKeySysReq               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySysReq),
  AppleHidUsbKbUsageKeyCancel               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyCancel),
  AppleHidUsbKbUsageKeyClear                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyClear),
  AppleHidUsbKbUsageKeyPrior                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyPrior),
  AppleHidUsbKbUsageKeyReturn               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyReturn),
  AppleHidUsbKbUsageKeySeparator            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeySeparator),
  AppleHidUsbKbUsageKeyOut                  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyOut),
  AppleHidUsbKbUsageKeyOper                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyOper),
  AppleHidUsbKbUsageKeyClearAgain           = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyClearAgain),
  AppleHidUsbKbUsageKeyCrSel                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyCrSel),
  AppleHidUsbKbUsageKeyExSel                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyExSel),
  AppleHidUsbKbUsageKeyPadDoubleZero        = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyDoubleZero),
  AppleHidUsbKbUsageKeyTrippleZero          = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyTrippleZero),
  AppleHidUsbKbUsageKeyThousandsSeparator   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyThousandsSeparator),
  AppleHidUsbKbUsageKeyDecimalSeparator     = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyDecimalSeparator),
  AppleHidUsbKbUsageKeyCurrencyUnit         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyCurrencyUnit),
  AppleHidUsbKbUsageKeyCurrencySubUnit      = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpKeyCurrencySubUnit),
  AppleHidUsbKbUsageKeyPadLeftBracket       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyLeftBracket),
  AppleHidUsbKbUsageKeyPadRightBracket      = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyRightBracket),
  AppleHidUsbKbUsageKeyPadCurlyLeftBracket  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyCurlyLeftBracket),
  AppleHidUsbKbUsageKeyPadCurlyRightBracket = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyCurlyRightBracket),
  AppleHidUsbKbUsageKeyPadTab               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyTab),
  AppleHidUsbKbUsageKeyPadBackspace         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyBackspace),
  AppleHidUsbKbUsageKeyPadA                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyA),
  AppleHidUsbKbUsageKeyPadB                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyB),
  AppleHidUsbKbUsageKeyPadC                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyC),
  AppleHidUsbKbUsageKeyPadD                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyD),
  AppleHidUsbKbUsageKeyPadE                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyE),
  AppleHidUsbKbUsageKeyPadF                 = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyF),
  AppleHidUsbKbUsageKeyPadXor               = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyXor),
  AppleHidUsbKbUsageKeyPadCaret             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyCaret),
  AppleHidUsbKbUsageKeyPadPercent           = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyPercent),
  AppleHidUsbKbUsageKeyPadLeftAngleBracket  = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyLeftAngleBracket),
  AppleHidUsbKbUsageKeyPadRightAngleBracket = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyRightAngleBracket),
  AppleHidUsbKbUsageKeyPadBitwiseAnd        = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyBitwiseAnd),
  AppleHidUsbKbUsageKeyPadLogicalAnd        = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyLogicalAnd),
  AppleHidUsbKbUsageKeyPadBitwiseOr         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyBitwiseOr),
  AppleHidUsbKbUsageKeyPadLogicalOr         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyLogicalOr),
  AppleHidUsbKbUsageKeyPadColon             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyColon),
  AppleHidUsbKbUsageKeyPadHash              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyHash),
  AppleHidUsbKbUsageKeyPadSpace             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeySpace),
  AppleHidUsbKbUsageKeyPadAt                = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyAt),
  AppleHidUsbKbUsageKeyPadExclamationMark   = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyExclamationMark),
  AppleHidUsbKbUsageKeyPadMemoryStore       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMemoryStore),
  AppleHidUsbKbUsageKeyPadMemoryRecall      = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMemoryRecall),
  AppleHidUsbKbUsageKeyPadMemoryClear       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMemoryClear),
  AppleHidUsbKbUsageKeyPadMemoryAdd         = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMemoryAdd),
  AppleHidUsbKbUsageKeyPadMemorySubtract    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMemorySubtract),
  AppleHidUsbKbUsageKeyPadMemoryMultiply    = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMemoryMultiply),
  AppleHidUsbKbUsageKeyPadMemoryDivide      = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyMemoryDivide),
  AppleHidUsbKbUsageKeyPadSign              = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeySign),
  AppleHidUsbKbUsageKeyPadClear             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyClear),
  AppleHidUsbKbUsageKeyPadClearEntry        = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyClearEntry),
  AppleHidUsbKbUsageKeyPadBinary            = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyBinary),
  AppleHidUsbKbUsageKeyPadOctal             = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyOctal),
  AppleHidUsbKbUsageKeyPadDecimal           = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyDecimal),
  AppleHidUsbKbUsageKeyPadHexadecimal       = APPLE_HID_USB_KB_KP_USGAE (UsbHidUsageIdKbKpPadKeyHexadecimal)
};

// APPLE_KEY
typedef APPLE_HID_USAGE APPLE_KEY;

#endif // APPLE_HID_H_
