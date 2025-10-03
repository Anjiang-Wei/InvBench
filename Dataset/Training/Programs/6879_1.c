#include <stdio.h>
#include <stdlib.h>

// Function to simulate an error if the condition fails
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "traffic_light_controller.c", 10, "reach_error"); }

// Function to simulate a nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

// Traffic light states
typedef enum { RED,
               GREEN,
               YELLOW } TrafficLightState;

// Function prototypes
void assume_abort_if_not(int cond);
void __VERIFIER_assert(int cond);
void change_light(TrafficLightState *state);
void simulate_traffic_light(int cycles);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Transition the traffic light to the next state
void change_light(TrafficLightState *state) {
    switch (*state) {
    case RED:
        *state = GREEN;
        break;
    case GREEN:
        *state = YELLOW;
        break;
    case YELLOW:
        *state = RED;
        break;
    }
}

// Simulate the traffic light system for a specified number of cycles
void simulate_traffic_light(int cycles) {
    assume_abort_if_not(cycles > 0);

    TrafficLightState state = RED;
    int i;
    for (i = 0; i < cycles; i++) {
        change_light(&state);
    }

    // Assert that the state transitions correctly after a full cycle
    __VERIFIER_assert((cycles % 3 == 0 && state == RED) ||
                      (cycles % 3 == 1 && state == GREEN) ||
                      (cycles % 3 == 2 && state == YELLOW));
}

int main() {
    int cycles = __VERIFIER_nondet_int();
    simulate_traffic_light(cycles);
    return 0;
}