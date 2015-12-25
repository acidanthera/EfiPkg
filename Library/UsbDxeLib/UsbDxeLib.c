/** @file
  Common Dxe Libarary for USB

  Copyright (C) 2005 - 2015 Apple Inc.  All rights reserved.<BR>

  This program and the accompanying materials have not been licensed.
  Neither is its usage, its redistribution, in source or binary form,
  licensed, nor implicitely or explicitely permitted, except when
  required by applicable law.

  Unless required by applicable law or agreed to in writing, software
  distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
  OR CONDITIONS OF ANY KIND, either express or implied.
**/

#include <AppleEfi.h>

#include <Library/AppleDriverLib.h>
#include <Library/UsbDxeLib.h>

// UsbGetDescriptor
/** Usb Get Descriptor

  @param[in]  UsbIo             EFI_USB_IO_PROTOCOL
  @param[in]  Value             Device Request Value
  @param[in]  Index             Device Request Index 
  @param[in]  DescriptorLength  Descriptor Length
  @param[out] Descriptor        Descriptor Buffer to contain result
  @param[out] Status            Transfer Status

  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbGetDescriptor (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT16               Value,
  IN  UINT16               Index,
  IN  UINT16               DescriptorLength,
  OUT VOID                 *Descriptor,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;
  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (DescriptorLength > 0);
  ASSERT (Descriptor != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    DevReq.RequestType = USB_DEV_GET_DESCRIPTOR_REQ_TYPE;
    DevReq.Request     = USB_REQ_GET_DESCRIPTOR;
    DevReq.Value       = Value;
    DevReq.Index       = Index;
    DevReq.Length      = DescriptorLength;
    EfiStatus          = UsbIo->UsbControlTransfer (
                                  UsbIo,
                                  &DevReq,
                                  EfiUsbDataIn,
                                  TIMEOUT_VALUE,
                                  Descriptor,
                                  DescriptorLength,
                                  Status
                                  );
  }

  return EfiStatus;
}

// UsbSetDescriptor
/** Usb Set Descriptor

  @param[in]  UsbIo             EFI_USB_IO_PROTOCOL
  @param[in]  Value             Device Request Value
  @param[in]  Index             Device Request Index 
  @param[in]  DescriptorLength  Descriptor Length
  @param[in]  Descriptor        Descriptor Buffer to set
  @param[out] Status            Transfer Status

  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbSetDescriptor (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT16               Value,
  IN  UINT16               Index,
  IN  UINT16               DescriptorLength,
  IN  VOID                 *Descriptor,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;

  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (DescriptorLength > 0);
  ASSERT (Descriptor != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    DevReq.RequestType = USB_DEV_SET_DESCRIPTOR_REQ_TYPE;
    DevReq.Request     = USB_REQ_SET_DESCRIPTOR;
    DevReq.Value       = Value;
    DevReq.Index       = Index;
    DevReq.Length      = DescriptorLength;
    EfiStatus          = UsbIo->UsbControlTransfer (
                                  UsbIo,
                                  &DevReq,
                                  EfiUsbDataOut,
                                  TIMEOUT_VALUE,
                                  Descriptor,
                                  DescriptorLength,
                                  Status
                                  );
  }

  return EfiStatus;
}

// UsbGetInterface
/** Usb Get Device Interface

  @param[in]  UsbIo       EFI_USB_IO_PROTOCOL
  @param[in]  Index       Interface index value
  @param[out] AltSetting  Alternate setting
  @param[out] Status      Trasnsfer status

  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbGetInterface (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT16               Index,
  OUT UINT8                *AltSetting,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;
  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (AltSetting != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    DevReq.RequestType = USB_DEV_GET_INTERFACE_REQ_TYPE;
    DevReq.Request     = USB_REQ_GET_INTERFACE;
    DevReq.Index       = Index;
    DevReq.Length      = sizeof (*AltSetting);
    EfiStatus          = UsbIo->UsbControlTransfer (
                                  UsbIo,
                                  &DevReq,
                                  EfiUsbDataIn,
                                  TIMEOUT_VALUE,
                                  AltSetting,
                                  sizeof (*AltSetting),
                                  Status
                                  );
  }

  return EfiStatus;
}

// UsbSetInterface
/** Usb Set Device Interface

  @param[in]  UsbIo        EFI_USB_IO_PROTOCOL
  @param[in]  InterfaceNo  Interface Number
  @param[in]  AltSetting   Alternate setting
  @param[out] Status       Trasnsfer status

  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbSetInterface (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT16               InterfaceNo,
  IN  UINT16               AltSetting,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;

  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    DevReq.RequestType = USB_DEV_SET_INTERFACE_REQ_TYPE;
    DevReq.Request     = USB_REQ_SET_INTERFACE;
    DevReq.Value       = AltSetting;
    DevReq.Index       = InterfaceNo;
    EfiStatus          = UsbIo->UsbControlTransfer (
                                  UsbIo,
                                  &DevReq,
                                  EfiUsbNoData,
                                  TIMEOUT_VALUE,
                                  NULL,
                                  0,
                                  Status
                                  );
  }

  return EfiStatus;
}

// UsbGetConfiguration
/** Usb Get Device Configuration

  @param[in]  UsbIo        EFI_USB_IO_PROTOCOL
  @param[out] ConfigValue  Config Value
  @param[out] Status       Transfer Status

  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbGetConfiguration (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  OUT UINT8                *ConfigValue,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;
  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (ConfigValue != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    DevReq.RequestType = USB_DEV_GET_CONFIGURATION_REQ_TYPE;
    DevReq.Request     = USB_REQ_GET_CONFIG;
    DevReq.Length      = sizeof (*ConfigValue);
    EfiStatus          = UsbIo->UsbControlTransfer (
                                  UsbIo,
                                  &DevReq,
                                  EfiUsbDataIn,
                                  TIMEOUT_VALUE,
                                  ConfigValue,
                                  sizeof (*ConfigValue),
                                  Status
                                  );
  }

  return EfiStatus;
}

// UsbSetConfiguration
/** Usb Set Device Configuration

  @param[in]  UsbIo    EFI_USB_IO_PROTOCOL
  @param[in]  Value    Configuration Value to set
  @param[out] Status   Transfer status

  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbSetConfiguration (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT16               Value,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;

  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    DevReq.RequestType = USB_DEV_SET_CONFIGURATION_REQ_TYPE;
    DevReq.Request     = USB_REQ_SET_CONFIG;
    DevReq.Value       = Value;
    EfiStatus          = UsbIo->UsbControlTransfer (
                                  UsbIo,
                                  &DevReq,
                                  EfiUsbNoData,
                                  TIMEOUT_VALUE,
                                  NULL,
                                  0,
                                  Status
                                  );

    ASSERT_EFI_ERROR (EfiStatus);
  }

  return EfiStatus;
}

// UsbSetFeature
/** Usb Set Device Feature

  @param[in]  UsbIo      EFI_USB_IO_PROTOCOL
  @param[in]  Recipient  Interface/Device/Endpoint
  @param[in]  Value      Request value
  @param[in]  Target     Request Index
  @param[out] Status     Transfer status
  
  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbSetFeature (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINTN                Recipient,
  IN  UINT16               Value,
  IN  UINT16               Target,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;

  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    switch (Recipient) {
    case USB_TARGET_DEVICE:
    {
      DevReq.RequestType = USB_DEV_SET_FEATURE_REQ_TYPE_D;
      break;
    }

    case USB_TARGET_INTERFACE:
    {
      DevReq.RequestType = USB_DEV_SET_FEATURE_REQ_TYPE_I;
      break;
    }

    case USB_TARGET_ENDPOINT:
    {
      DevReq.RequestType = USB_DEV_SET_FEATURE_REQ_TYPE_E;
      break;
    }
    }

    // Fill device request, see USB1.1 spec

    DevReq.Request = USB_REQ_SET_FEATURE;
    DevReq.Value   = Value;
    DevReq.Index   = Target;
    EfiStatus      = UsbIo->UsbControlTransfer (
                              UsbIo,
                              &DevReq,
                              EfiUsbNoData,
                              TIMEOUT_VALUE,
                              NULL,
                              0,
                              Status
                              );
  }

  return EfiStatus;
}

// UsbClearFeature
/** Usb Clear Device Feature

  @param[in]  UsbIo      EFI_USB_IO_PROTOCOL
  @param[in]  Recipient  Interface/Device/Endpoint
  @param[in]  Value      Request value
  @param[in]  Target     Request Index
  @param[out] Status     Transfer status
  
  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbClearFeature (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINTN                Recipient,
  IN  UINT16               Value,
  IN  UINT16               Target,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;

  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    switch (Recipient) {
    case USB_TARGET_DEVICE:
    {
      DevReq.RequestType = USB_DEV_CLEAR_FEATURE_REQ_TYPE_D;
      break;
    }

    case USB_TARGET_INTERFACE:
    {
      DevReq.RequestType = USB_DEV_CLEAR_FEATURE_REQ_TYPE_I;
      break;
    }

    case USB_TARGET_ENDPOINT:
    {
      DevReq.RequestType = USB_DEV_CLEAR_FEATURE_REQ_TYPE_E;
      break;
    }
    }

    // Fill device request, see USB1.1 spec

    DevReq.Request = USB_REQ_CLEAR_FEATURE;
    DevReq.Value   = Value;
    DevReq.Index   = Target;
    EfiStatus      = UsbIo->UsbControlTransfer (
                              UsbIo,
                              &DevReq,
                              EfiUsbNoData,
                              TIMEOUT_VALUE,
                              NULL,
                              0,
                              Status
                              );
  }

  return EfiStatus;
}

// UsbGetStatus
/** Usb Get Device Status

  @param[in]  UsbIo      EFI_USB_IO_PROTOCOL
  @param[in]  Recipient  Interface/Device/Endpoint
  @param[in]  Target     Request index
  @param[out] DevStatus  Device status
  @param[out] Status     Transfer status

  @retval EFI_INVALID_PARAMETER  Parameter is error
  @retval EFI_SUCCESS            Success
  @retval EFI_TIMEOUT            Device has no response
**/
EFI_STATUS
UsbGetStatus (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINTN                Recipient,
  IN  UINT16               Target,
  OUT UINT16               *DevStatus,
  OUT UINT32               *Status
  )
{
  EFI_STATUS             EfiStatus;

  EFI_USB_DEVICE_REQUEST DevReq;

  ASSERT (UsbIo != NULL);
  ASSERT (DevStatus != NULL);
  ASSERT (Status != NULL);

  EfiStatus = EFI_INVALID_PARAMETER;

  if (UsbIo != NULL) {
    EfiZeroMem (&DevReq, sizeof (DevReq));

    switch (Recipient) {
    case USB_TARGET_DEVICE:
    {
      DevReq.RequestType = USB_DEV_GET_STATUS_REQ_TYPE_D;
      break;
    }

    case USB_TARGET_INTERFACE:
    {
      DevReq.RequestType = USB_DEV_GET_STATUS_REQ_TYPE_I;
      break;
    }

    case USB_TARGET_ENDPOINT:
    {
      DevReq.RequestType = USB_DEV_GET_STATUS_REQ_TYPE_E;
      break;
    }
    }

    // Fill device request, see USB1.1 spec

    DevReq.Request = USB_REQ_GET_STATUS;
    DevReq.Value   = 0;
    DevReq.Index   = Target;
    DevReq.Length  = sizeof (*DevStatus);
    EfiStatus      = UsbIo->UsbControlTransfer (
                              UsbIo,
                              &DevReq,
                              EfiUsbDataIn,
                              TIMEOUT_VALUE,
                              DevStatus,
                              sizeof (*DevStatus),
                              Status
                              );
  }

  return EfiStatus;
}

