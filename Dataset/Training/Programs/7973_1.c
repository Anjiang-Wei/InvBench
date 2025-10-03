#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Computes the factorial of a number using an iterative approach
// The factorial of n (n!) is defined for non-negative integers as
// n! = 1 * 2 * 3 * ... * n, with 0! defined as 1.
int factorial(int n) {
    int result = 1;
    int i;

    for (i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Ensure non-deterministic input n is non-negative and sufficiently small to avoid overflow
    if (n < 0 || n > 12) {
        return 0;
    }

    // Calculate the factorial of 'n'
    int fact = factorial(n);

    // Check that the factorial has been computed correctly for n > 0
    int expected_result = 1;
    for (int j = 2; j <= n; j++) {
        expected_result *= j;
    }

    __VERIFIER_assert(fact == expected_result);

    return 0;
}