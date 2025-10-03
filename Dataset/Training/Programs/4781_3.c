#include <stdio.h>
#include <stdlib.h>

// External functions for verification purpose (mocked for this example)
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "traffic_light_controller.c", 5, "reach_error"); }

// Traffic light states enumeration
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

// Function to simulate traffic light transition
TrafficLightState next_state(TrafficLightState current, int timer) {
    if (timer <= 0) {
        return RED;
    }

    switch (current) {
    case RED:
        if (timer >= 5) {
            return GREEN;
        }
        break;
    case GREEN:
        if (timer >= 3) {
            return YELLOW;
        }
        break;
    case YELLOW:
        if (timer >= 2) {
            return RED;
        }
        break;
    }
    return current;
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    TrafficLightState state = RED;
    int timer = 0;

    // Main simulation loop for traffic light system
    for (int cycle = 0; cycle < 10; ++cycle) {
        timer = __VERIFIER_nondet_int();
        if (timer < 0 || timer > 10) {
            continue; // Skip invalid timer values
        }

        TrafficLightState next = next_state(state, timer);

        // Assert that the state transition is legal
        if (state == RED && next != RED && next != GREEN) {
        } else if (state == GREEN && next != GREEN && next != YELLOW) {
        } else if (state == YELLOW && next != YELLOW && next != RED) {
            __VERIFIER_assert(0);
        }

        // Update the state
        state = next;
    }

    return 0;
}