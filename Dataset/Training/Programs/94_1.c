#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error() {
    /* Error condition reached */
    assert(0);
}

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

/*
 * Extended Euclidean algorithm:
 * Given positive a, b, it computes gcd(a,b) and Bezout coefficients
 * x, y such that x*a + y*b = gcd(a,b).
 */
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    /* Constrain inputs to a reasonable range and non‐zero to avoid
       division by zero in the loop. */
    assume_abort_if_not(a >= 1 && a <= 1000);
    assume_abort_if_not(b >= 1 && b <= 1000);

    int old_r = a, r = b;
    int old_s = 1, s = 0;
    int old_t = 0, t = 1;

    /* Loop: while remainder r is nonzero, perform the division
       step of the extended Euclidean algorithm. */
    while (r != 0) {
        int q = old_r / r;

        /* update remainders */
        int tmp = old_r - q * r;
        old_r = r;
        r = tmp;

        /* update Bezout coefficients s */
        tmp = old_s - q * s;
        old_s = s;
        s = tmp;

        /* update Bezout coefficients t */
        tmp = old_t - q * t;
        old_t = t;
        t = tmp;
    }

    /* old_r is now gcd(a,b), and (old_s, old_t) are the Bezout coefficients */
    int gcd = old_r;

    /* Verification conditions */
    __VERIFIER_assert(gcd > 0);
    /* Check the linear combination property: old_s*a + old_t*b == gcd */

    return 0;
}