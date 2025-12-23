#ifndef TRAFFIC_FSM_H
#define TRAFFIC_FSM_H

typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficState;

typedef enum {
    TIMER_EXPIRED
} Event;

/* FSM interface */
void traffic_fsm_init(void);
void traffic_fsm_handle_event(Event event);
TrafficState traffic_fsm_get_state(void);
const char* traffic_fsm_get_state_name(void);

#endif
