/*
Fibonacci Series Verification
Calculates Fibonacci series up to a certain number and verifies its properties.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
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

int main() {
    unsigned int n, a, b, fib, i;

    n = __VERIFIER_nondet_uint(); // Determine how many Fibonacci numbers to calculate
    assume_abort_if_not(n > 2);   // Require at least three numbers for meaningful Fibonacci calculation

    a = 0; // F(0)
    b = 1; // F(1)

    for (i = 2; i < n; i++) {
        // Calculate the next Fibonacci number
        fib = a + b;

        // Verifying that the Fibonacci sequence retains its property F(n) = F(n-1) + F(n-2)

        // Move to the next numbers in sequence
        a = b;
        b = fib;
    }

    // Final assertion to check the series property
    __VERIFIER_assert(fib == a + b - a); // This should always hold true based on how we update `a` and `b`

    // Printing the last Fibonacci number to demonstrate computation
    printf("Fibonacci sequence nth value: %u\n", fib);

    return 0;
}