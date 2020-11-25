#ifndef RPM
#define RPM

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

#include "types.h"

#define MaxSize 1024
#define InitMem 0

int ReadProcessMemory(ulong addr, ulong *tmp, uint pid);

#endif