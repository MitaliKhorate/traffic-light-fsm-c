#ifndef TRAFFIC_FSM_H
#define TRAFFIC_FSM_H

typedef enum {
    STATE_NS_GREEN = 0,
    STATE_NS_YELLOW,
    STATE_EW_GREEN,
    STATE_EW_YELLOW
} TrafficState;

typedef struct {
    TrafficState current_state;
    int state_timer;
} TrafficSystem;

void TrafficFSM_Init(TrafficSystem *system);
void TrafficFSM_Update(TrafficSystem *system);
void TrafficFSM_Display(const TrafficSystem *system);

#endif
