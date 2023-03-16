#include "../../src/dlopen.h"

int main()
{
    struct hotwire_dll_t dll = hw_dlopen("./bin/exampleWinLib.dll", 0);
}