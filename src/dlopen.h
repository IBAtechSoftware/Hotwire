#pragma once
#include <stdio.h>

#if defined(__APPLE__)
#include <dlfcn.h>
#endif

#if defined(__linux__)
#include <dlfcn.h>
#endif

#if defined(_WIN32)
#include <windows.h>
#include <strsafe.h>
#endif

// Platform specific code functions

#if defined(_WIN32)
void hw_platform_win32_get_last_error(LPTSTR lpszFunction);
#endif

enum hotwire_status_code { Failed, Success, NoPlatform };

struct hotwire_dll_t {
#if defined(__linux__) || defined(__APPLE__)
  void *dll_handle;
#endif

#if defined(_WIN32)
  HINSTANCE dll_handle;
#endif
};

// Function arguments are based off the dlopen() api on POSIX based operating
// systems Loads dll from library
struct hotwire_dll_t hw_dlopen(const char *file, int flags);

// Loads symbol from DLL
void *hw_dlsym(struct hotwire_dll_t dll, const char *symbol);

enum hotwire_status_code hw_dlclose(struct hotwire_dll_t handle);
