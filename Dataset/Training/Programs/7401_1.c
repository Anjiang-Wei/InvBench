#include <assert.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Implement a function to calculate the factorial of a number non-deterministically
// and verify boundary conditions
int main() {
    int n = __VERIFIER_nondet_int();
    int i;
    long long factorial = 1;

    // Assume n must be a positive integer less than or equal to 12 (to prevent overflow in int)
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 12);

    for (i = 1; i <= n; i++) {
        factorial *= i;
    }

    // Verify the factorial result with known boundary conditions
    if (n == 0) {
        __VERIFIER_assert(factorial == 1); // 0! = 1
    }
    if (n == 1) {
        __VERIFIER_assert(factorial == 1); // 1! = 1
    }
    // Since we know n <= 12, factorial should always be a well known value
    if (n == 5) {
        __VERIFIER_assert(factorial == 120); // 5! = 120
    }

    return 0;
}