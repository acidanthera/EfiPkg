#ifndef _APPLE_EVENT_LIB_H_
#define _APPLE_EVENT_LIB_H_

// CreateTimerEvent
EFI_EVENT
CreateTimerEvent (
  IN EFI_EVENT_NOTIFY  NotifyFunction,
  IN VOID              *NotifyContext,
  IN UINT64            TriggerTime,
  IN BOOLEAN           SignalPeriodic,
  IN EFI_TPL           NotifyTpl
  );

// CreateNotifyEvent
EFI_EVENT
CreateNotifyEvent (
  IN EFI_EVENT_NOTIFY  NotifyFunction,
  IN VOID              *NotifyContext,
  IN UINT64            TriggerTime,
  IN BOOLEAN           SignalPeriodic
  );

// CancelEvent
VOID
CancelEvent (
  IN EFI_EVENT  Event
  );

#endif // ifndef _APPLE_EVENT_LIB_H_
