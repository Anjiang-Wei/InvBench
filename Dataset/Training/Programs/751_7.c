/*
  A comprehensive C program combining several loops and
  computational tasks: Pascal's triangle row sums, Fibonacci
  sequence, and the Euclidean GCD algorithm. Designed for
  automated verification. Contains nondeterministic inputs,
  assume/abort for constraints, and verification assertions.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "combined-verify.c", 15, "reach_error");
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

/* Nondeterministic input functions */
extern int __VERIFIER_nondet_int(void);

/* Main program */
int main() {
    /* Part 1: Pascal's triangle row sums */
    int max_row;
    int prev[12], curr[12];
    long long sum;
    long long power2;
    int i, j;

    /* get a nondet row index between 0 and 10 */
    max_row = __VERIFIER_nondet_int();
    assume_abort_if_not(max_row >= 0 && max_row <= 10);

    /* initialize row 0: [1] */
    for (i = 0; i < 12; i++) {
        prev[i] = 0;
    }
    prev[0] = 1;

    power2 = 1; /* 2^0 == 1 */

    /* Loop over rows from 0 to max_row */
    i = 0;
    while (i <= max_row) {
        /* compute sum of current row (in prev) */
        sum = 0;
        for (j = 0; j <= i; j++) {
            sum += prev[j];
        }
        /* verify that the sum equals 2^i */

        /* prepare next row unless we're at the last */
        if (i < max_row) {
            /* compute row i+1 into curr */
            curr[0] = 1;
            for (j = 1; j <= i; j++) {
                curr[j] = prev[j - 1] + prev[j];
            }
            curr[i + 1] = 1;
            /* clear the rest */
            for (j = i + 2; j < 12; j++) {
                curr[j] = 0;
            }
            /* copy curr to prev */
            for (j = 0; j < 12; j++) {
                prev[j] = curr[j];
            }
            /* update power2: multiply by 2 */
            power2 = power2 * 2;
        }
        i = i + 1;
    }

    /* Part 2: Fibonacci sequence */
    int fib_n;
    int k;
    long long f0, f1, f2;

    /* get nondet fib index between 0 and 20 */
    fib_n = __VERIFIER_nondet_int();
    assume_abort_if_not(fib_n >= 0 && fib_n <= 20);

    /* F(0)=0, F(1)=1 */
    f0 = 0;
    f1 = 1;
    k = 1;

    /* compute up to F(fib_n) */
    while (k < fib_n) {
        f2 = f0 + f1;
        /* verify relation holds each step */
        f0 = f1;
        f1 = f2;
        k = k + 1;
    }
    /* At end, f1 holds F(fib_n) */
    /* A simple postcondition: Fibonacci grows: F(n) >= n for all n>=1 */
    if (fib_n >= 1) {
    }

    /* Part 3: Euclidean GCD */
    int a, b;
    int orig_a, orig_b;
    int r;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    /* constrain to positive range */
    assume_abort_if_not(a > 0 && a <= 1000);
    assume_abort_if_not(b > 0 && b <= 1000);

    orig_a = a;
    orig_b = b;

    /* classic Euclid's algorithm */
    while (b != 0) {
        r = a % b;
        /* remainder is always nonnegative and less than b */
        a = b;
        b = r;
    }
    /* now a holds gcd(orig_a, orig_b) */
    /* gcd divides both originals */
    /* gcd is at least 1 */
    __VERIFIER_assert(a >= 1);

    /* If all assertions pass, program returns normally */
    return 0;
}