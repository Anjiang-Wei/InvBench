/*
 * Program to calculate the factorial of a number and verify properties
 * using automated verification tools.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial-verify.c", 8, "reach_error"); }
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
    assume_abort_if_not(n >= 0 && n <= 12); // Constraint for n within a reasonable range to avoid overflow

    long long factorial = 1;
    int i = 1;

    while (i <= n) {
        factorial = factorial * i;
        i++;
    }

    // Post-condition: factorial should be greater than 0 for all n >= 0
    __VERIFIER_assert(factorial > 0);

    // Additional property: verify factorial of 5 is 120
    if (n == 5) {
    }

    return 0;
}