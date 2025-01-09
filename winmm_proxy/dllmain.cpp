#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmiscapi.h>
#include <mmsystem.h>
#include <mmddk.h>
#include <stdio.h>

HMODULE winmm_dll;

#define WRAPPER_FUNC(name) o##name = GetProcAddress(winmm_dll, ###name)

#ifdef _M_AMD64
#pragma warning (disable: 4081)
#define STRINGIFY(name) #name
#define EXPORT_FUNCTION comment(linker, "/EXPORT:" __FUNCTION__ "=" __FUNCDNAME__)
#define WRAPPER_GENFUNC(name) \
    FARPROC o##name; \
    __declspec(dllexport) void WINAPI _##name() \
    { \
        __pragma(STRINGIFY(EXPORT_FUNCTION)); \
        o##name(); \
    }
#else
#define WRAPPER_GENFUNC(name) \
	FARPROC o##name; \
	__declspec(naked) void _##name() \
	{ \
		__asm jmp[o##name] \
	}
#endif

#pragma region Wrapper functions
WRAPPER_GENFUNC(WINMM_2);
WRAPPER_GENFUNC(CloseDriver);
WRAPPER_GENFUNC(DefDriverProc);
WRAPPER_GENFUNC(DriverCallback);
WRAPPER_GENFUNC(DrvGetModuleHandle);
WRAPPER_GENFUNC(GetDriverModuleHandle);
WRAPPER_GENFUNC(OpenDriver);
WRAPPER_GENFUNC(PlaySound);
WRAPPER_GENFUNC(PlaySoundA);
WRAPPER_GENFUNC(PlaySoundW);
WRAPPER_GENFUNC(SendDriverMessage);
WRAPPER_GENFUNC(WOWAppExit);
WRAPPER_GENFUNC(auxGetDevCapsA);
WRAPPER_GENFUNC(auxGetDevCapsW);
WRAPPER_GENFUNC(auxGetNumDevs);
WRAPPER_GENFUNC(auxGetVolume);
WRAPPER_GENFUNC(auxOutMessage);
WRAPPER_GENFUNC(auxSetVolume);
WRAPPER_GENFUNC(joyConfigChanged);
WRAPPER_GENFUNC(joyGetDevCapsA);
WRAPPER_GENFUNC(joyGetDevCapsW);
WRAPPER_GENFUNC(joyGetNumDevs);
WRAPPER_GENFUNC(joyGetPos);
WRAPPER_GENFUNC(joyGetPosEx);
WRAPPER_GENFUNC(joyGetThreshold);
WRAPPER_GENFUNC(joyReleaseCapture);
WRAPPER_GENFUNC(joySetCapture);
WRAPPER_GENFUNC(joySetThreshold);
WRAPPER_GENFUNC(mciDriverNotify);
WRAPPER_GENFUNC(mciDriverYield);
WRAPPER_GENFUNC(mciExecute);
WRAPPER_GENFUNC(mciFreeCommandResource);
WRAPPER_GENFUNC(mciGetCreatorTask);
WRAPPER_GENFUNC(mciGetDeviceIDA);
WRAPPER_GENFUNC(mciGetDeviceIDFromElementIDA);
WRAPPER_GENFUNC(mciGetDeviceIDFromElementIDW);
WRAPPER_GENFUNC(mciGetDeviceIDW);
WRAPPER_GENFUNC(mciGetDriverData);
WRAPPER_GENFUNC(mciGetErrorStringA);
WRAPPER_GENFUNC(mciGetErrorStringW);
WRAPPER_GENFUNC(mciGetYieldProc);
WRAPPER_GENFUNC(mciLoadCommandResource);
WRAPPER_GENFUNC(mciSendCommandA);
WRAPPER_GENFUNC(mciSendCommandW);
WRAPPER_GENFUNC(mciSendStringA);
WRAPPER_GENFUNC(mciSendStringW);
WRAPPER_GENFUNC(mciSetDriverData);
WRAPPER_GENFUNC(mciSetYieldProc);
WRAPPER_GENFUNC(midiConnect);
WRAPPER_GENFUNC(midiDisconnect);
WRAPPER_GENFUNC(midiInAddBuffer);
WRAPPER_GENFUNC(midiInClose);
WRAPPER_GENFUNC(midiInGetDevCapsA);
WRAPPER_GENFUNC(midiInGetDevCapsW);
WRAPPER_GENFUNC(midiInGetErrorTextA);
WRAPPER_GENFUNC(midiInGetErrorTextW);
WRAPPER_GENFUNC(midiInGetID);
WRAPPER_GENFUNC(midiInGetNumDevs);
WRAPPER_GENFUNC(midiInMessage);
WRAPPER_GENFUNC(midiInOpen);
WRAPPER_GENFUNC(midiInPrepareHeader);
WRAPPER_GENFUNC(midiInReset);
WRAPPER_GENFUNC(midiInStart);
WRAPPER_GENFUNC(midiInStop);
WRAPPER_GENFUNC(midiInUnprepareHeader);
WRAPPER_GENFUNC(midiOutCacheDrumPatches);
WRAPPER_GENFUNC(midiOutCachePatches);
WRAPPER_GENFUNC(midiOutClose);
WRAPPER_GENFUNC(midiOutGetDevCapsA);
WRAPPER_GENFUNC(midiOutGetDevCapsW);
WRAPPER_GENFUNC(midiOutGetErrorTextA);
WRAPPER_GENFUNC(midiOutGetErrorTextW);
WRAPPER_GENFUNC(midiOutGetID);
WRAPPER_GENFUNC(midiOutGetNumDevs);
WRAPPER_GENFUNC(midiOutGetVolume);
WRAPPER_GENFUNC(midiOutLongMsg);
WRAPPER_GENFUNC(midiOutMessage);
WRAPPER_GENFUNC(midiOutOpen);
WRAPPER_GENFUNC(midiOutPrepareHeader);
WRAPPER_GENFUNC(midiOutReset);
WRAPPER_GENFUNC(midiOutSetVolume);
WRAPPER_GENFUNC(midiOutShortMsg);
WRAPPER_GENFUNC(midiOutUnprepareHeader);
WRAPPER_GENFUNC(midiStreamClose);
WRAPPER_GENFUNC(midiStreamOpen);
WRAPPER_GENFUNC(midiStreamOut);
WRAPPER_GENFUNC(midiStreamPause);
WRAPPER_GENFUNC(midiStreamPosition);
WRAPPER_GENFUNC(midiStreamProperty);
WRAPPER_GENFUNC(midiStreamRestart);
WRAPPER_GENFUNC(midiStreamStop);
WRAPPER_GENFUNC(mixerClose);
WRAPPER_GENFUNC(mixerGetControlDetailsA);
WRAPPER_GENFUNC(mixerGetControlDetailsW);
WRAPPER_GENFUNC(mixerGetDevCapsA);
WRAPPER_GENFUNC(mixerGetDevCapsW);
WRAPPER_GENFUNC(mixerGetID);
WRAPPER_GENFUNC(mixerGetLineControlsA);
WRAPPER_GENFUNC(mixerGetLineControlsW);
WRAPPER_GENFUNC(mixerGetLineInfoA);
WRAPPER_GENFUNC(mixerGetLineInfoW);
WRAPPER_GENFUNC(mixerGetNumDevs);
WRAPPER_GENFUNC(mixerMessage);
WRAPPER_GENFUNC(mixerOpen);
WRAPPER_GENFUNC(mixerSetControlDetails);
WRAPPER_GENFUNC(mmDrvInstall);
WRAPPER_GENFUNC(mmGetCurrentTask);
WRAPPER_GENFUNC(mmTaskBlock);
WRAPPER_GENFUNC(mmTaskCreate);
WRAPPER_GENFUNC(mmTaskSignal);
WRAPPER_GENFUNC(mmTaskYield);
WRAPPER_GENFUNC(mmioAdvance);
WRAPPER_GENFUNC(mmioAscend);
WRAPPER_GENFUNC(mmioClose);
WRAPPER_GENFUNC(mmioCreateChunk);
WRAPPER_GENFUNC(mmioDescend);
WRAPPER_GENFUNC(mmioFlush);
WRAPPER_GENFUNC(mmioGetInfo);
WRAPPER_GENFUNC(mmioInstallIOProcA);
WRAPPER_GENFUNC(mmioInstallIOProcW);
WRAPPER_GENFUNC(mmioOpenA);
WRAPPER_GENFUNC(mmioOpenW);
WRAPPER_GENFUNC(mmioRead);
WRAPPER_GENFUNC(mmioRenameA);
WRAPPER_GENFUNC(mmioRenameW);
WRAPPER_GENFUNC(mmioSeek);
WRAPPER_GENFUNC(mmioSendMessage);
WRAPPER_GENFUNC(mmioSetBuffer);
WRAPPER_GENFUNC(mmioSetInfo);
WRAPPER_GENFUNC(mmioStringToFOURCCA);
WRAPPER_GENFUNC(mmioStringToFOURCCW);
WRAPPER_GENFUNC(mmioWrite);
WRAPPER_GENFUNC(mmsystemGetVersion);
WRAPPER_GENFUNC(sndPlaySoundA);
WRAPPER_GENFUNC(sndPlaySoundW);
WRAPPER_GENFUNC(timeBeginPeriod);
WRAPPER_GENFUNC(timeEndPeriod);
WRAPPER_GENFUNC(timeGetDevCaps);
WRAPPER_GENFUNC(timeGetSystemTime);
WRAPPER_GENFUNC(timeGetTime);
WRAPPER_GENFUNC(timeKillEvent);
WRAPPER_GENFUNC(timeSetEvent);
WRAPPER_GENFUNC(waveInAddBuffer);
WRAPPER_GENFUNC(waveInClose);
WRAPPER_GENFUNC(waveInGetDevCapsA);
WRAPPER_GENFUNC(waveInGetDevCapsW);
WRAPPER_GENFUNC(waveInGetErrorTextA);
WRAPPER_GENFUNC(waveInGetErrorTextW);
WRAPPER_GENFUNC(waveInGetID);
WRAPPER_GENFUNC(waveInGetNumDevs);
WRAPPER_GENFUNC(waveInGetPosition);
WRAPPER_GENFUNC(waveInMessage);
WRAPPER_GENFUNC(waveInOpen);
WRAPPER_GENFUNC(waveInPrepareHeader);
WRAPPER_GENFUNC(waveInReset);
WRAPPER_GENFUNC(waveInStart);
WRAPPER_GENFUNC(waveInStop);
WRAPPER_GENFUNC(waveInUnprepareHeader);
WRAPPER_GENFUNC(waveOutBreakLoop);
WRAPPER_GENFUNC(waveOutClose);
WRAPPER_GENFUNC(waveOutGetDevCapsA);
WRAPPER_GENFUNC(waveOutGetDevCapsW);
WRAPPER_GENFUNC(waveOutGetErrorTextA);
WRAPPER_GENFUNC(waveOutGetErrorTextW);
WRAPPER_GENFUNC(waveOutGetID);
WRAPPER_GENFUNC(waveOutGetNumDevs);
WRAPPER_GENFUNC(waveOutGetPitch);
WRAPPER_GENFUNC(waveOutGetPlaybackRate);
WRAPPER_GENFUNC(waveOutGetPosition);
WRAPPER_GENFUNC(waveOutGetVolume);
WRAPPER_GENFUNC(waveOutMessage);
WRAPPER_GENFUNC(waveOutOpen);
WRAPPER_GENFUNC(waveOutPause);
WRAPPER_GENFUNC(waveOutPrepareHeader);
WRAPPER_GENFUNC(waveOutReset);
WRAPPER_GENFUNC(waveOutRestart);
WRAPPER_GENFUNC(waveOutSetPitch);
WRAPPER_GENFUNC(waveOutSetPlaybackRate);
WRAPPER_GENFUNC(waveOutSetVolume);
WRAPPER_GENFUNC(waveOutUnprepareHeader);
WRAPPER_GENFUNC(waveOutWrite);
#pragma endregion

char* stristr(char* str, const char* subStr) {
	int len = strlen(subStr);
	while (*str) {
		if (!_strnicmp(str, subStr, len))
			return str;
		str++;
	}
	return NULL;
}

DWORD WINAPI Load(LPVOID lpParam) {
	char systemPath[MAX_PATH];
	GetSystemDirectoryA(systemPath, MAX_PATH);
	strcat_s(systemPath, "\\winmm.dll");
	winmm_dll = LoadLibraryA(systemPath);
	if (!winmm_dll)
		return 0;

#pragma region Wrap functions
	WRAPPER_FUNC(WINMM_2);
	WRAPPER_FUNC(CloseDriver);
	WRAPPER_FUNC(DefDriverProc);
	WRAPPER_FUNC(DriverCallback);
	WRAPPER_FUNC(DrvGetModuleHandle);
	WRAPPER_FUNC(GetDriverModuleHandle);
	WRAPPER_FUNC(OpenDriver);
	WRAPPER_FUNC(PlaySound);
	WRAPPER_FUNC(PlaySoundA);
	WRAPPER_FUNC(PlaySoundW);
	WRAPPER_FUNC(SendDriverMessage);
	WRAPPER_FUNC(WOWAppExit);
	WRAPPER_FUNC(auxGetDevCapsA);
	WRAPPER_FUNC(auxGetDevCapsW);
	WRAPPER_FUNC(auxGetNumDevs);
	WRAPPER_FUNC(auxGetVolume);
	WRAPPER_FUNC(auxOutMessage);
	WRAPPER_FUNC(auxSetVolume);
	WRAPPER_FUNC(joyConfigChanged);
	WRAPPER_FUNC(joyGetDevCapsA);
	WRAPPER_FUNC(joyGetDevCapsW);
	WRAPPER_FUNC(joyGetNumDevs);
	WRAPPER_FUNC(joyGetPos);
	WRAPPER_FUNC(joyGetPosEx);
	WRAPPER_FUNC(joyGetThreshold);
	WRAPPER_FUNC(joyReleaseCapture);
	WRAPPER_FUNC(joySetCapture);
	WRAPPER_FUNC(joySetThreshold);
	WRAPPER_FUNC(mciDriverNotify);
	WRAPPER_FUNC(mciDriverYield);
	WRAPPER_FUNC(mciExecute);
	WRAPPER_FUNC(mciFreeCommandResource);
	WRAPPER_FUNC(mciGetCreatorTask);
	WRAPPER_FUNC(mciGetDeviceIDA);
	WRAPPER_FUNC(mciGetDeviceIDFromElementIDA);
	WRAPPER_FUNC(mciGetDeviceIDFromElementIDW);
	WRAPPER_FUNC(mciGetDeviceIDW);
	WRAPPER_FUNC(mciGetDriverData);
	WRAPPER_FUNC(mciGetErrorStringA);
	WRAPPER_FUNC(mciGetErrorStringW);
	WRAPPER_FUNC(mciGetYieldProc);
	WRAPPER_FUNC(mciLoadCommandResource);
	WRAPPER_FUNC(mciSendCommandA);
	WRAPPER_FUNC(mciSendCommandW);
	WRAPPER_FUNC(mciSendStringA);
	WRAPPER_FUNC(mciSendStringW);
	WRAPPER_FUNC(mciSetDriverData);
	WRAPPER_FUNC(mciSetYieldProc);
	WRAPPER_FUNC(midiConnect);
	WRAPPER_FUNC(midiDisconnect);
	WRAPPER_FUNC(midiInAddBuffer);
	WRAPPER_FUNC(midiInClose);
	WRAPPER_FUNC(midiInGetDevCapsA);
	WRAPPER_FUNC(midiInGetDevCapsW);
	WRAPPER_FUNC(midiInGetErrorTextA);
	WRAPPER_FUNC(midiInGetErrorTextW);
	WRAPPER_FUNC(midiInGetID);
	WRAPPER_FUNC(midiInGetNumDevs);
	WRAPPER_FUNC(midiInMessage);
	WRAPPER_FUNC(midiInOpen);
	WRAPPER_FUNC(midiInPrepareHeader);
	WRAPPER_FUNC(midiInReset);
	WRAPPER_FUNC(midiInStart);
	WRAPPER_FUNC(midiInStop);
	WRAPPER_FUNC(midiInUnprepareHeader);
	WRAPPER_FUNC(midiOutCacheDrumPatches);
	WRAPPER_FUNC(midiOutCachePatches);
	WRAPPER_FUNC(midiOutClose);
	WRAPPER_FUNC(midiOutGetDevCapsA);
	WRAPPER_FUNC(midiOutGetDevCapsW);
	WRAPPER_FUNC(midiOutGetErrorTextA);
	WRAPPER_FUNC(midiOutGetErrorTextW);
	WRAPPER_FUNC(midiOutGetID);
	WRAPPER_FUNC(midiOutGetNumDevs);
	WRAPPER_FUNC(midiOutGetVolume);
	WRAPPER_FUNC(midiOutLongMsg);
	WRAPPER_FUNC(midiOutMessage);
	WRAPPER_FUNC(midiOutOpen);
	WRAPPER_FUNC(midiOutPrepareHeader);
	WRAPPER_FUNC(midiOutReset);
	WRAPPER_FUNC(midiOutSetVolume);
	WRAPPER_FUNC(midiOutShortMsg);
	WRAPPER_FUNC(midiOutUnprepareHeader);
	WRAPPER_FUNC(midiStreamClose);
	WRAPPER_FUNC(midiStreamOpen);
	WRAPPER_FUNC(midiStreamOut);
	WRAPPER_FUNC(midiStreamPause);
	WRAPPER_FUNC(midiStreamPosition);
	WRAPPER_FUNC(midiStreamProperty);
	WRAPPER_FUNC(midiStreamRestart);
	WRAPPER_FUNC(midiStreamStop);
	WRAPPER_FUNC(mixerClose);
	WRAPPER_FUNC(mixerGetControlDetailsA);
	WRAPPER_FUNC(mixerGetControlDetailsW);
	WRAPPER_FUNC(mixerGetDevCapsA);
	WRAPPER_FUNC(mixerGetDevCapsW);
	WRAPPER_FUNC(mixerGetID);
	WRAPPER_FUNC(mixerGetLineControlsA);
	WRAPPER_FUNC(mixerGetLineControlsW);
	WRAPPER_FUNC(mixerGetLineInfoA);
	WRAPPER_FUNC(mixerGetLineInfoW);
	WRAPPER_FUNC(mixerGetNumDevs);
	WRAPPER_FUNC(mixerMessage);
	WRAPPER_FUNC(mixerOpen);
	WRAPPER_FUNC(mixerSetControlDetails);
	WRAPPER_FUNC(mmDrvInstall);
	WRAPPER_FUNC(mmGetCurrentTask);
	WRAPPER_FUNC(mmTaskBlock);
	WRAPPER_FUNC(mmTaskCreate);
	WRAPPER_FUNC(mmTaskSignal);
	WRAPPER_FUNC(mmTaskYield);
	WRAPPER_FUNC(mmioAdvance);
	WRAPPER_FUNC(mmioAscend);
	WRAPPER_FUNC(mmioClose);
	WRAPPER_FUNC(mmioCreateChunk);
	WRAPPER_FUNC(mmioDescend);
	WRAPPER_FUNC(mmioFlush);
	WRAPPER_FUNC(mmioGetInfo);
	WRAPPER_FUNC(mmioInstallIOProcA);
	WRAPPER_FUNC(mmioInstallIOProcW);
	WRAPPER_FUNC(mmioOpenA);
	WRAPPER_FUNC(mmioOpenW);
	WRAPPER_FUNC(mmioRead);
	WRAPPER_FUNC(mmioRenameA);
	WRAPPER_FUNC(mmioRenameW);
	WRAPPER_FUNC(mmioSeek);
	WRAPPER_FUNC(mmioSendMessage);
	WRAPPER_FUNC(mmioSetBuffer);
	WRAPPER_FUNC(mmioSetInfo);
	WRAPPER_FUNC(mmioStringToFOURCCA);
	WRAPPER_FUNC(mmioStringToFOURCCW);
	WRAPPER_FUNC(mmioWrite);
	WRAPPER_FUNC(mmsystemGetVersion);
	WRAPPER_FUNC(sndPlaySoundA);
	WRAPPER_FUNC(sndPlaySoundW);
	WRAPPER_FUNC(timeBeginPeriod);
	WRAPPER_FUNC(timeEndPeriod);
	WRAPPER_FUNC(timeGetDevCaps);
	WRAPPER_FUNC(timeGetSystemTime);
	WRAPPER_FUNC(timeGetTime);
	WRAPPER_FUNC(timeKillEvent);
	WRAPPER_FUNC(timeSetEvent);
	WRAPPER_FUNC(waveInAddBuffer);
	WRAPPER_FUNC(waveInClose);
	WRAPPER_FUNC(waveInGetDevCapsA);
	WRAPPER_FUNC(waveInGetDevCapsW);
	WRAPPER_FUNC(waveInGetErrorTextA);
	WRAPPER_FUNC(waveInGetErrorTextW);
	WRAPPER_FUNC(waveInGetID);
	WRAPPER_FUNC(waveInGetNumDevs);
	WRAPPER_FUNC(waveInGetPosition);
	WRAPPER_FUNC(waveInMessage);
	WRAPPER_FUNC(waveInOpen);
	WRAPPER_FUNC(waveInPrepareHeader);
	WRAPPER_FUNC(waveInReset);
	WRAPPER_FUNC(waveInStart);
	WRAPPER_FUNC(waveInStop);
	WRAPPER_FUNC(waveInUnprepareHeader);
	WRAPPER_FUNC(waveOutBreakLoop);
	WRAPPER_FUNC(waveOutClose);
	WRAPPER_FUNC(waveOutGetDevCapsA);
	WRAPPER_FUNC(waveOutGetDevCapsW);
	WRAPPER_FUNC(waveOutGetErrorTextA);
	WRAPPER_FUNC(waveOutGetErrorTextW);
	WRAPPER_FUNC(waveOutGetID);
	WRAPPER_FUNC(waveOutGetNumDevs);
	WRAPPER_FUNC(waveOutGetPitch);
	WRAPPER_FUNC(waveOutGetPlaybackRate);
	WRAPPER_FUNC(waveOutGetPosition);
	WRAPPER_FUNC(waveOutGetVolume);
	WRAPPER_FUNC(waveOutMessage);
	WRAPPER_FUNC(waveOutOpen);
	WRAPPER_FUNC(waveOutPause);
	WRAPPER_FUNC(waveOutPrepareHeader);
	WRAPPER_FUNC(waveOutReset);
	WRAPPER_FUNC(waveOutRestart);
	WRAPPER_FUNC(waveOutSetPitch);
	WRAPPER_FUNC(waveOutSetPlaybackRate);
	WRAPPER_FUNC(waveOutSetVolume);
	WRAPPER_FUNC(waveOutUnprepareHeader);
	WRAPPER_FUNC(waveOutWrite);
#pragma endregion

	char szFileName[MAX_PATH];
	GetModuleFileNameA(NULL, szFileName, MAX_PATH);
	if (stristr(szFileName, "MuseDash.exe"))
	{
		while (GetModuleHandleA("GameAssembly.dll") == nullptr)
			Sleep(50);
		LoadLibraryA("MuseDashDLCUnlocker.dll");
	}
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Load, hModule, NULL, NULL);
        break;
    case DLL_PROCESS_DETACH:
        FreeLibrary(winmm_dll);
        break;
    }
    return TRUE;
}