// UsbClearEndpointHalt
/** Clear endpoint stall

  @param[in]  UsbIo       EFI_USB_IO_PROTOCOL
  @param[in]  EndpointNo  Endpoint Number
  @param[out] Status      Transfer Status

  @retval EFI_NOT_FOUND     Can't find the Endpoint
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_SUCCESS       Success
**/
EFI_STATUS
UsbClearEndpointHalt (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT8                EndpointNo,
  OUT UINT32               *Status
  )
{
  EFI_STATUS                   EfiStatus;

  EFI_USB_ENDPOINT_DESCRIPTOR  EndpointDescriptor;
  EFI_USB_INTERFACE_DESCRIPTOR InterfaceDescriptor;
  UINT8                        Index;

  ASSERT (UsbIo != NULL);
  ASSERT (Status != NULL);

  EfiZeroMem (&EndpointDescriptor, sizeof (EndpointDescriptor));

  // First seach the endpoint descriptor for that endpoint addr
  EfiStatus = UsbIo->UsbGetInterfaceDescriptor (
                       UsbIo,
                       &InterfaceDescriptor
                       );

  if (!EFI_ERROR (EfiStatus)) {
    for (Index = 0; Index < InterfaceDescriptor.NumEndpoints; ++Index) {
      EfiStatus = UsbIo->UsbGetEndpointDescriptor (
                           UsbIo,
                           Index,
                           &EndpointDescriptor
                           );

      if (!EFI_ERROR (EfiStatus) && (EndpointDescriptor.EndpointAddress == EndpointNo)) {
        break;
      }
    }

    EfiStatus = EFI_NOT_FOUND;

    if (Index != InterfaceDescriptor.NumEndpoints) {
      EfiStatus = UsbClearFeature (
                    UsbIo,
                    USB_TARGET_ENDPOINT,
                    USB_FEATURE_ENDPOINT_HALT,
                    EndpointDescriptor.EndpointAddress,
                    Status
                    );
    }
  }

  return EfiStatus;
}

