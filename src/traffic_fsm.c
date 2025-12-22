#include <stdio.h>
#include "traffic_fsm.h"
#include "../include/config.h"

void TrafficFSM_Init(TrafficSystem *system)
{
    system->current_state = STATE_NS_GREEN;
    system->state_timer   = NS_GREEN_TIME;
}

void TrafficFSM_Update(TrafficSystem *system)
{
    if (system->state_timer > 0) {
        system->state_timer--;
        return;
    }

    switch (system->current_state) {

    case STATE_NS_GREEN:
        system->current_state = STATE_NS_YELLOW;
        system->state_timer   = NS_YELLOW_TIME;
        break;

    case STATE_NS_YELLOW:
        system->current_state = STATE_EW_GREEN;
        system->state_timer   = EW_GREEN_TIME;
        break;

    case STATE_EW_GREEN:
        system->current_state = STATE_EW_YELLOW;
        system->state_timer   = EW_YELLOW_TIME;
        break;

    case STATE_EW_YELLOW:
        system->current_state = STATE_NS_GREEN;
        system->state_timer   = NS_GREEN_TIME;
        break;
    }
}

void TrafficFSM_Display(const TrafficSystem *system)
{
    switch (system->current_state) {

    case STATE_NS_GREEN:
        printf("NS: GREEN  | EW: RED\n");
        break;

    case STATE_NS_YELLOW:
        printf("NS: YELLOW | EW: RED\n");
        break;

    case STATE_EW_GREEN:
        printf("NS: RED    | EW: GREEN\n");
        break;

    case STATE_EW_YELLOW:
        printf("NS: RED    | EW: YELLOW\n");
        break;
    }
}
