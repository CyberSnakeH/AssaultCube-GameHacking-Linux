#include "ReadProcessMemory.h"
#include "Player.h"

int PlayerGetLocalInfo(Player *player, ulong Module, uint ProcId) {
    ulong BaseAddr;
    ReadProcessMemory(Module + LocalPlayerOffset, &BaseAddr, ProcId);
    ReadProcessMemory(BaseAddr + xPos, (ulong*)&(player->x), ProcId);
    ReadProcessMemory(BaseAddr + yPos, (ulong*)&(player->y), ProcId);
    ReadProcessMemory(BaseAddr + zPos, (ulong*)&(player->z), ProcId);

    return 1;
}

void PlayerDisplayCoordinates(Player *player) {
    printf("<LOCAL PLAYER POSISTION> : [%f, %f, %f]\n", player->x, player->y, player->z);
}