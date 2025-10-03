/*
 * This program computes the factorial of a nondeterministic integer using a loop.
 * It utilizes an assertion to validate the result at the end. The program is intended
 * to be verified by automated verification tools to ensure correctness.
 */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "factorial.c", 9, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Choose a reasonable range for factorial

    long long factorial = 1;
    int i;

    for (i = 2; i <= n; ++i) { // Calculate factorial using a loop
        factorial *= i;
    }

    // Verify using a condition that factorial should not exceed a predefined limit
    // Here, the range of factorial values is safe up to 10! = 3628800
    __VERIFIER_assert(factorial > 0 && factorial <= 3628800);

    return 0;
}