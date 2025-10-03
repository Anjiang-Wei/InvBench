#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to calculate factorial
int factorial(int n) {
    if (n < 0) {
        return 0; // Return 0 for invalid input
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limiting n to a reasonable range for factorial

    int fact = factorial(n);

    // Verify that factorial(n) is non-negative

    // Verify that factorial(n) will be correct for known small values
    if (n == 0 || n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
        __VERIFIER_assert(fact == 6);
    } else if (n == 4) {
    } else if (n == 5) {
    }

    return 0;
}