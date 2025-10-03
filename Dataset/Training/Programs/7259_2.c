/*
 * This program implements a simulation of a simplified traffic light system at a
 * pedestrian crossing. It uses finite state machine principles to switch between
 * different states (Green, Yellow, Red) based on time intervals. The program includes
 * assertions to ensure state transitions occur correctly and validates time constraints.
 */

#include <stdio.h>
#include <stdlib.h>

#define GREEN_DURATION 5
#define YELLOW_DURATION 2
#define RED_DURATION 5

typedef enum {
    GREEN,
    YELLOW,
    RED
} TrafficLightState;

typedef struct {
    TrafficLightState state;
    int timer;
} TrafficLight;

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

TrafficLight *initialize_traffic_light() {
    TrafficLight *light = (TrafficLight *)malloc(sizeof(TrafficLight));
    if (light == NULL) {
        abort();
    }
    light->state = RED;
    light->timer = 0;
    return light;
}

void switch_state(TrafficLight *light) {
    switch (light->state) {
    case GREEN:
        light->state = YELLOW;
        light->timer = 0;
        break;
    case YELLOW:
        light->state = RED;
        light->timer = 0;
        break;
    case RED:
        light->state = GREEN;
        light->timer = 0;
        break;
    default:
        abort(); // Unexpected state
    }
}

void update_traffic_light(TrafficLight *light) {
    light->timer++;
    switch (light->state) {
    case GREEN:
        if (light->timer >= GREEN_DURATION) {
            switch_state(light);
        }
        break;
    case YELLOW:
        if (light->timer >= YELLOW_DURATION) {
            switch_state(light);
        }
        break;
    case RED:
        if (light->timer >= RED_DURATION) {
            switch_state(light);
        }
        break;
    default:
        abort(); // Unexpected state
    }
}

void simulate_traffic_light(int cycles) {
    TrafficLight *light = initialize_traffic_light();
    int cycle_count = 0;

    while (cycle_count < cycles) {
        update_traffic_light(light);

        // Debug: Print the current state and timer
        printf("State: %d, Timer: %d\n", light->state, light->timer);

        // Assertions to verify correct state durations
        switch (light->state) {
        case GREEN:
            break;
        case YELLOW:
            __VERIFIER_assert(light->timer <= YELLOW_DURATION);
            break;
        case RED:
            break;
        default:
            abort(); // Unexpected state
        }

        // Move to the next cycle after all states have been processed
        if (light->state == RED && light->timer == 0) {
            cycle_count++;
        }
    }

    free(light);
}

int main() {
    simulate_traffic_light(3);
    return 0;
}