#include <assert.h>
void reach_error(void) { assert(0); }

extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// New program proposal based on learned patterns:
// - Involves management of a sequence and ensures parity calculation holds through transformations
// - Uses a loop to modify and check an aspect of a sequence

int main() {
    unsigned int n, i, evens = 0, odds = 0;

    n = __VERIFIER_nondet_uint();

    if (n == 0) {
        return 0; // Ensure n is not zero for meaningful work
    }

    // Compute the sequence counts for initial conditions
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evens++;
        } else {
            odds++;
        }
    }

    // Ensure initial conditions hold true
    __VERIFIER_assert(evens + odds == n);

    // Transform the sequence while maintaining parity
    while (n > 0) {
        if (n % 2 == 0) {
            evens--;
        } else {
            odds--;
        }
        n--;
    }

    // Assert final conditions

    return 0;
}