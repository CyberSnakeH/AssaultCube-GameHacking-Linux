#ifndef MODULE_BASE
#define MODULE_BASE

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

#define MaxSize             1024
#define GetFirstLineSize    13
#define AddrOffset          12
#define InitMem             0

struct get_modulebase {
    char FileMaps[MaxSize];
    char Line[MaxSize];
    char GetFirstLine[GetFirstLineSize];
    char RealModule[AddrOffset];

    ulong ConvertModule;

    FILE *GetModuleBaseAddrFile;
}get_modulebaseaddr;

ulong GetModuleBase(uint pid, const char *module);

#endif