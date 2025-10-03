// Program to compute the maximum k such that k^2 + k <= n
// ensuring correct behavior via checks using assertions

#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int n, k, sum, incr;

    n = __VERIFIER_nondet_int();

    // Assumptions on n (for verification purposes, it should be non-negative)
    if (n < 0) {
        return 0;
    }

    k = 0;
    sum = 0;
    incr = 1;

    while (1) {
        // Assert that sum will always be less or equal to n when it enters the loop

        if (sum > n) {
            break;
        }

        k = k + 1;
        sum = k * k + k;
        incr = incr + 2;
    }

    // Check that the sum exceeds n
    // This serves as our verification for the condition that sum shouldn't be <= n after the loop

    // k - 1 should be the correct maximum satisfying the condition
    __VERIFIER_assert((k - 1) * (k - 1) + (k - 1) <= n);

    return 0;
}