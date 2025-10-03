/*
Fibonacci Sequence and Parity Check
This program calculates a few terms of the Fibonacci sequence
and ensures certain parity properties in the process.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib_parity.c", 5, "reach_error"); }
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
    long long fib1, fib2, temp;
    long long sum_even = 0;
    long long sum_odd = 0;
    long long c;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Constrain n for verification purposes

    fib1 = 0;
    fib2 = 1;
    c = 0;

    while (1) {
        if (c >= n) {
            break;
        }

        // Calculate next Fibonacci term
        temp = fib1 + fib2;
        fib1 = fib2;
        fib2 = temp;

        // Ensure parity properties:
        // Even Fibonacci numbers add to sum_even
        // Odd Fibonacci numbers add to sum_odd
        if (fib1 % 2 == 0) {
            sum_even += fib1;
        } else {
            sum_odd += fib1;
        }

        // Avoid overflow / check constraints
        __VERIFIER_assert(sum_even >= 0 && sum_odd >= 0);

        c = c + 1;
    }

    // Check that total sum divided by last fibonacci value is a reasonable number

    printf("Sum of even fibonacci numbers: %lld\n", sum_even);
    printf("Sum of odd fibonacci numbers: %lld\n", sum_odd);

    return 0;
}