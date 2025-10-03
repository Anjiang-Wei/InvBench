/*
Compute the sum of the first n cubes
(where n is a nonnegative integer in a specified range) and check a condition on the sum.
*/

#include <stdio.h>

// Simulated environment functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "cube-sum.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n;
    long long sum_cubes = 0;
    long long expected_sum = 0;
    int i = 0;

    n = __VERIFIER_nondet_int();
    // Assuming n is a positive integer between 0 and 10 for this example
    assume_abort_if_not(n >= 0 && n <= 10);

    // Compute the sum of the first n cubes
    while (i <= n) {
        sum_cubes += (long long)i * i * i;
        i++;
    }

    // Precomputed expected sum formula for the first n cubes
    // expected_sum = (n * (n + 1) / 2) ^ 2;
    expected_sum = ((long long)n * (n + 1) / 2) * ((long long)n * (n + 1) / 2);

    __VERIFIER_assert(sum_cubes == expected_sum);

    printf("Sum of the first %d cubes is %lld\n", n, sum_cubes);

    return 0;
}