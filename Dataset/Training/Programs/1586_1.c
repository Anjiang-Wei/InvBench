#include <assert.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

/*
Fibonacci-like Series
This program generates a series similar to the Fibonacci sequence.
It verifies the absolute difference between two consecutive terms is less than or equal to the next term.
*/

int main() {
    int prev1 = 0, prev2 = 1, current, n = __VERIFIER_nondet_int();
    if (n < 2) {
        return 0; // Base case, no series to compute.
    }

    int counter = 2; // Starting with two terms already defined: prev1 and prev2.

    while (counter < n) {
        current = prev1 + prev2; // Basic Fibonacci computation.

        // Verify the relation between the terms in the series
        __VERIFIER_assert(abs(prev2 - prev1) <= current);

        // Shuffle the series
        prev1 = prev2;
        prev2 = current;
        counter++;
    }

    return 0;
}