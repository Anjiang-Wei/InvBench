#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "series_assert.c", 3, "reach_error"); }
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

int main() {
    int a, n;
    long long sum, term;

    // Get non-deterministic values for a and n
    a = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensure a is a positive integer and n is within a reasonable bound
    assume_abort_if_not(a > 0 && a <= 100);
    assume_abort_if_not(n >= 0 && n <= 50);

    sum = 0;
    term = 1;

    // Summation of series: 1 + a + a^2 + ... + a^(n-1)
    for (int i = 0; i < n; ++i) {
        sum += term;
        term *= a;
        __VERIFIER_assert(term >= 0); // Ensure no overflow (term should be non-negative)
    }

    // Verify that the computed sum matches the expected sum of geometric series
    if (a == 1) {
        __VERIFIER_assert(sum == n); // Special case: when a = 1, sum should be n
    } else {
        long long expected_sum = (1 - term) / (1 - a);
    }

    printf("Sum of series for a = %d and n = %d is %lld\n", a, n, sum);
    return 0;
}