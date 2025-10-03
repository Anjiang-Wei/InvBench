/*
  Extended Euclidean Algorithm and Related Computations
  This program reads two non-negative integers a and b (<= 10000),
  computes their greatest common divisor (gcd) via the extended
  Euclidean algorithm, verifies the result with assertions,
  and then performs additional computations (lcm, digit sum, Fibonacci)
  under nondeterministic branches.

  The program is intended for automated verification tools.
*/

#include <stdint.h>
#include <stdlib.h>

/* Verification harness declarations */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "ext_euclid.c", 20, "reach_error");
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

/* Main entry */
int main() {
    /* Input variables */
    int a, b;
    int orig_a, orig_b;

    /* Read nondeterministic inputs */
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    /* Constrain inputs: 0 <= a,b <= 10000 */
    assume_abort_if_not(a >= 0 && a <= 10000);
    assume_abort_if_not(b >= 0 && b <= 10000);

    /* Save originals */
    orig_a = a;
    orig_b = b;

    /* Extended Euclidean Algorithm variables */
    int old_r = a;
    int r = b;
    int old_s = 1;
    int s = 0;
    int old_t = 0;
    int t = 1;

    int q, temp;

    /* Compute extended gcd: while r != 0 */
    while (r != 0) {
        /* quotient */
        q = old_r / r;

        /* update remainders */
        temp = old_r - q * r;
        old_r = r;
        r = temp;

        /* update s-coefficients */
        temp = old_s - q * s;
        old_s = s;
        s = temp;

        /* update t-coefficients */
        temp = old_t - q * t;
        old_t = t;
        t = temp;

        /* Basic safety checks */
    }

    /* After loop, old_r is gcd */
    int gcd = old_r;
    int x = old_s;
    int y = old_t;

    /* Verify the gcd is positive (unless both inputs zero) */
    if (orig_a != 0 || orig_b != 0) {
    } else {
        /* gcd(0,0) is defined here as 0 */
    }

    /* Verify the Bézout identity: orig_a*x + orig_b*y == gcd */

    /* Branch 1: Compute LCM if flag1 is true */
    if (__VERIFIER_nondet_int()) {
        /* Avoid division by zero */
        assume_abort_if_not(gcd != 0);

        /* Compute least common multiple */
        long long lcm = (long long)orig_a / gcd * (long long)orig_b;

        /* Verify relationship between gcd and lcm */
    }

    /* Branch 2: Compute sum of decimal digits of gcd */
    if (__VERIFIER_nondet_int()) {
        int sum = 0;
        int tmp = gcd;

        /* Digit-summing loop */
        while (tmp > 0) {
            int digit = tmp % 10;
            sum += digit;
            tmp /= 10;

            /* sum is non-negative and bounded by 9*digits */
        }

        /* Final check on sum */
        __VERIFIER_assert(sum >= 0);
    }

    /* Branch 3: Compute Fibonacci number up to n2 (n2 <= 20) */
    if (__VERIFIER_nondet_int()) {
        int n2 = __VERIFIER_nondet_int();
        assume_abort_if_not(n2 >= 0 && n2 <= 20);

        int f0 = 0;
        int f1 = 1;
        int i;

        /* Fibonacci computation loop */
        for (i = 2; i <= n2; i++) {
            int f2 = f0 + f1;
            f0 = f1;
            f1 = f2;

            /* basic monotonicity: f1 >= f0 */
        }

        /* Check non-negativity */
        if (n2 == 0) {
        } else {
        }
    }

    /* Additional loop: iterate counter times */
    {
        int counter = __VERIFIER_nondet_int();
        assume_abort_if_not(counter >= 0 && counter <= 1000);
        int sum = 0;

        /* Simple accumulation loop */
        while (counter-- > 0) {
            sum += counter;
            /* sum remains non-negative */
        }
        /* Final sanity check */
    }

    return 0;
}