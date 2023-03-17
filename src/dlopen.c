#include "dlopen.h"
#include <stdlib.h>

struct hotwire_dll_t hw_dlopen(const char *file, int flags) {

  struct hotwire_dll_t dll;

// UNIX specific code(MacOS uses the same API as linux for dlopen)
#if defined(__linux__) || defined(__APPLE__)
  dll.dll_handle = dlopen(file, flags);

  if (dll.dll_handle == NULL){
    printf("could not load dll(UNIX api call returned error)\n");
    printf("error message: %s\n", dlerror());

    exit(-1);
  }
#endif

// Windows specific code
#if defined(_WIN32)
  dll.dll_handle = LoadLibrary(file);

  if (!dll.dll_handle){
    printf("could not load dll(windows api call returned error)\n");
    
    exit(-1);
  }
#endif

  return dll;
}

void* hw_dlsym(struct hotwire_dll_t dll, const char* symbol){
  #if defined(_WIN32)
    return GetProcAddress(dll.dll_handle, symbol);
  #endif

  #if defined(__linux) || defined(__APPLE__)
    return dlsym(dll.dll_handle, symbol);
  #endif
}