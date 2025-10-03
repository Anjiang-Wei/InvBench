#include <stdio.h>
#include <stdlib.h>

// Declare the reach_error function
extern void abort(void);
void reach_error() {
    printf("REACH_ERROR\n");
    abort();
}

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

// Define states
enum states { STATE_A,
              STATE_B,
              STATE_C,
              STATE_D };

// State variables
int state = STATE_A;
int counter = 0;
int limit = 15;
int input;

// Function to check current state and transition
void check_state(int input) {
    switch (state) {
    case STATE_A:
        if (input % 2 == 0) {
            state = STATE_B;
            counter++;
        }
        break;
    case STATE_B:
        if (input % 3 == 0) {
            state = STATE_C;
            counter += 2;
        } else {
            state = STATE_D;
            counter += 3;
        }
        break;
    case STATE_C:
        if (input % 5 == 0) {
            state = STATE_A;
            counter += 5;
        }
        break;
    case STATE_D:
        if (input % 7 == 0) {
            state = STATE_C;
            counter += 7;
        }
        break;
    default:
        reach_error();
        break;
    }
}

int main() {
    // Set initial input
    input = 1;

    // Main loop
    while (counter < limit) {
        // Simulate input
        input = rand() % 10 + 1; // Random input between 1 and 10

        // Check state and make transitions
        check_state(input);

        // Assert to verify the counter never exceeds twice the limit
        __VERIFIER_assert(counter <= 2 * limit);
    }

    // Final assertion to check if the final state is STATE_C

    return 0;
}