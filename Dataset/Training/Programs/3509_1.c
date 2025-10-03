#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
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
    int n, sum, i, multiplier;

    // Inputs
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    sum = 0;
    multiplier = 1;

    // Loop that calculates a series sum with a condition
    for (i = 1; i <= n; i++) {
        sum += i * multiplier;
        multiplier *= 2;

        // Invariant for verification
        __VERIFIER_assert(sum > 0 || n == 0);
    }

    // Assertion to check final condition
}