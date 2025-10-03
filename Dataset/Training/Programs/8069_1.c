#include <stdlib.h>

void reach_error(void) { exit(1); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
The program verifies that the sum of a sequence of integers starting
from a given non-negative integer is greater than or equal to the
initial number, provided the increments are non-negative.
*/

int main(void) {
    int start = __VERIFIER_nondet_int();
    if (start < 0) {
        return 0; // ensure start is non-negative
    }

    int limit = __VERIFIER_nondet_int();
    if (limit <= start) {
        return 0; // ensure limit is greater than start
    }

    int sum = start;
    int x = start;

    while (x < limit) {
        // Each step adds a non-negative number
        int increment = __VERIFIER_nondet_int();
        if (increment < 0) {
            break; // end the loop if a negative increment is encountered
        }

        x += increment;
        sum += increment;
    }

    __VERIFIER_assert(sum >= start); // ensure that sum is never less than start
    return 0;
}