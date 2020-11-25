#include <stdio.h>
#include <string.h>

#include "get_modulebase.h"
#include "get_pid.h"
#include "types.h"

ulong GetModuleBase(uint pid, const char *module) {
    memset(get_modulebaseaddr.FileMaps, InitMem, MaxSize);
    memset(get_modulebaseaddr.Line, InitMem, MaxSize);
    memset(get_modulebaseaddr.GetFirstLine, InitMem, GetFirstLineSize);

    sprintf(get_modulebaseaddr.FileMaps, "/proc/%d/maps", stockthepid.pid);
    sprintf(get_modulebaseaddr.RealModule, "/%s", module);

    get_modulebaseaddr.GetModuleBaseAddrFile = fopen(get_modulebaseaddr.FileMaps, "r");

    if (get_modulebaseaddr.GetModuleBaseAddrFile != NULL) {
        while(fgets(get_modulebaseaddr.Line, MaxSize, get_modulebaseaddr.GetModuleBaseAddrFile)) {
            if(strstr(get_modulebaseaddr.Line, get_modulebaseaddr.RealModule)) {
                strncpy(get_modulebaseaddr.GetFirstLine, get_modulebaseaddr.Line, AddrOffset);
                get_modulebaseaddr.ConvertModule = strtoul(get_modulebaseaddr.GetFirstLine, NULL, 16);
                break;
            }
        }
    }
    fclose(get_modulebaseaddr.GetModuleBaseAddrFile);
    return get_modulebaseaddr.ConvertModule;
}