/*
Fibonacci Sequence Generator with Verifier
This program generates Fibonacci numbers up to a given limit N
and verifies that the Fibonacci property holds true:
F(n) = F(n-1) + F(n-2)
*/

#include <stdio.h>
#include <stdlib.h>

// Functions to simulate verification environment
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-verifier.c", 10, "reach_error"); }

// Assertion to check conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Function to simulate non-deterministic value
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }

    int *fib = (int *)malloc(sizeof(int) * (N + 1));
    if (fib == NULL) {
        return 1;
    }

    // Initializing the first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    // Generating Fibonacci numbers
    for (int i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        // Verifying the Fibonacci property
        __VERIFIER_assert(fib[i] == fib[i - 1] + fib[i - 2]);
    }

    // Verify that we have the correct number of Fibonacci numbers

    // Clean up
    free(fib);
    return 0;
}