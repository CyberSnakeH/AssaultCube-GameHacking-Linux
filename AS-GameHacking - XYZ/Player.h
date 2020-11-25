#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

#define LocalPlayerOffset 0x19A0F0

#define xPos 0x38
#define yPos 0x3C
#define zPos 0x40

typedef struct {
    float x;
    float y;
    float z;
} Player;

int PlayerGetLocalInfo(Player *player, ulong Module, uint ProcId);
void PlayerDisplayCoordinates(Player *player);

#endif