#include "pch.h"
#include <Windows.h>
#include "Dumper.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule); // Optimalizace
        CreateThread(nullptr, 0, [](LPVOID) -> DWORD {
            Dumper dumper;
            if (dumper.Initialize()) {
                dumper.DumpAll(); // Spustí dumpování
            }
            FreeLibraryAndExitThread(GetModuleHandle(NULL), 0);
            return 0;
            }, nullptr, 0, nullptr);
    }
    return TRUE;
}