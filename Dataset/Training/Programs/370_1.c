#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0;
    }

    int factor = 1;
    int factorial = 1;
    int prev_factorial = 1;

    while (factor <= n) {
        prev_factorial = factorial; // Store previous factorial before multiplication to check overflow
        factorial *= factor;

        // Verifying no overflow occurred
        if (factor != 0 && prev_factorial != 0) {
            __VERIFIER_assert(factorial / factor == prev_factorial);
        }

        factor++;
    }

    // A simple constraint check
    if (n >= 5) {
    }

    return 0;
}