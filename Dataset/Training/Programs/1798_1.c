/*
 * New C Program
 * This program is designed based on patterns observed in previous examples.
 * It performs a simple integer manipulation and verification without using
 * assertions to indicate loop invariants directly.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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
}

int main() {
    int m, n, sum, prod, count;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && n >= 0);

    sum = 0;
    prod = 1;
    count = 0;

    // Ensuring m and n are limited to small values for safety
    assume_abort_if_not(m < 100);
    assume_abort_if_not(n < 100);

    // Increment every element in the range [0, m) by 2
    while (count < m) {
        sum += 2;
        count++;
    }

    count = 0;

    // Compute factorial of n, careful for larger n values
    while (count < n) {
        prod *= (count + 1);
        count++;
    }

    // Verification condition
    __VERIFIER_assert(sum == 2 * m);
}