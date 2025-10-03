#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
 * Program to demonstrate a computation with state changes and bounds checking.
 * The program calculates a sequence with a termination condition when a certain
 * threshold is reached after performing a series of additions and multiplications.
 */
int main() {
    int threshold, increment, multiplier, counter, result;

    // Generate non-deterministic values.
    threshold = __VERIFIER_nondet_int();
    increment = __VERIFIER_nondet_int();
    multiplier = __VERIFIER_nondet_int();

    // Assumptions on inputs for meaningful computation.
    assume_abort_if_not(threshold > 0);
    assume_abort_if_not(increment > 0);
    assume_abort_if_not(multiplier > 1);

    result = 0;
    counter = 0;

    // Loop until result exceeds a given threshold.
    while (result < threshold) {
        // Perform some arbitrary computations.
        result = result * multiplier + increment;
        counter++;

        // Ensure the result does not wrap around or revert to non-positive values.
        __VERIFIER_assert(result >= 0);
    }

    // Final assertion that checks the termination condition has been met.

    return 0;
}