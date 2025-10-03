#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function prototypes
int calculate_output(int input, int *state);

// Global state variables
int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;

int calculate_output(int input, int *state) {
    int local_state = *state;
    if (local_state == 0) {
        if (input == 2) {
            local_state = 1;
        } else if (input == 3) {
            local_state = 2;
        }
    } else if (local_state == 1) {
        if (input == 4) {
            local_state = 3;
        } else if (input == 5) {
            local_state = 0;
        }
    } else if (local_state == 2) {
        if (input == 6) {
            local_state = 0;
        } else if (input == 1) {
            local_state = 3;
        }
    } else {
        if (input == 1) {
            local_state = 1;
        } else if (input == 2) {
            local_state = 2;
        }
    }

    *state = local_state;
    return local_state;
}

int main() {
    // Default output
    int output = -1;

    // State initialization
    int state = 0;

    // Main input-output loop
    while (1) {
        // Read input
        int input = __VERIFIER_nondet_int();
        if ((input < 1) || (input > 6)) {
            continue;
        }

        // Compute next state
        output = calculate_output(input, &state);

        // Constraint conditions
        if (state == 3) {
            assume_abort_if_not(output == 3);
        } else {
            __VERIFIER_assert(output != 3);
        }
    }

    return 0;
}