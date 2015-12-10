//
// Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
//
// This program and the accompanying materials have not been licensed.
// Neither is its usage, its redistribution, in source or binary form,
// licensed, nor implicitely or explicitely permitted, except when
// required by applicable law.
//
// Unless required by applicable law or agreed to in writing, software
// distributed is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
// OR CONDITIONS OF ANY KIND, either express or implied.
//

///
/// @file      Include/Protocol/AppleFramebufferInfo.h
///
///            
///
/// @author    tiamo
/// @date      28/08/2012: Initial version
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_FRAMEBUFFER_INFO_H__
#define __APPLE_FRAMEBUFFER_INFO_H__

// APPLE_FRAMEBUFFER_INFO_PROTOCOL_GUID
#define APPLE_FRAMEBUFFER_INFO_PROTOCOL_GUID \
  { 0xE316E100, 0x0751, 0x4C49, { 0x90, 0x56, 0x48, 0x6C, 0x7E, 0x47, 0x29, 0x03 } }

FORWARD_DECLARATION (APPLE_FRAMEBUFFER_INFO_PROTOCOL);

// FRAMEBUFFER_INFO_GET_INFO
/// 
///
/// @param 
///
/// @return 
/// @retval 
typedef
EFI_STATUS
(EFIAPI *FRAMEBUFFER_INFO_GET_INFO)(
  IN  APPLE_FRAMEBUFFER_INFO_PROTOCOL  *This,
  OUT UINT64                           *BaseAddress,
  OUT UINT64                           *FrameBufferSize,
  OUT UINT32                           *ByterPerRow,
  OUT UINT32                           *Width,
  OUT UINT32                           *Height,
  OUT UINT32                           *ColorDepth
  );

// _APPLE_FRAMEBUFFER_INFO_PROTOCOL
struct _APPLE_FRAMEBUFFER_INFO_PROTOCOL {
  FRAMEBUFFER_INFO_GET_INFO GetInfo;  ///< 
};

// gAppleFramebufferInfoProtocolGuid
extern EFI_GUID gAppleFramebufferInfoProtocolGuid;

#endif // ifndef __APPLE_FRAMEBUFFER_INFO_H__
