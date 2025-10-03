/* Program to compute Fibonacci sequence iteratively and verify result */

#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-iter.c", 7, "reach_error"); }
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
    int n, i;
    long long fib, prevFib, prevPrevFib;

    // Get a nondeterministic number of terms to compute
    n = __VERIFIER_nondet_int();

    // Assume n to be non-negative
    assume_abort_if_not(n >= 0);

    // Initial two Fibonacci numbers
    if (n == 0) {
        fib = 0;
    } else if (n == 1) {
        fib = 1;
    } else {
        prevPrevFib = 0; // F(0)
        prevFib = 1;     // F(1)
        fib = 1;         // Result place holder

        i = 2;
        while (i <= n) {
            fib = prevFib + prevPrevFib;

            // Shift previous numbers upward
            prevPrevFib = prevFib;
            prevFib = fib;

            i++;
        }
    }

    // Verify the Fibonacci value check (only for known small n like 5, can be extended with known values)
    if (n == 0) {
    } else if (n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(fib == 1);
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    }
    // More checks can be added accordingly

    return 0;
}