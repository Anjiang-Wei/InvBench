/* Program to compute the maximum power of 2 less than or equal to a number */

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power2.c", 5, "reach_error"); }
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
    int n, power = 1;

    // Obtain a non-deterministic integer value for n
    n = __VERIFIER_nondet_int();

    // Assume n is a positive integer
    assume_abort_if_not(n > 0);

    // Compute the largest power of 2 such that it is less than or equal to n
    while (2 * power <= n) {
        power *= 2;
    }

    // Assert that power is indeed the largest power of 2 less than or equal to n
    __VERIFIER_assert(power <= n && (power * 2) > n);

    // Print the result (optional for verification)
    printf("The largest power of 2 less than or equal to %d is %d\n", n, power);

    return 0;
}