#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Factorial Calculation with constraints
int main() {
    int n = __VERIFIER_nondet_int();
    long long factorial = 1;
    int i = 1;

    // Constraint: n should be a positive integer and not too large to avoid overflow
    if (n <= 0 || n >= 20) {
        printf("Input out of range. Exiting.\n");
        return 0;
    }

    // Loop to compute factorial
    for (i = 1; i <= n; i++) {
        factorial *= i;
    }

    // Check if factorial calculation is correct by comparing with pre-determined values
    if (n == 5) {
        __VERIFIER_assert(factorial == 120); // 5! = 120
    } else if (n == 10) {
        __VERIFIER_assert(factorial == 3628800); // 10! = 3628800
    } else if (n == 15) {
        __VERIFIER_assert(factorial == 1307674368000); // 15! = 1307674368000
    }

    printf("Factorial of %d is %lld\n", n, factorial);
    return 0;
}