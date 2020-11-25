#include <stdio.h>
#include "get_pid.h"

uint GetThePid(const char *targetprocess) {
    sprintf(stockthepid.pidofbuff, "pidof -s %s", targetprocess);
    stockthepid.pid_pipe = popen(stockthepid.pidofbuff, "r");
    char *ppp = fgets(stockthepid.buff, BUFF, stockthepid.pid_pipe);
    stockthepid.pid = strtoul(stockthepid.buff, NULL, 10);

    if (stockthepid.pid == 0) {
        printf("App is not launch ! \n");
        pclose(stockthepid.pid_pipe);
        exit(-1);
    } else {
        pclose(stockthepid.pid_pipe);
    }

    return stockthepid.pid;
}