#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_geo_series.c", 8, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int base, n, i;
    long long sum, term;

    // Get non-deterministic values for base and n
    base = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assumptions to provide meaningful constraints
    assume_abort_if_not(base >= 0 && base <= 10);
    assume_abort_if_not(n >= 0 && n <= 15);

    sum = 0;
    term = 1; // Initial term base^0 = 1

    // Calculate the series sum of (base^i) where i=0..n-1
    for (i = 0; i < n; ++i) {
        sum += term;
        term *= base;
    }

    // Invariant check based on known series sum formula for x^0 + x^1 + ... + x^(k-1)
    if (base != 1 && n > 0) {
        long long expectedSum = (term - 1) / (base - 1);
        __VERIFIER_assert(sum == expectedSum);
    }

    return 0;
}