#include <assert.h>
#include <stdbool.h>

void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// This program finds the largest power of 2 less than or equal to a given number.
int main() {
    int n = __VERIFIER_nondet_int();
    int power = 1;

    // Assume n is a positive number
    if (n <= 0) {
        return 0;
    }

    // Double the power of 2 until it would exceed n
    while (power <= n / 2) {
        // Ensure power remains a power of 2
        __VERIFIER_assert((power & (power - 1)) == 0);
        power *= 2;
    }

    // Verify the largest power of 2 found is indeed less than or equal to n

    return 0;
}