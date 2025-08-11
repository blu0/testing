// testdll.c
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        MessageBoxW(NULL, L"Injected via MavInject", L"Test DLL", MB_OK);
        HANDLE h = CreateFileW(L"C:\\Temp\\mavinject_test.txt", GENERIC_WRITE, FILE_SHARE_READ, NULL,
                               CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (h != INVALID_HANDLE_VALUE) {
            const char *msg = "Hello from injected DLL.\r\n";
            DWORD written = 0;
            WriteFile(h, msg, (DWORD)lstrlenA(msg), &written, NULL);
            CloseHandle(h);
        }
    }
    return TRUE;
}
