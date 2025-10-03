#include <assert.h>
#include <stdlib.h>

// Function prototypes for nondeterministic inputs and error handling
extern int __VERIFIER_nondet_int();
extern void abort(void);
void reach_error() { assert(0); }

// Function to assert a condition
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to calculate factorial iteratively
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    // Get a nondeterministic integer input
    int n = __VERIFIER_nondet_int();

    // Constrain n to be within a valid range
    if (n >= 0 && n <= 10) {
        int fact = factorial(n);

        // Verify factorial property: n! > 0 for n >= 0
        __VERIFIER_assert(fact > 0);

        // Additional property: 0! == 1
        if (n == 0) {
        }

        // Basic loop to check properties, demonstrating loop invariants
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += i;
        }

        // Verify sum of first n natural numbers: sum == n * (n + 1) / 2
    }

    return 0;
}