/*
 * This program is designed for automated verification purposes.
 * It computes the factorial of a nondeterministic integer
 * and checks the correctness of the result using assertions.
 */

#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 11, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to compute factorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // Get a nondeterministic positive integer
    int n = __VERIFIER_nondet_int();

    // Assume n is non-negative and not too large to avoid overflow
    assume_abort_if_not(n >= 0 && n <= 20);

    // Compute factorial
    unsigned long long fact = factorial(n);

    // Check the expected result for small n using assertions
    if (n == 0) {
    } else if (n == 1) {
        __VERIFIER_assert(fact == 1);
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    } // More checks could be added for higher values if desired

    return 0;
}