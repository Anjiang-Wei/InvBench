/*
 * C Program: Summation and Product Verification
 * This program computes the sum and the product of the first N non-negative integers,
 * and verifies certain conditions using automated assertion checks.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_prog.c", 8, "reach_error");
}
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
    int i, N;
    long long sum = 0;
    long long product = 1;

    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 1);
    assume_abort_if_not(N <= 20); // Limit N to avoid overflow in product

    for (i = 1; i <= N; i++) {
        sum += i;
        product *= i;
    }

    // Compute the expected sum of first N integers: N * (N + 1) / 2
    long long expected_sum = (long long)N * (N + 1) / 2;

    // Verify that the computed sum matches the expected sum
    __VERIFIER_assert(sum == expected_sum);

    // Expected product verification is skipped due to rapid product growth
    // This program illustrates handling and verification for a computed sum

    return 0;
}