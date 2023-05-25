#include "dlopen.h"
#include <stdlib.h>

struct hotwire_dll_t hw_dlopen(const char* file, int flags)
{

    struct hotwire_dll_t dll;

// UNIX specific code(MacOS uses the same API as linux for dlopen)
#if defined(__linux__) || defined(__APPLE__)
    dll.dll_handle = dlopen(file, flags);

    if (dll.dll_handle == NULL) {
        printf("Could not load dll(UNIX api call returned error)\n");
        printf("Error message: %s\n", dlerror());

        exit(-1);
    }
#endif

// Windows specific code
#if defined(_WIN32)
    dll.dll_handle = LoadLibrary(file);

    if (!dll.dll_handle) {
        printf("Could not load dll(Windows api call returned error)\n");
        hw_platform_win32_get_last_error(TEXT("LoadLibrary"));
        exit(-1);
    }
#endif

    return dll;
}

void* hw_dlsym(struct hotwire_dll_t dll, const char* symbol)
{
#if defined(_WIN32)
    return GetProcAddress(dll.dll_handle, symbol);
#endif

#if defined(__linux) || defined(__APPLE__)
    return dlsym(dll.dll_handle, symbol);
#endif
}

enum hotwire_status_code hw_dlclose(struct hotwire_dll_t handle)
{
#if defined(__linux) || defined(__APPLE__)
    if (dlclose(handle.dll_handle) != 0) {
        return Failed;
    }
    else {
        return Success;
    }
#endif

#if defined(__WIN32)
    if (FreeLibrary(handle.dll_handle)) {
        return Success;
    }
    else {
        return Failed;
    }
#endif

    return NoPlatform;
}

#if defined(_WIN32)
void hw_platform_win32_get_last_error(LPTSTR lpszFunction)
{
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf, 0, NULL);

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf, LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"), lpszFunction, dw,
        lpMsgBuf);

    printf("Error message: %s", (LPCTSTR)lpDisplayBuf);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
}

#endif
