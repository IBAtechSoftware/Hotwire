#include "../../src/dlopen.h"

typedef void (*func_handle)();

int main()
{
    struct hotwire_dll_t dll = hw_dlopen("./bin/exampleUnixLib.dll", RTLD_NOW);

    func_handle func = (func_handle)hw_dlsym(dll, "test");

    func();
}