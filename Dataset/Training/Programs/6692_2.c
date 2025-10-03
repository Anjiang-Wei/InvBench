// This file is designed as a verification task for automated tools
//
// SPDX-License-Identifier: MIT

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// State variables
int state_a = 1;
int state_b = 0;
int state_c = 3;
int state_d = 4;
int state_e = 2;

// Inputs
int input_x = 1;
int input_y = 2;
int input_z = 3;

// Outputs
int output_1 = 11;
int output_2 = 12;

// Function to determine the next output based on inputs and states
int determine_output(int input) {
    if ((state_a == 1) && ((input == 1 && state_b == 0) || (state_c == 3 && input == 2))) {
        state_b = 1;
        return output_1;
    } else if (state_d < 5 && (state_e > 1 && input == 3)) {
        state_a = 0;
        state_d = state_d + 1;
        return output_2;
    } else if ((state_a == 0) && ((input == 2 && state_c == 3))) {
        state_c = 4;
        return output_1 + output_2;
    }
    return -1;
}

int main() {
    int output = 0;
    int loop_count = 0;

    while (1) {
        // Simulate input
        int input = __VERIFIER_nondet_int();

        // Accept only specific inputs
        if ((input != 1) && (input != 2) && (input != 3)) {
            break;
        }

        // Compute output
        output = determine_output(input);

        // Check some properties
        __VERIFIER_assert(state_d <= 5);

        // Count iterations to prevent infinite loops in testing
        if (loop_count++ > 100) {
            break;
        }
    }

    return 0;
}