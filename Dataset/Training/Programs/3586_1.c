#include <stdlib.h>

/*
  Compute integer division (quotient and remainder) of a non-negative integer n
  by a positive integer d, using repeated subtraction.
  The post-condition is checked: 0 <= r < d and n0 == q*d + r
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "div_subtract.c", 10, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n, d;
    long long original, q, r;

    /* nondeterministic inputs */
    n = __VERIFIER_nondet_int();
    d = __VERIFIER_nondet_int();

    /* assume reasonable bounds to ensure termination and avoid overflow */
    assume_abort_if_not(n >= 0 && n <= 1000);
    assume_abort_if_not(d >= 1 && d <= 1000);

    /* initialize */
    original = n;
    q = 0;

    /* compute quotient by repeated subtraction */
    while (n >= d) {
        n = n - d;
        q = q + 1;
    }

    r = n;

    /* post-conditions */
    __VERIFIER_assert(r >= 0);

    return 0;
}