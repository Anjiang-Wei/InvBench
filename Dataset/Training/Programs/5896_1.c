#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_and_square.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to compute factorial of a number
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, m;
    long long fact, square;

    // Input: Two nondeterministic integer values
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    // Assumptions on input values
    assume_abort_if_not(n >= 0 && n <= 10); // Restrict n to avoid large factorials
    assume_abort_if_not(m >= 0);            // m must be non-negative

    // Compute factorial of n
    fact = factorial(n);

    // Compute m^2 using iterative addition
    square = 0;
    for (int i = 0; i < m; i++) {
        square += m;
    }

    // Verification conditions
    __VERIFIER_assert(fact >= 1);   // Factorial of any n >= 0 is at least 1
    __VERIFIER_assert(square >= 0); // Square of any m should be non-negative

    printf("Factorial of %d is %lld\n", n, fact);
    printf("Square of %d is %lld\n", m, square);

    return 0;
}