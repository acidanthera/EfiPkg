//********************************************************************
//	created:	28:8:2012   18:40
//	filename: 	AppleFramebufferInfo.h
//	author:		tiamo
//	purpose:	graph info
//********************************************************************

// DEPRECATED IN FAVOR OF GOP

#ifndef _APPLE_FRAMEBUFFER_INFO_H_
#define _APPLE_FRAMEBUFFER_INFO_H_

// APPLE_FRAMEBUFFER_INFO_PROTOCOL_GUID
#define APPLE_FRAMEBUFFER_INFO_PROTOCOL_GUID \
  { 0xE316E100, 0x0751, 0x4C49, { 0x90, 0x56, 0x48, 0x6C, 0x7E, 0x47, 0x29, 0x03 } }

FORWARD_DECLARATION (APPLE_FRAMEBUFFER_INFO_PROTOCOL);

// GET_INFO
typedef
EFI_STATUS
(EFIAPI *GET_INFO)(
  APPLE_FRAMEBUFFER_INFO_PROTOCOL  *This,
  UINT64                           *BaseAddress,
  UINT64                           *FrameBufferSize,
  UINT32                           *ByterPerRow,
  UINT32                           *Width,
  UINT32                           *Height,
  UINT32                           *ColorDepth
  );

// _APPLE_FRAMEBUFFER_INFO_PROTOCOL
struct _APPLE_FRAMEBUFFER_INFO_PROTOCOL {
  GET_INFO GetInfo;
};

// gAppleFramebufferInfoProtocolGuid
extern EFI_GUID gAppleFramebufferInfoProtocolGuid;

#endif // ifndef _APPLE_FRAMEBUFFER_INFO_H_
