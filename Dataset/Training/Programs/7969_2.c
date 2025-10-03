// This is a C program designed for verification tasks.
// It simulates a simple traffic light control system with constraints.

#include <stdio.h>
#include <stdlib.h>

// External functions used for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "traffic_light.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

// Enum for traffic light states
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

// Traffic light control system
typedef struct {
    TrafficLightState state;
    int timer;
    int max_time;
} TrafficLight;

void update_traffic_light(TrafficLight *light) {
    switch (light->state) {
    case RED:
        if (light->timer >= light->max_time) {
            light->state = GREEN;
            light->timer = 0;
        } else {
            light->timer++;
        }
        break;
    case GREEN:
        if (light->timer >= light->max_time) {
            light->state = YELLOW;
            light->timer = 0;
        } else {
            light->timer++;
        }
        break;
    case YELLOW:
        if (light->timer >= light->max_time) {
            light->state = RED;
            light->timer = 0;
        } else {
            light->timer++;
        }
        break;
    default:
        reach_error();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    TrafficLight light;
    light.state = RED;
    light.timer = 0;
    light.max_time = 5;

    int counter = 0;
    while (counter++ < 20) { // Simulate for 20 time units
        update_traffic_light(&light);

        // Assert that the light remains valid

        // Assert that the timer never exceeds the max time
        __VERIFIER_assert(light.timer <= light.max_time);

        // Output the current state for verification
        printf("State: %d, Timer: %d\n", light.state, light.timer);
    }

    return 0;
}