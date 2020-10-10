// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <fstream>
#include "Globals.h"

FILE* stream;
FILE* g_log = NULL;
int g_safeToRun = 0;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	

	

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
#ifdef DEBUG_CONSOLE
		if (AllocConsole())
		{
			freopen_s(&stream, "CONOUT$", "w", stdout);
			SetConsoleTitle((L"DCS A-4 Debug Console"));
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
#endif

#ifdef LOGGING
		fopen_s(&g_log, "C:/tmp/log.txt", "w");
#endif
		g_safeToRun = isSafeContext();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
#ifdef LOGGING
		fclose(g_log);
#endif
		break;
	}
	return TRUE;
}

