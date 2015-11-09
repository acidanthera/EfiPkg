#include <AppleEfi.h>

#include <IndustryStandard/AppleHid.h>

#include <Library/AppleKeyMapLib.h>

// gAppleHidUsbKbUsageKeyMap
/// The default United States key map for Apple keyboards.
APPLE_KEY_DESCRIPTOR gAppleKeyMap[91] = {
	{ AppleHidUsbKbUsageKeyA,              { SCAN_NULL,                   L'a' },                 { SCAN_NULL,                   L'A' } },
	{ AppleHidUsbKbUsageKeyB,              { SCAN_NULL,                   L'b' },                 { SCAN_NULL,                   L'B' } },
	{ AppleHidUsbKbUsageKeyC,              { SCAN_NULL,                   L'c' },                 { SCAN_NULL,                   L'C' } },
	{ AppleHidUsbKbUsageKeyD,              { SCAN_NULL,                   L'd' },                 { SCAN_NULL,                   L'D' } },
	{ AppleHidUsbKbUsageKeyE,              { SCAN_NULL,                   L'e' },                 { SCAN_NULL,                   L'E' } },
	{ AppleHidUsbKbUsageKeyF,              { SCAN_NULL,                   L'f' },                 { SCAN_NULL,                   L'F' } },
	{ AppleHidUsbKbUsageKeyG,              { SCAN_NULL,                   L'g' },                 { SCAN_NULL,                   L'G' } },
	{ AppleHidUsbKbUsageKeyH,              { SCAN_NULL,                   L'h' },                 { SCAN_NULL,                   L'H' } },
	{ AppleHidUsbKbUsageKeyI,              { SCAN_NULL,                   L'i' },                 { SCAN_NULL,                   L'I' } },
	{ AppleHidUsbKbUsageKeyJ,              { SCAN_NULL,                   L'j' },                 { SCAN_NULL,                   L'J' } },
	{ AppleHidUsbKbUsageKeyK,              { SCAN_NULL,                   L'k' },                 { SCAN_NULL,                   L'K' } },
	{ AppleHidUsbKbUsageKeyL,              { SCAN_NULL,                   L'l' },                 { SCAN_NULL,                   L'L' } },
	{ AppleHidUsbKbUsageKeyM,              { SCAN_NULL,                   L'm' },                 { SCAN_NULL,                   L'M' } },
	{ AppleHidUsbKbUsageKeyN,              { SCAN_NULL,                   L'n' },                 { SCAN_NULL,                   L'N' } },
	{ AppleHidUsbKbUsageKeyO,              { SCAN_NULL,                   L'o' },                 { SCAN_NULL,                   L'O' } },
	{ AppleHidUsbKbUsageKeyP,              { SCAN_NULL,                   L'p' },                 { SCAN_NULL,                   L'P' } },
	{ AppleHidUsbKbUsageKeyQ,              { SCAN_NULL,                   L'q' },                 { SCAN_NULL,                   L'Q' } },
	{ AppleHidUsbKbUsageKeyR,              { SCAN_NULL,                   L'r' },                 { SCAN_NULL,                   L'R' } },
	{ AppleHidUsbKbUsageKeyS,              { SCAN_NULL,                   L's' },                 { SCAN_NULL,                   L'S' } },
	{ AppleHidUsbKbUsageKeyT,              { SCAN_NULL,                   L't' },                 { SCAN_NULL,                   L'T' } },
	{ AppleHidUsbKbUsageKeyU,              { SCAN_NULL,                   L'u' },                 { SCAN_NULL,                   L'U' } },
	{ AppleHidUsbKbUsageKeyV,              { SCAN_NULL,                   L'v' },                 { SCAN_NULL,                   L'V' } },
	{ AppleHidUsbKbUsageKeyW,              { SCAN_NULL,                   L'w' },                 { SCAN_NULL,                   L'W' } },
	{ AppleHidUsbKbUsageKeyX,              { SCAN_NULL,                   L'x' },                 { SCAN_NULL,                   L'X' } },
	{ AppleHidUsbKbUsageKeyY,              { SCAN_NULL,                   L'y' },                 { SCAN_NULL,                   L'Y' } },
	{ AppleHidUsbKbUsageKeyZ,              { SCAN_NULL,                   L'z' },                 { SCAN_NULL,                   L'Z' } },
	{ AppleHidUsbKbUsageKeyOne,            { SCAN_NULL,                   L'1' },                 { SCAN_NULL,                   L'!' } },
	{ AppleHidUsbKbUsageKeyTwo,            { SCAN_NULL,                   L'2' },                 { SCAN_NULL,                   L'@' } },
	{ AppleHidUsbKbUsageKeyThree,          { SCAN_NULL,                   L'3' },                 { SCAN_NULL,                   L'#' } },
	{ AppleHidUsbKbUsageKeyFour,           { SCAN_NULL,                   L'4' },                 { SCAN_NULL,                   L'$' } },
	{ AppleHidUsbKbUsageKeyFive,           { SCAN_NULL,                   L'5' },                 { SCAN_NULL,                   L'%' } },
	{ AppleHidUsbKbUsageKeySix,            { SCAN_NULL,                   L'6' },                 { SCAN_NULL,                   L'^' } },
	{ AppleHidUsbKbUsageKeySeven,          { SCAN_NULL,                   L'7' },                 { SCAN_NULL,                   L'&' } },
	{ AppleHidUsbKbUsageKeyEight,          { SCAN_NULL,                   L'8' },                 { SCAN_NULL,                   L'*' } },
	{ AppleHidUsbKbUsageKeyNine,           { SCAN_NULL,                   L'9' },                 { SCAN_NULL,                   L'(' } },
	{ AppleHidUsbKbUsageKeyZero,           { SCAN_NULL,                   L'0' },                 { SCAN_NULL,                   L')' } },
	{ AppleHidUsbKbUsageKeyEnter,          { SCAN_NULL,                   CHAR_CARRIAGE_RETURN }, { SCAN_NULL,                   CHAR_CARRIAGE_RETURN } },
	{ AppleHidUsbKbUsageKeyEscape,         { SCAN_ESC,                    CHAR_NULL },            { SCAN_ESC,                    CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyBackSpace,      { SCAN_NULL,                   CHAR_BACKSPACE },       { SCAN_NULL,                   CHAR_BACKSPACE } },
	{ AppleHidUsbKbUsageKeyTab,            { SCAN_NULL,                   CHAR_TAB },             { SCAN_NULL,                   CHAR_TAB } },
	{ AppleHidUsbKbUsageKeySpaceBar,       { SCAN_NULL,                   L'L' },                 { SCAN_NULL,                   L'L' } },
	{ AppleHidUsbKbUsageKeyMinus,          { SCAN_NULL,                   L'-' },                 { SCAN_NULL,                   L'/' } },
	{ AppleHidUsbKbUsageKeyEquals,         { SCAN_NULL,                   L'=' },                 { SCAN_NULL,                   L'+' } },
	{ AppleHidUsbKbUsageKeyLeftBracket,    { SCAN_NULL,                   L'[' },                 { SCAN_NULL,                   L'{' } },
	{ AppleHidUsbKbUsageKeyRightBracket,   { SCAN_NULL,                   L']' },                 { SCAN_NULL,                   L'}' } },
	{ AppleHidUsbKbUsageKeyBackslash,      { SCAN_NULL,                   L'\\' },                { SCAN_NULL,                   L'|' } },
	{ AppleHidUsbKbUsageKeySemicolon,      { SCAN_NULL,                   L';' },                 { SCAN_NULL,                   L':' } },
	{ AppleHidUsbKbUsageKeyQuotation,      { SCAN_NULL,                   L'\'' },                { SCAN_NULL,                   L'"' } },
	{ AppleHidUsbKbUsageKeyAcute,          { SCAN_NULL,                   L'`' },                 { SCAN_NULL,                   L'~' } },
	{ AppleHidUsbKbUsageKeyComma,          { SCAN_NULL,                   L',' },                 { SCAN_NULL,                   L'<' } },
	{ AppleHidUsbKbUsageKeyPeriod,         { SCAN_NULL,                   L'.' },                 { SCAN_NULL,                   L'>' } },
	{ AppleHidUsbKbUsageKeySlash,          { SCAN_NULL,                   L'/' },                 { SCAN_NULL,                   L'?' } },
	{ AppleHidUsbKbUsageKeyF1,             { SCAN_F1,                     CHAR_NULL },            { SCAN_F1,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF2,             { SCAN_F2,                     CHAR_NULL },            { SCAN_F2,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF3,             { SCAN_F3,                     CHAR_NULL },            { SCAN_F3,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF4,             { SCAN_F4,                     CHAR_NULL },            { SCAN_F4,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF5,             { SCAN_F5,                     CHAR_NULL },            { SCAN_F5,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF6,             { SCAN_F6,                     CHAR_NULL },            { SCAN_F6,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF7,             { SCAN_F7,                     CHAR_NULL },            { SCAN_F7,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF8,             { SCAN_F8,                     CHAR_NULL },            { SCAN_F8,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF9,             { SCAN_F9,                     CHAR_NULL },            { SCAN_F9,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF10,            { SCAN_F10,                    CHAR_NULL },            { SCAN_F10,                    CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF11,            { SCAN_F11,                    CHAR_NULL },            { SCAN_F11,                    CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyF12,            { SCAN_F12,                    CHAR_NULL },            { SCAN_F12,                    CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyIns,            { SCAN_INSERT,                 CHAR_NULL },            { SCAN_INSERT,                 CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyHome,           { SCAN_HOME,                   CHAR_NULL },            { SCAN_HOME,                   CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyPgUp,           { SCAN_PAGE_UP,                CHAR_NULL },            { SCAN_PAGE_UP,                CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyDel,            { SCAN_DELETE,                 CHAR_NULL },            { SCAN_DELETE,                 CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyEnd,            { SCAN_END,                    CHAR_NULL },            { SCAN_END,                    CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyPgDn,           { SCAN_PAGE_DOWN,              CHAR_NULL },            { SCAN_PAGE_DOWN,              CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyRightArrow,     { SCAN_RIGHT,                  CHAR_NULL },            { SCAN_RIGHT,                  CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyLeftArrow,      { SCAN_LEFT,                   CHAR_NULL },            { SCAN_LEFT,                   CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyDownArrow,      { SCAN_DOWN,                   CHAR_NULL },            { SCAN_DOWN,                   CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyUpArrow,        { SCAN_UP,                     CHAR_NULL },            { SCAN_UP,                     CHAR_NULL } },
	{ AppleHidUsbKbUsageKeyPadSlash,       { AppleScanCodeKeypadSlash,    L'/' },                 { AppleScanCodeKeypadSlash,    L'/' } },
	{ AppleHidUsbKbUsageKeyPadAsterisk,    { AppleScanCodeKeypadAsterisk, L'*' },                 { AppleScanCodeKeypadAsterisk, L'*' } },
	{ AppleHidUsbKbUsageKeyPadMinus,       { AppleScanCodeKeypadMinus,    L'-' },                 { AppleScanCodeKeypadMinus,    L'-' } },
	{ AppleHidUsbKbUsageKeyPadPlus,        { AppleScanCodeKeypadPlus,     L'+' },                 { AppleScanCodeKeypadPlus,     L'+' } },
	{ AppleHidUsbKbUsageKeyPadEnter,       { AppleScanCodeKeypadEnter,    CHAR_CARRIAGE_RETURN }, { AppleScanCodeKeypadEnter,    CHAR_CARRIAGE_RETURN } },
	{ AppleHidUsbKbUsageKeyPadOne,         { AppleScanCodeKeypadOne,      L'1' },                 { AppleScanCodeKeypadOne,      L'1' } },
	{ AppleHidUsbKbUsageKeyPadTwo,         { AppleScanCodeKeypadTwo,      L'2' },                 { AppleScanCodeKeypadTwo,      L'2' } },
	{ AppleHidUsbKbUsageKeyPadThree,       { AppleScanCodeKeypadThree,    L'3' },                 { AppleScanCodeKeypadThree,    L'3' } },
	{ AppleHidUsbKbUsageKeyPadFour,        { AppleScanCodeKeypadFour,     L'4' },                 { AppleScanCodeKeypadFour,     L'4' } },
	{ AppleHidUsbKbUsageKeyPadFive,        { AppleScanCodeKeypadFive,     L'5' },                 { AppleScanCodeKeypadFive,     L'5' } },
	{ AppleHidUsbKbUsageKeyPadSix,         { AppleScanCodeKeypadSix,      L'6' },                 { AppleScanCodeKeypadSix,      L'6' } },
	{ AppleHidUsbKbUsageKeyPadSeven,       { AppleScanCodeKeypadSeven,    L'7' },                 { AppleScanCodeKeypadSeven,    L'7' } },
	{ AppleHidUsbKbUsageKeyPadEight,       { AppleScanCodeKeypadEight,    L'8' },                 { AppleScanCodeKeypadEight,    L'8' } },
	{ AppleHidUsbKbUsageKeyPadNine,        { AppleScanCodeKeypadNine,     L'9' },                 { AppleScanCodeKeypadNine,     L'9' } },
	{ AppleHidUsbKbUsageKeyPadIns,         { AppleScanCodeKeypadIns,      L'0' },                 { AppleScanCodeKeypadIns,      L'0' } },
	{ AppleHidUsbKbUsageKeyPadDel,         { AppleScanCodeKeypadDel,      L'.' },                 { AppleScanCodeKeypadDel,      L'.' } },
	{ AppleHidUsbKbUsageKeyPadEquals,      { AppleScanCodeKeypadEquals,   L'=' },                 { AppleScanCodeKeypadEquals,   L'=' } }
};

// InputKeyFromAppleKey
VOID
InputKeyFromAppleKey (
	IN  APPLE_KEY     AppleKey,
	OUT EFI_INPUT_KEY *InputKey,
	IN  BOOLEAN       Shifted
	) // sub_18D2
{
	UINTN                Index;
	APPLE_KEY_DESCRIPTOR *Key;

	Key = &gAppleKeyMap[0];

	for (Index = 0; Index < ARRAY_LENGTH (gAppleKeyMap); ++Index) {
		if (Key->AppleKey == AppleKey) {
			*InputKey = (Shifted ? Key->ShiftedInputKey : Key->InputKey);
			return;
		}

		++Key;
	}

	InputKey->ScanCode    = SCAN_NULL;
	InputKey->UnicodeChar = CHAR_NULL;
}
