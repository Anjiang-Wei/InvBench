/*
Fibonacci Sequence Checker
computes if a number is part of the Fibonacci sequence
and verifies sequence constraints.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci_check.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    assume_abort_if_not(n >= 0 && n < 1000); // Assume n is a positive integer less than 1000

    long long a = 0, b = 1, c;
    int found = 0;

    if (n == 0 || n == 1) {
        found = 1;
    } else {
        int counter = 2;
        while (counter <= n) {
            c = a + b;
            a = b;
            b = c;
            if (b == n) {
                found = 1;
                break;
            }
            counter++;
        }
    }

    if (found) {
        printf("%d is a Fibonacci number.\n", n);
    } else {
        printf("%d is not a Fibonacci number.\n", n);
    }

    // Verification step to ensure the loop maintains the constraints of the Fibonacci series
    __VERIFIER_assert(b >= 0 && a >= 0); // Ensure non-negative values in the sequence
    return 0;
}