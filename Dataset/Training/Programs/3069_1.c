// This program contains a simple computational task involving numeric sums.
// The goal is to simulate a simple computation where an invariant condition is to be ensured using a loop.
// The final sum needs to be cross-verified against an expected value.

#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    unsigned int i, n = 10; // set n to a fixed number for simplicity
    int sum = 0;

    // Populate the sum with the squares of numbers from 1 to n
    for (i = 1; i <= n; ++i) {
        sum += i * i;
    }

    // Calculate expected sum using n(n+1)(2n+1)/6 formula
    int expected_sum = (n * (n + 1) * (2 * n + 1)) / 6;

    // Verification of whether the computed and expected sums agree
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}