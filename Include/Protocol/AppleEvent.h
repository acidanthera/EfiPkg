#ifndef __APPLE_EVENT_H__
#define __APPLE_EVENT_H__

//
// Related definitions
//

// Apple Event Type
///@{
#define APPLE_EVENT_TYPE_NONE                0
#define APPLE_EVENT_TYPE_MOUSE_MOVED         BIT (0)
#define APPLE_EVENT_TYPE_MOUSE_DOWN          BIT (1)
#define APPLE_EVENT_TYPE_MOUSE_UP            BIT (2)
#define APPLE_EVENT_TYPE_MOUSE_CLICK         BIT (3)
#define APPLE_EVENT_TYPE_MOUSE_DOUBLE_CLICK  BIT (4)
#define APPLE_EVENT_TYPE_LEFT_BUTTON         BIT (5)
#define APPLE_EVENT_TYPE_RIGHT_BUTTON        BIT (6)
#define APPLE_EVENT_TYPE_RESERVED_BUTTON     BIT (7)
#define APPLE_EVENT_TYPE_KEY_DOWN            BIT (8)
#define APPLE_EVENT_TYPE_KEY_UP              BIT (9)
#define APPLE_EVENT_TYPE_MODIFIER_DOWN       BIT (10)
#define APPLE_EVENT_TYPE_MODIFIER_UP         BIT (11)
///@}

#define APPLE_CLICK_MOUSE_EVENTS   (APPLE_EVENT_TYPE_MOUSE_DOWN | APPLE_EVENT_TYPE_MOUSE_UP | APPLE_EVENT_TYPE_MOUSE_CLICK | APPLE_EVENT_TYPE_LEFT_BUTTON | APPLE_EVENT_TYPE_RIGHT_BUTTON)
#define APPLE_ALL_MOUSE_EVENTS     0x00FF
#define APPLE_ALL_KEYBOARD_EVENTS  0xFF00

// APPLE_EVENT_TYPE
typedef UINT32 APPLE_EVENT_TYPE;

// APPLE_POINTER_EVENT_TYPE
typedef UINTN APPLE_POINTER_EVENT_TYPE;

#pragma pack(1)

// APPLE_KEY_EVENT_DATA
typedef struct _APPLE_KEY_EVENT_DATA {
  UINT16          NoKeyPairs; // ??
  struct {
    EFI_INPUT_KEY InputKey;
    APPLE_KEY     AppleKey;
  }               KeyPair;
  UINT16          Unknown;    // ??
} APPLE_KEY_EVENT_DATA;

#pragma pack()

typedef union _APPLE_EVENT_DATA {
  APPLE_KEY_EVENT_DATA     *AppleKeyEventData;
  APPLE_POINTER_EVENT_TYPE PointerEventType;
  UINTN                    Raw;
} APPLE_EVENT_DATA;

// _DIMENSION
typedef struct _DIMENSION {
  INT32 Horizontal;
  INT32 Vertical;
} DIMENSION;

// _APPLE_EVENT_QUERY_INFORMATION
typedef struct _APPLE_EVENT_QUERY_INFORMATION {
  struct {
    UINT16 Year;
    UINT8  Month;
    UINT8  Day;
    UINT8  Hour;
    UINT8  Minute;
    UINT8  Second;
    UINT8  Pad1;
  }                  CreationTime;
  APPLE_EVENT_TYPE   EventType;
  APPLE_EVENT_DATA   EventData;
  APPLE_MODIFIER_MAP Modifiers;
  DIMENSION          PointerPosition;
} APPLE_EVENT_QUERY_INFORMATION;

// APPLE_EVENT_NOTIFY_FUNCTION
typedef
VOID
(EFIAPI *APPLE_EVENT_NOTIFY_FUNCTION)(
  IN APPLE_EVENT_QUERY_INFORMATION  *Information,
  IN VOID                           *NotifyContext
  );

// _APPLE_EVENT_HANDLE
typedef struct _APPLE_EVENT_HANDLE {
  UINT32                      Signature;
  EFI_LIST_ENTRY              This;
  BOOLEAN                     Ready;
  BOOLEAN                     Registered;
  UINT32                      EventType;
  APPLE_EVENT_NOTIFY_FUNCTION NotifyFunction;
  VOID                        *NotifyContext;
  CHAR8                       *Name;
} APPLE_EVENT_HANDLE;

//
// Protocol
//

// APPLE_EVENT_PROTOCOL_GUID
#define APPLE_EVENT_PROTOCOL_GUID \
  { 0x33BE0EF1, 0x89C9, 0x4A6D, { 0xBB, 0x9F, 0x69, 0xDC, 0x8D, 0xD5, 0x16, 0xB9 } }

// REGISTER_HANDLER
typedef
EFI_STATUS
(EFIAPI *REGISTER_HANDLER)(
  IN  APPLE_EVENT_TYPE             EventType,
  IN  APPLE_EVENT_NOTIFY_FUNCTION  NotifyFunction,
  OUT APPLE_EVENT_HANDLE           **EventHandle,
  IN  VOID                         *NotifyContext
  );

// UNREGISTER_HANDLER
typedef
EFI_STATUS
(EFIAPI *UNREGISTER_HANDLER)(
  IN APPLE_EVENT_HANDLE  *EventHandle
  );

// SET_CURSOR_POSITION
typedef
EFI_STATUS
(EFIAPI *SET_CURSOR_POSITION)(
  IN DIMENSION  *Position
  );

// SET_EVENT_NAME
typedef
EFI_STATUS
(EFIAPI *SET_EVENT_NAME)(
  IN OUT APPLE_EVENT_HANDLE  *EventHandle,
  IN     CHAR8               *EventName
  );

// IS_CAPS_LOCK_ACTIVE
typedef
EFI_STATUS
(EFIAPI *IS_CAPS_LOCK_ACTIVE)(
  IN OUT BOOLEAN  *CapsLockActive
  );

// _APPLE_EVENT_PROTOCOL
typedef struct _APPLE_EVENT_PROTOCOL {
  UINT64              Revision;           ///< 
  REGISTER_HANDLER    RegisterHandler;    ///< 
  UNREGISTER_HANDLER  UnregisterHandler;  ///< 
  SET_CURSOR_POSITION SetCursorPosition;  ///< 
  SET_EVENT_NAME      SetEventName;       ///< 
  IS_CAPS_LOCK_ACTIVE IsCapsLockActive;   ///< 
} APPLE_EVENT_PROTOCOL;

// gAppleEventProtocolGuid
extern EFI_GUID gAppleEventProtocolGuid;

#endif // ifndef __APPLE_EVENT_H__
