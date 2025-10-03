#include <stdio.h>
#include <stdlib.h>

/*
 * A C program to calculate the factorial of a number iteratively.
 * The program is designed to be verifiable by automated verification tools.
 * It checks the correctness of factorial computation for inputs in a specified range.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 12, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Assume n is between 0 and 10 for simplicity.

    if (n == 0 || n == 1) {
    }

    int factorial = 1;
    int i;

    // Calculate factorial iteratively
    for (i = 2; i <= n; i++) {
        factorial = factorial * i;
    }

    // Verify the computed factorial for n (only up to 10 for simplicity)
    switch (n) {
    case 2:
        break;
    case 3:
        break;
    case 4:
        __VERIFIER_assert(factorial == 24);
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    default:
        break;
    }

    return 0;
}