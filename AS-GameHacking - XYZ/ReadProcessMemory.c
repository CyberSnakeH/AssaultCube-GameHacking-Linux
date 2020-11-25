#include <stdio.h>
#include "ReadProcessMemory.h"

int ReadProcessMemory(ulong addr, ulong *tmp, uint pid) {
    long ret;

    int err_code = ptrace(PTRACE_ATTACH, pid, NULL, NULL);

    if (err_code == -1) {
        printf("Error we can't attach the process ! \n");
        return -1;
    }

    usleep(1000);

    ret = ptrace(PTRACE_PEEKDATA, pid, addr, NULL);

    if (ret == -1) {
        printf("Error we can't peak data \n");
        return -1;
    }

    err_code = ptrace(PTRACE_DETACH, pid, NULL, NULL);

    if (err_code == -1) {
        printf("Error we can't dettach the process ! \n");
        return -1;
    }

    *tmp = ret;

    return 1;
}