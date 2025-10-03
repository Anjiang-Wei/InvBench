#include <stdio.h>

/*
Arithmetic Series
computes s = sum(2*k + 3) for k in range [0, n-1]
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "arithmetic-series.c", 10, "reach_error"); }
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
    int n, k, s, expected_sum;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    k = 0;
    s = 0;
    expected_sum = n * (n - 1) + 3 * n; // Calculated expected sum for validation

    while (k < n) {
        // Each term of the sequence is 2*k + 3
        s = s + (2 * k + 3);
        k = k + 1;
    }

    // Verify the computed sum equals the expected_sum
    __VERIFIER_assert(s == expected_sum);

    printf("Computed sum: %d, Expected sum: %d\n", s, expected_sum);

    return 0;
}