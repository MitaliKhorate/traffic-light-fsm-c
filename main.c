#include <stdio.h>
#include <unistd.h>
#include "traffic_fsm.h"

int main(void)
{
    TrafficSystem system;

    TrafficFSM_Init(&system);

    while (1) {
        TrafficFSM_Display(&system);
        TrafficFSM_Update(&system);
        sleep(1);
    }

    return 0;
}
