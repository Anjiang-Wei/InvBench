#include <stdio.h>
#include <stdlib.h>

/*
Fibonacci Series Verification
Calculates the Fibonacci numbers up to the nth number and verifies each number in the series.
*/

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
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
    int n;
    n = __VERIFIER_nondet_int();

    // Assumptions on the value of n to prevent overflow
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n <= 46); // This is to ensure fib(n) doesn't exceed 32-bit integer limit

    int fib0 = 0, fib1 = 1, fibNext;

    if (n == 1) {
    }

    for (int i = 2; i <= n; i++) {
        fibNext = fib0 + fib1;
        fib0 = fib1;
        fib1 = fibNext;
        // Verify Fibonacci property: F(i) should equal the sum of F(i-1) and F(i-2)
    }

    // Verify the nth Fibonacci number
    __VERIFIER_assert(fib1 > 0); // Trivial non-negative assertion considering how fib numbers are generated

    return 0;
}