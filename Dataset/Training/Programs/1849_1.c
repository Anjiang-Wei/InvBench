#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int calculate_series_sum(int n) {
    int sum = 0;
    int term = 1;
    for (int i = 1; i <= n; ++i) {
        sum += term;
        term *= 2; // Each term is twice the previous term
    }
    return sum;
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR:
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    int sum = calculate_series_sum(n);

    // Verify that the sum is equal to 2^(n) - 1
    __VERIFIER_assert(sum == (1 << n) - 1);

    // Print the result (not required for verification, just for visual confirmation)
    printf("The calculated sum of the series is %d.\n", sum);

    return 0;
}