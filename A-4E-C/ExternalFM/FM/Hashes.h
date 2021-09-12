#pragma once
#include <Windows.h>

static WCHAR* files[] = {
	L"entry.lua",
	L"A-4E-C.lua",
	L"Cockpit/Scripts/EFM_Data_Bus.lua",
	L"Entry/Suspension.lua",
	L"EFM_BETA_1_BUILD_DO_NOT_DISTRIBUTE.lua",
};

static BYTE hashes[][32] = {
	{0x2c,0x97,0x98,0x2f,0xb6,0xbf,0x64,0x68,0x14,0x37,0xad,0x8b,0x74,0x43,0x75,0xe4,0x36,0xcd,0x41,0xe6},
	{0x6e,0xb1,0x3b,0xcc,0x5e,0x6c,0x4f,0x7b,0xed,0x41,0xef,0x8a,0x77,0x1d,0x17,0xf2,0xc0,0xef,0x3a,0xb3},
	{0x6c,0x1e,0x41,0xfa,0xc3,0x0a,0xb7,0x8a,0x36,0x2f,0xd1,0x3c,0xc1,0x97,0x04,0xc5,0x55,0x78,0x4a,0x18},
	{0x76,0x0a,0x96,0x5c,0xff,0x3d,0x20,0x51,0xc0,0x2e,0x9a,0x79,0x72,0xe6,0x67,0x1b,0x20,0x5b,0x6e,0x92},
	{0xc5,0x45,0xa1,0xec,0x92,0x4b,0x49,0x9a,0x55,0xa0,0x8e,0xbe,0xa2,0x0c,0x6c,0x35,0x2f,0xb9,0xf0,0xa6}
};
    