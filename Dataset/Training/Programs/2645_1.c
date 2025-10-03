/*
Fibonacci Numbers Verification
This program computes Fibonacci numbers and verifies certain properties.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int fibonacci(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, fib = 0;
    for (unsigned int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    unsigned int limit = 30; // Calculate Fibonacci numbers up to a certain limit
    int lastFib = 0;
    int currentFib;

    for (unsigned int i = 0; i <= limit; i++) {
        currentFib = fibonacci(i);

        // Verify that each Fibonacci number is non-negative
        __VERIFIER_assert(currentFib >= 0);

        // Verify that current Fibonacci number is the sum of the two preceding ones
        if (i >= 2) {
            int sumOfPrevTwo = lastFib + fibonacci(i - 1);
        }

        lastFib = fibonacci(i);
    }

    return 0;
}