// UsbGetHidDescriptor
/** Get Hid Descriptor

  @param[in]  UsbIo          EFI_USB_IO_PROTOCOL
  @param[in]  InterfaceNum   Hid interface number
  @param[out] HidDescriptor  Caller allocated Buffer to store Usb hid descriptor
                             if successfully returned.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbGetHidDescriptor (
  IN  EFI_USB_IO_PROTOCOL     *UsbIo,
  IN  UINT8                   InterfaceNum,
  OUT EFI_USB_HID_DESCRIPTOR  *HidDescriptor UNALIGNED
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);
  ASSERT (HidDescriptor != NULL);

  Request.RequestType = 0x81;
  Request.Request     = 0x06;
  Request.Value       = (UINT16) (0x21 << 8);
  Request.Index       = InterfaceNum;
  Request.Length      = sizeof (*HidDescriptor);
  Status              = UsbIo->UsbControlTransfer (
                                 UsbIo,
                                 &Request,
                                 EfiUsbDataIn,
                                 TIMEOUT_VALUE,
                                 HidDescriptor,
                                 sizeof (*HidDescriptor),
                                 &UsbStatus
                                 );

  return Status;
}

// UsbGetReportDescriptor
/** get Report Class descriptor

  @param[in]  UsbIo             EFI_USB_IO_PROTOCOL.
  @param[in]  InterfaceNum      Report interface number.
  @param[in]  DescriptorSize    Length of DescriptorBuffer.
  @param[out] DescriptorBuffer  Caller allocated Buffer to store Usb report descriptor
                                if successfully returned.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbGetReportDescriptor (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT8                InterfaceNum,
  IN  UINT16               DescriptorSize,
  OUT UINT8                *DescriptorBuffer
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);
  ASSERT (DescriptorSize > 0);
  ASSERT (DescriptorBuffer != NULL);

  // Fill Device request packet

  Request.RequestType = 0x81;
  Request.Request     = 0x06;
  Request.Value       = (UINT16)(0x22 << 8);
  Request.Index       = InterfaceNum;
  Request.Length      = DescriptorSize;
  Status              = UsbIo->UsbControlTransfer (
                                 UsbIo,
                                 &Request,
                                 EfiUsbDataIn,
                                 TIMEOUT_VALUE,
                                 DescriptorBuffer,
                                 DescriptorSize,
                                 &UsbStatus
                                 );

  return Status;
}

// UsbGetProtocolRequest
/** Get Hid Protocol Request

  @param[in] UsbIo      EFI_USB_IO_PROTOCOL
  @param[in] Interface  Which interface the caller wants to get protocol
  @param[in] Protocol   Protocol value returned.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbGetProtocolRequest (
  IN EFI_USB_IO_PROTOCOL  *UsbIo,
  IN UINT8                Interface,
  IN UINT8                *Protocol
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);
  ASSERT (Protocol != NULL);

  // Fill Device request packet

  Request.RequestType = 0xa1;

  // 10100001b;

  Request.Request     = EFI_USB_GET_PROTOCOL_REQUEST;
  Request.Value       = 0;
  Request.Index       = Interface;
  Request.Length      = 1;
  Status              = UsbIo->UsbControlTransfer (
                                 UsbIo,
                                 &Request,
                                 EfiUsbDataIn,
                                 TIMEOUT_VALUE,
                                 Protocol,
                                 sizeof (*Protocol),
                                 &UsbStatus
                                 );

  return Status;
}

// UsbSetProtocolRequest
/** Set Hid Protocol Request

  @param[in] UsbIo      EFI_USB_IO_PROTOCOL
  @param[in] Interface  Which interface the caller wants to set protocol
  @param[in] Protocol   Protocol value the caller wants to set.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbSetProtocolRequest (
  IN EFI_USB_IO_PROTOCOL  *UsbIo,
  IN UINT8                Interface,
  IN UINT8                Protocol
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);


  // Fill Device request packet

  Request.RequestType = 0x21;

  // 00100001b;

  Request.Request     = EFI_USB_SET_PROTOCOL_REQUEST;
  Request.Value       = Protocol;
  Request.Index       = Interface;
  Request.Length      = 0;
  Status              = UsbIo->UsbControlTransfer (
                                 UsbIo,
                                 &Request,
                                 EfiUsbNoData,
                                 TIMEOUT_VALUE,
                                 NULL,
                                 0,
                                 &UsbStatus
                                 );
  return Status;
}

// UsbSetIdleRequest
/** Set Idel request.

  @param[in] UsbIo      EFI_USB_IO_PROTOCOL
  @param[in] Interface  Which interface the caller wants to set.
  @param[in] ReportId   Which report the caller wants to set.
  @param[in] Duration   Idle rate the caller wants to set.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbSetIdleRequest (
  IN EFI_USB_IO_PROTOCOL  *UsbIo,
  IN UINT8                Interface,
  IN UINT8                ReportId,
  IN UINT8                Duration
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);
  ASSERT (Duration > 0);


  // Fill Device request packet

  Request.RequestType = 0x21;

  // 00100001b;

  Request.Request     = EFI_USB_SET_IDLE_REQUEST;
  Request.Value       = (UINT16) ((Duration << 8) | ReportId);
  Request.Index       = Interface;
  Request.Length      = 0;
  Status              = UsbIo->UsbControlTransfer (
                                 UsbIo,
                                 &Request,
                                 EfiUsbNoData,
                                 TIMEOUT_VALUE,
                                 NULL,
                                 0,
                                 &UsbStatus
                                 );
  return Status;
}

// UsbGetIdleRequest
/** Get Idel request.

  @param[in]  UsbIo      EFI_USB_IO_PROTOCOL
  @param[in]  Interface  Which interface the caller wants to get.
  @param[in]  ReportId   Which report the caller wants to get.
  @param[out] Duration   Idle rate the caller wants to get.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbGetIdleRequest (
  IN  EFI_USB_IO_PROTOCOL  *UsbIo,
  IN  UINT8                Interface,
  IN  UINT8                ReportId,
  OUT UINT8                *Duration
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);
  ASSERT (Duration != NULL);

  // Fill Device request packet

  Request.RequestType = 0xa1;

  // 10100001b;

  Request.Request     = EFI_USB_GET_IDLE_REQUEST;
  Request.Value       = ReportId;
  Request.Index       = Interface;
  Request.Length      = 1;
  Status              = UsbIo->UsbControlTransfer (
                                 UsbIo,
                                 &Request,
                                 EfiUsbDataIn,
                                 TIMEOUT_VALUE,
                                 Duration,
                                 sizeof (*Duration),
                                 &UsbStatus
                                 );

  return Status;
}

// UsbSetReportRequest
/** Hid Set Report request.

  @param[in] UsbIo       EFI_USB_IO_PROTOCOL
  @param[in] Interface   Which interface the caller wants to set.
  @param[in] ReportId    Which report the caller wants to set.
  @param[in] ReportType  Type of report.
  @param[in] ReportLen   Length of report descriptor.
  @param[in] Report      Report Descriptor Buffer.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbSetReportRequest (
  IN EFI_USB_IO_PROTOCOL  *UsbIo,
  IN UINT8                Interface,
  IN UINT8                ReportId,
  IN UINT8                ReportType,
  IN UINT16               ReportLen,
  IN UINT8                *Report
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);
  ASSERT (ReportLen > 0);
  ASSERT (Report != NULL);

  // Fill Device request packet

  Request.RequestType = 0x21;

  // 00100001b;

  Request.Request     = EFI_USB_SET_REPORT_REQUEST;
  Request.Value       = (UINT16)((ReportType << 8) | ReportId);
  Request.Index       = Interface;
  Request.Length      = ReportLen;
  Status              = UsbIo->UsbControlTransfer (
                                 UsbIo,
                                 &Request,
                                 EfiUsbDataOut,
                                 TIMEOUT_VALUE,
                                 Report,
                                 ReportLen,
                                 &UsbStatus
                                 );

  return Status;
}

// UsbGetReportRequest
/** Hid Set Report request.

  @param[in] UsbIo       EFI_USB_IO_PROTOCOL
  @param[in] Interface   Which interface the caller wants to set.
  @param[in] ReportId    Which report the caller wants to set.
  @param[in] ReportType  Type of report.
  @param[in] ReportLen   Length of report descriptor.
  @param[in] Report      Caller allocated Buffer to store Report Descriptor.

  @retval EFI_SUCCESS       Success
  @retval EFI_DEVICE_ERROR  Hardware error
  @retval EFI_TIMEOUT       Device has no response
**/
EFI_STATUS
UsbGetReportRequest (
  IN EFI_USB_IO_PROTOCOL  *UsbIo,
  IN UINT8                Interface,
  IN UINT8                ReportId,
  IN UINT8                ReportType,
  IN UINT16               ReportLen,
  IN UINT8                *Report
  )
{
  EFI_STATUS             Status;

  UINT32                 UsbStatus;
  EFI_USB_DEVICE_REQUEST Request;

  ASSERT (UsbIo != NULL);
  ASSERT (ReportLen > 0);
  ASSERT (Report != NULL);

  // Fill Device request packet

  Request.RequestType = 0xA1;

  // 10100001b;

  Request.Request = EFI_USB_GET_REPORT_REQUEST;
  Request.Value   = (UINT16)((ReportType << 8) | ReportId);
  Request.Index   = Interface;
  Request.Length  = ReportLen;
  Status          = UsbIo->UsbControlTransfer (
                             UsbIo,
                             &Request,
                             EfiUsbDataIn,
                             TIMEOUT_VALUE,
                             Report,
                             ReportLen,
                             &UsbStatus
                             );

  return Status;
}
