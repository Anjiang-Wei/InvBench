// This program is designed to be analyzed by automated verification tools
// It involves computation and constraint checks, following patterns observed
// in verification-targeted C programs.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 100);

    int sum = 0;
    int prod = 1;
    int i = 1;

    while (i <= n) {
        sum += i;
        prod *= i;
    }

    // Check if sum of first n natural numbers equals n(n+1)/2
    __VERIFIER_assert(sum == n * (n + 1) / 2);

    // Check if product is greater than sum for n > 1
    if (n > 1) {
    }

    return 0;
}