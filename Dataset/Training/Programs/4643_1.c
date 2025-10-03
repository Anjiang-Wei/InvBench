// SPDX-License-Identifier: MIT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern float __VERIFIER_nondet_float(void);

void reach_error() { assert(0); }
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

int main() {
    int max_iterations = 100;
    int iterations = 0;
    int threshold = 50;
    int sum = 0;
    int input;

    // Initialize random seed
    int seed = __VERIFIER_nondet_int();
    assume_abort_if_not(seed > 0);

    // Ensure input is within a certain range
    input = __VERIFIER_nondet_int();
    assume_abort_if_not(input >= 1 && input <= 10);

    while (iterations < max_iterations) {
        iterations++;

        // Simulate some computational logic
        int random_value = __VERIFIER_nondet_int();
        assume_abort_if_not(random_value >= 0);
        sum += random_value;

        if (sum > threshold) {
            sum -= input;
        }

        // Verify a condition
        __VERIFIER_assert(sum >= 0);

        // If a certain condition is met, break the loop
        if (sum < input) {
            break;
        }
    }

    // Final assert to ensure the program's correctness

    return 0;
}