/*
 * Sample C program demonstrating simple computation with loop
 * Implements factorial computation and verification through asserts
 * Designed to be analyzed by automated verification tools
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 8, "reach_error"); }
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
    return;
}

int factorial(int n) {
    int i;
    int result = 1;
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // limiting n to avoid integer overflow

    int fact = factorial(n);

    // Expected factorial value for small n, assert to verify computation
    if (n == 0) {
    }
    if (n == 1) {
    }
    if (n == 2) {
    }
    if (n == 3) {
    }
    if (n == 4) {
    }
    if (n == 5) {
    }
    if (n == 6) {
    }
    if (n == 7) {
        __VERIFIER_assert(fact == 5040);
    }
    if (n == 8) {
    }
    if (n == 9) {
    }
    if (n == 10) {
    }
    if (n == 11) {
    }
    if (n == 12) {
    }

    return 0;
}