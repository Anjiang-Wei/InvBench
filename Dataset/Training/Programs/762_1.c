#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Verify Sum of Powers of Two
 * Computes whether the sum of powers of two from 2^0 to 2^(k-1)
 * equals 2^k - 1.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_of_powers.c", 9, "reach_error"); }
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
}

int main() {
    int k, n;
    long long sum, power;

    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k > 0 && k < 31); // limit k to prevent overflow in power
    n = 1;
    sum = 0;
    power = 1; // 2^0

    while (n <= k) {
        sum += power; // sum of powers of two
        power *= 2;   // calculate next power of two (2^n)
        n++;
    }

    // Verify that the sum of 2^0 + 2^1 + ... + 2^(k-1) is 2^k - 1
    long long expected_sum = power - 1;
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}