// This program is designed to compute a triangular number sequence
// and validates the sum formula using assertions.
// It can be used with automated verification tools to ensure correctness.

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "triangular.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int n, i, sum, expected_sum;

    // Obtain a non-deterministic integer between 0 and 10
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    sum = 0;
    expected_sum = n * (n + 1) / 2;
    i = 0;

    while (i <= n) {
        sum = sum + i;
        i = i + 1;
    }

    // Validate that the computed sum matches the expected sum
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}