// Fibonacci Series Assertion

/*
 * This program computes the Fibonacci series up to a certain number 'n'.
 * It checks at each step that the calculated value matches the
 * expected value using pre-computed constants for small values.
 * The process is controlled through `c` which dictates the number of
 * iterations or steps for computing Fibonacci sequence.
 */

#include <stdio.h>
#include <stdlib.h>

// Function prototypes for verification tools, similar to provided examples
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 20, "reach_error"); }
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

// Fibonacci sequence constants for small `c` values, used for assertions
static const int fibonacci_constants[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

int main() {
    int n;
    long long a, b, tmp, c;

    // Initialize variables using a deterministic input model
    n = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assume certain values to prevent overly large calculations
    assume_abort_if_not(n >= 0 && n < 10);
    assume_abort_if_not(c >= 0 && c <= n);

    a = 0;
    b = 1;
    for (int i = 0; i < c; i++) {
        tmp = a + b;
        a = b;
        b = tmp;

        // Verification assertions using pre-determined fibonacci values
        __VERIFIER_assert(a == fibonacci_constants[i + 1]);
    }

    printf("Computation completed up to n=%d, last value: %lld\n", c, a);

    return 0;
}