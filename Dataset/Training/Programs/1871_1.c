/*
 * A C program that calculates the Fibonacci numbers iteratively and uses assertions to verify properties.
 * This program aims to be suitable for automated analysis and verification tools.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 7, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a;
        a = b;
        b = temp + b;
    }
    return b;
}

int main() {
    // Get a nondeterministic integer for the Fibonacci sequence position
    int n = __VERIFIER_nondet_int();

    // Assume a realistic bound for the sake of running computations
    assume_abort_if_not(n >= 0 && n <= 20); // Reasonable bounds

    int result = fib(n);

    // Assertions to verify properties of Fibonacci numbers
    // Any Fibonacci number shall not be negative
    __VERIFIER_assert(result >= 0);

    // Known property: every second Fibonacci number is even starting with Fib(0) = 0
    if (n % 3 == 0) {
    }

    // Print Fibonacci of n for manual checking
    printf("Fibonacci number at position %d is %d\n", n, result);

    return 0;
}