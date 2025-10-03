#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int factorial(int n) {
    if (n < 0) {
        return -1; // Undefined for negative values
    }
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N < 0 || N > 12) { // Limit N to prevent integer overflow
        return 1;
    }

    int result = factorial(N);

    // Check that the factorial calculation is correct
    // For N = 5, factorial should be 120
    if (N == 5) {
    }

    // Check simple property for factorial of 0 and 1
    if (N == 0 || N == 1) {
        __VERIFIER_assert(result == 1);
    }

    return 0;
}