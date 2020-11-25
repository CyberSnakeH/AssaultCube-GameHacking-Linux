#include <stdio.h>

#include "types.h"
#include "get_pid.h"
#include "get_modulebase.h"
#include "ReadProcessMemory.h"
#include "WriteProcessMemory.h"
#include "Player.h"

int main(void) {
    uint ProcId;
    ulong GetModule;

    Player LocalPlayer;

    ProcId = GetThePid("ac_client");
    GetModule = GetModuleBase(ProcId, "ac_client");

    printf("Module is : %lx", GetModule);

    while (1 == 1) {
        PlayerGetLocalInfo(&LocalPlayer, GetModule, ProcId);
        PlayerDisplayCoordinates(&LocalPlayer);
        usleep(50*1000);
    }

    return 0;

}
    
    