/*
Fibonacci Sequence modulo m
This program computes the Fibonacci sequence modulo m over a given number of terms.
It verifies that each computed term is indeed congruent to the sum of the two preceding terms, modulo m.
*/

#include <stdio.h>
#include <stdlib.h>

// External function prototypes for error handling.
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_mod.c", 9, "reach_error"); }
extern void abort(void);

// Function to assert conditions.
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// External function to generate non-deterministic integer input.
extern int __VERIFIER_nondet_int(void);

int main() {
    int n, m; // number of terms and modulus
    int i;
    int *fib;

    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0); // Ensure the number of terms is positive
    assume_abort_if_not(m > 1); // Ensure modulus is greater than 1

    fib = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(fib != NULL);

    // Initialize the first two Fibonacci numbers
    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
    }

    // Compute the Fibonacci sequence modulo m up to the nth term
    for (i = 2; i < n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % m;

        // Verify the property of Fibonacci modulo sequence
        __VERIFIER_assert(fib[i] == (fib[i - 1] + fib[i - 2]) % m);
    }

    // Free allocated memory
    free(fib);

    return 0;
}