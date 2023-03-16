#pragma once
#include <stdio.h>

#if defined(__APPLE__)
#define HW_MODE 0
#include <dlfcn.h>
#endif

#if defined(__linux__)
#define HW_MODE 1
#include <dlfcn.h>
#endif

#if defined(_WIN32)
#define HW_MODE 2
#include <windows.h>
#endif


struct hotwire_dll_t {
    #if defined(__linux__) || defined(__APPLE__)
    void* dll_handle;
    #endif

    #if defined(_WIN32)
    HINSTANCE dll_handle;
    #endif
};

// Function arguments are based off the dlopen() api on POSIX based operating systems
// Loads dll from library
struct hotwire_dll_t hw_dlopen(const char* file, int flags);

// Loads symbol from DLL
inline void* hw_dlsym(struct hotwire_dll_t dll, const char *__restrict symbol);

inline int hw_dlclose(void* handle);
