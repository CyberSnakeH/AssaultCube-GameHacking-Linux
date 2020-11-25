#ifndef GETPID_H
#define GETPID_H

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

#define BUFF 512

struct StockPid {
    pid_t pid;
    char buff[BUFF];
    char pidofbuff[BUFF];
    FILE *pid_pipe;

}stockthepid;

uint GetThePid(const char *targetprocess);

#endif