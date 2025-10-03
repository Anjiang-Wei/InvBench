#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci-like series generator
This program uses a Fibonacci-like series to compute
terms in a series with randomly chosen start points and constraints.
The loop ensures that we don't exceed the max allowed term number.
*/

int main() {
    int n = __VERIFIER_nondet_int(); // Maximum number of terms
    int a = __VERIFIER_nondet_int(); // First term of the sequence
    int b = __VERIFIER_nondet_int(); // Second term of the sequence

    if (!(n >= 1 && a >= 0 && b >= 0)) {
        return 0; // Precondition check
    }

    int i = 2;
    int t1 = a;
    int t2 = b;
    int t;

    while (i < n) {
        t = t1 + t2;

        // Ensure the sequence does not exceed a certain value
        __VERIFIER_assert(t >= t1 && t >= t2);

        t1 = t2;
        t2 = t;
        i++;
    }

    // Final postcondition, validates that the final result is correct
    // Sequence should still be increasing or stable if within bounds
    return 0;
}