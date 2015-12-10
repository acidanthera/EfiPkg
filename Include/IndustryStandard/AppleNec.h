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
/// @file      Include/IndustryStandard/AppleNex.h
///
///            
///
/// @author    Download-Fritz
/// @date      
/// @copyright Copyright (C) 2005 - 2015 Apple Inc. All rights reserved.
///

#ifndef __APPLE_NEC_H__
#define __APPLE_NEC_H__

// https://en.wikipedia.org/wiki/Apple_Remote#Technical_details

#define APPLE_REMOTE_VENDOR  0x043F

// _APPLE_REMOTE_TABLE
enum _APPLE_REMOTE_TABLE {
  AppleRemoteCommandTable = 0x00,
  AppleRemoteKeyTable     = 0x0E
};

// _APPLE_REMOTE_COMMAND
enum _APPLE_REMOTE_COMMAND {
  AppleRemoteCommandPairing            = 0x01,
  AppleRemoteCommandFactoryDefaults    = 0x02,
  AppleRemoteCommandOriginalLowBattery = 0x03,
  AppleRemoteCommandCurrentLowBattery  = 0x07
};

// APPLE_REMOTE_COMMAND
typedef UINT16 APPLE_REMOTE_COMMAND;

// _APPLE_REMOTE_KEY
enum _APPLE_REMOTE_USAGE_ID {
  AppleRemoteKeyMenu         = 0x01,
  AppleRemoteKeyCenter       = 0x02,   ///< In the old remote this is the Play/Pause and Select button
  AppleRemoteKeyRight        = 0x03,
  AppleRemoteKeyLeft         = 0x04,
  AppleRemoteKeyVolumeUp     = 0x05,
  AppleRemoteKeyVolumeDown   = 0x06,
  AppleRemoteKeyPlayUp       = 0x07,
  AppleRemoteKeyPlayDown     = 0x08,
  AppleRemoteKeyPlayNext     = 0x09,
  AppleRemoteKeyPlayPrevious = 0x0A,
  AppleRemoteKeyMenuUp       = 0x0B,
  AppleRemoteKeyMenuDown     = 0x0C,
  AppleRemoteKeyMenuPlay     = 0x0D,
  AppleRemoteKeyMenuNext     = 0x0E,
  AppleRemoteKeyMenuPrevious = 0x0F,
  AppleRemoteKeySelect       = 0x2E,  ///< Select button on the new remote
  AppleRemoteKeyPlay         = 0x2F   ///< Play/Pause on the new remote
};

#pragma pack(1)

// _APPLE_REMOTE_DATA_PACKAGE
typedef PACKED struct _APPLE_REMOTE_DATA_PACKAGE {
  UINT8  Vendor[11];      ///< This is always 0x43f and can be used to identify an Apple Remote
  UINT8  CommandPage[5];  ///< 0x0 for the pairing and other commands, 0xe for the different buttons
  UINT64 DeviceId;        ///< A unique device ID, used to allow pairing of a remote to a specific device. It can be changed with the pairing command
  UINT8  Command[7];      ///< Actual command for the Command Page
  UINT8  Checksum;        ///< All 32 bits added together have to equal 1
} APPLE_REMOTE_DATA_PACKAGE;

#pragma pack()

#endif // ifndef __APPLE_NEC_H__
