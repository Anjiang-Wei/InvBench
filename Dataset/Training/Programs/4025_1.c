/*
 * A program that computes the factorial of a non-negative integer using an iterative approach.
 * It also contains a simple consistency check after the computation.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_example.c", 9, "reach_error"); }

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
    return;
}

int main() {
    int n;
    long long result = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // We limit n to 20 to prevent overflow in factorial

    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    // A consistency check: factorial of 0 is 1, and any factorial should be >= 1
    if (n == 0) {
        __VERIFIER_assert(result == 1);
    } else {
    }

    printf("Factorial of %d is %lld\n", n, result);

    return 0;
}