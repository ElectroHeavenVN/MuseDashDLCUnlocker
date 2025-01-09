#include <Windows.h>
#include "MinHookMod/mhook.h"
#include "AetherimMod/api.hpp"
#include "AetherimMod/wrapper.hpp"

struct handle_data {
    unsigned long process_id;
    HWND window_handle;
};

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
    handle_data& data = *(handle_data*)lParam;
    unsigned long process_id = 0;
    GetWindowThreadProcessId(handle, &process_id);
    if (data.process_id != process_id || !(GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle)))
        return TRUE;
    data.window_handle = handle;
    return FALSE;
}

HWND FindMainWindow(unsigned long process_id)
{
    handle_data data = {};
    data.process_id = process_id;
    data.window_handle = 0;
    EnumWindows(EnumWindowsCallback, (LPARAM)&data);
    return data.window_handle;
}

static bool Steamworks_SteamApps__BIsDlcInstalled(unsigned int nAppID, const MethodInfo *method)
{
	return true;
}

static void Main() 
{
    while (!FindMainWindow(GetCurrentProcessId()))
        Sleep(50);
	Sleep(1000);
    MH_Initialize();
    Il2cpp::initialize();
    const auto il2cppImages = std::make_unique<Wrapper>();
	const auto steamworksDotNet = il2cppImages->get_image("com.rlabrecque.steamworks.net.dll");
	Il2CppMethodPointer Steamworks_SteamApps__BIsDlcInstalled_ptr = steamworksDotNet->get_class("SteamApps", "Steamworks")->get_method("BIsDlcInstalled", 1)->methodPointer;
    MH_CreateHook(reinterpret_cast<LPVOID*>(Steamworks_SteamApps__BIsDlcInstalled_ptr), &Steamworks_SteamApps__BIsDlcInstalled, nullptr);
    MH_EnableHook(MH_ALL_HOOKS);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
        break;
    case DLL_PROCESS_DETACH:
        MH_Uninitialize();
        FreeConsole();
        FreeLibraryAndExitThread(hModule, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }
    return TRUE;
}