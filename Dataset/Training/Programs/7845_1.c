/*
Fibonacci Sequence Computation with Automated Verification Constraints
Calculates the nth Fibonacci number with basic verification checks
*/

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 47); // Constraint to prevent integer overflow for Fibonacci sequence
    int a = 0, b = 1;
    int fib;

    if (n == 0) {
        fib = 0;
    } else if (n == 1) {
        fib = 1;
    } else {
        fib = 0;
        int i = 2;
        while (i <= n) {
            __VERIFIER_assert(a <= b); // Simple verification property: Fibonacci sequence is non-decreasing

            fib = a + b;
            if (fib < 0) {
                // Check for overflow, should not happen due to above constraint
                reach_error();
            }

            a = b;
            b = fib;
            i++;
        }
    }

    return 0;
}