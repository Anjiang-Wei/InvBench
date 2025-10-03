// C Program to calculate the factorial of a nondeterministic integer
// and verify certain properties related to the calculation

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }

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
    unsigned long long factorial = 1;

    // Get a nondeterministic integer for n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting n to avoid overflow of factorial

    // Calculate factorial
    i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verifying the last value of the factorial
    if (n == 0 || n == 1) {
        __VERIFIER_assert(factorial == 1);
    }

    if (n == 2) {
    }

    if (n == 3) {
    }

    // Continue the pattern as desired...
    return 0;
}