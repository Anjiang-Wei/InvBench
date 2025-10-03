// The program implements a simplified traffic light controller
// It simulates the cyclic behavior of traffic lights using a finite state machine.
// Each state represents a color of the traffic light: Green, Yellow, and Red.
// The transitions between states are modeled within the loop.
// The program ensures that each color change follows traffic light rules.

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} Light;

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern _Bool __VERIFIER_nondet_bool();

int main() {
    Light currentLight = RED;
    int timer = 0;
    int redDuration = 5;    // seconds the red light lasts
    int greenDuration = 4;  // seconds the green light lasts
    int yellowDuration = 2; // seconds the yellow light lasts

    while (1) {
        switch (currentLight) {
        case RED:
            if (timer == redDuration) {
                currentLight = GREEN;
                timer = 0;
            } else {
                // Simulate time passing
                timer++;
            }
            break;

        case GREEN:
            __VERIFIER_assert(timer <= greenDuration);
            if (timer == greenDuration) {
                currentLight = YELLOW;
                timer = 0;
            } else {
                // Simulate time passing
                timer++;
            }
            break;

        case YELLOW:
            if (timer == yellowDuration) {
                currentLight = RED;
                timer = 0;
            } else {
                // Simulate time passing
                timer++;
            }
            break;

        default:
            // Invalid state, should never reach here
            reach_error();
        }
    }

    return 0;
}