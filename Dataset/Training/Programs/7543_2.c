#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reach_error();
void assume_abort_if_not(int cond);
void __VERIFIER_assert(int cond);
int calculate_next_state(int current_state, int input);

// Error handling functions
void reach_error() {
    printf("Reach error\n");
    abort();
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Global variables
int state = 0;
int counter = 0;

// Function to determine the next state based on current state and input
int calculate_next_state(int current_state, int input) {
    int next_state = current_state;
    switch (current_state) {
    case 0:
        if (input == 1) {
            next_state = 1;
        } else if (input == 2) {
            next_state = 2;
        } else {
            next_state = 0;
        }
        break;
    case 1:
        if (input == 3) {
            next_state = 2;
        } else {
            next_state = 1;
        }
        break;
    case 2:
        if (input == 4) {
            next_state = 0;
        } else if (input == 5) {
            next_state = 1;
        } else {
            next_state = 2;
        }
        break;
    default:
        next_state = 0;
        break;
    }
    return next_state;
}

int main() {
    int output = -1;
    while (counter < 1000) {
        int input = rand() % 6 + 1; // Generate input between 1 and 6
        int prev_state = state;

        // Transitions based on state and input
        state = calculate_next_state(state, input);

        // Assertions to ensure correct state transitions
        if (prev_state == 0 && input == 1) {
        }
        if (prev_state == 0 && input == 2) {
            __VERIFIER_assert(state == 2);
        }
        if (prev_state == 1 && input == 3) {
        }
        if (prev_state == 2 && input == 4) {
        }
        if (prev_state == 2 && input == 5) {
        }

        printf("Current state: %d, Input: %d, Next state: %d\n", prev_state, input, state);

        counter++;
    }

    return 0;
}