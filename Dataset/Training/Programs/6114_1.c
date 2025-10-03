#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 9, "reach_error"); }
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

// This program computes whether a given number n is a perfect square
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    int sqrt_approx = 0;
    int squared = 0;

    while (squared < n) {
        sqrt_approx++;
        squared = sqrt_approx * sqrt_approx;
    }

    // If squared becomes exactly n, then n is a perfect square
    __VERIFIER_assert((squared == n && sqrt_approx * sqrt_approx == n) || (squared != n && (sqrt_approx - 1) * (sqrt_approx - 1) < n));

    return 0;
}