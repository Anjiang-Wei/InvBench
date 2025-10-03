// This program implements a simple state machine for input sequence validation

#include <stdio.h>
#include <stdlib.h>

// Assertions for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "state_machine.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// State variables
int state = 0;
int flagA = 0;
int flagB = 0;
int value = 0;
int limit = 10;

// State transition function
int compute_next_state(int input) {
    if (state == 0) {
        if (input == 1) {
            state = 1;
            flagA = 1;
        } else if (input == 2) {
            state = 2;
            flagB = 1;
        }
    } else if (state == 1) {
        if (input == 3 && flagA) {
            state = 3;
            value += 5;
        } else if (input == 4) {
            state = 4;
            value -= 3;
        }
    } else if (state == 2) {
        if (input == 3 && flagB) {
            state = 3;
            value += 10;
        } else if (input == 5) {
            state = 4;
            value -= 5;
        }
    } else if (state == 3) {
        if (input == 6) {
            state = 4;
            value = 0; // Reset value
        }
    } else if (state == 4) {
        if (input == 1) {
            state = 0; // Return to initial state
        }
    }
    return state;
}

int main() {
    // Default loop counter
    int count = 0;

    // Loop to process inputs
    while (count < limit) {
        // Get nondeterministic input
        int input = __VERIFIER_nondet_int();
        if (input < 1 || input > 6) {
            continue; // Ignore invalid inputs
        }

        // Compute next state based on input
        int next_state = compute_next_state(input);

        // Verify some property
        __VERIFIER_assert(next_state <= 4);

        // Increment counter
        count++;
    }

    // Final verification

    return 0;
}