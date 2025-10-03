#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
  Generic Program Pattern Demonstrating Verification
  Generates and verifies a Fibonacci sequence up to a certain number.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 13, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N, i;
    long long fib[2]; // Using an array to store last two Fibonacci numbers

    // Nondeterministically choose the number of Fibonacci terms to generate
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 1 && N <= 50); // Constraints on N

    // Initialize the first two terms
    fib[0] = 0;
    fib[1] = 1;

    i = 2; // Start index from 2 as the first two terms are initialized

    while (i < N) {
        long long next_fib = fib[0] + fib[1];
        fib[1] = next_fib;

        i++;
    }

    // A simple verification at the end
    __VERIFIER_assert(fib[1] >= 0); // Check the Fibonacci number computed is non-negative

    printf("Fibonacci sequence up to term %d calculated.\n", N);
    return 0;
}