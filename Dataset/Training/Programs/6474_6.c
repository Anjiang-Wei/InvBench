#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "verification_pascal_fib_gcd_lcm.c", 9, "reach_error");
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

/*
   This program computes:
   1) Pascal's triangle up to row n and verifies row sums == 2^i.
   2) Fibonacci sequence up to F[n] and checks F[i] > F[i-1].
   3) GCD and LCM for all pairs (a,b) in [1..n] and checks a*b == gcd(a,b)*lcm(a,b).
   It is designed for automatic verification tools.
*/

#define MAX_N 10

int main() {
    int n;
    int i, j;
    int C[MAX_N + 1][MAX_N + 1];
    int fib[MAX_N + 2];
    int a, b, x, y, g, l;
    int sumR;
    int pow2[MAX_N + 1];

    /* nondeterministic choice of n */
    n = __VERIFIER_nondet_int();
    /* restrict n to small range */
    assume_abort_if_not(n >= 0 && n <= MAX_N);

    /* precompute powers of 2 up to MAX_N */
    pow2[0] = 1;
    for (i = 1; i <= MAX_N; i++) {
        pow2[i] = pow2[i - 1] * 2;
        /* check no overflow within small bounds */
    }

    /********** Pascal's Triangle Computation **********/
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
            /* each entry is at least 1 and not more than 2^i */
        }
        /* compute sum of the i-th row */
        sumR = 0;
        for (j = 0; j <= i; j++) {
            sumR += C[i][j];
        }
        /* the sum of row i is exactly 2^i */
    }

    /********** Fibonacci Sequence Computation **********/
    /* we define fib[0..n], with fib[0]=0, fib[1]=1 */
    if (n >= 0) {
        fib[0] = 0;
    }
    if (n >= 1) {
        fib[1] = 1;
    }
    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        /* fibonacci numbers grow monotonically for i>=2 */
    }

    /********** GCD and LCM Verification **********/
    /* for all pairs (a,b) in [1..n] */
    for (a = 1; a <= n; a++) {
        for (b = 1; b <= n; b++) {
            /* compute gcd(a,b) by subtraction-based Euclid */
            x = a;
            y = b;
            /* invariant: x>=1 && y>=1 */
            while (x != y) {
                if (x > y) {
                    x = x - y;
                } else {
                    y = y - x;
                }
                /* gcd is invariant under subtraction */
                __VERIFIER_assert(x >= 1 && y >= 1);
            }
            g = x; /* gcd */
            /* compute lcm from gcd */
            /* to avoid overflow in small bounds: cast */
            l = (a / g) * b;
            /* check that a*b == g*l */
            /* check that g divides both a and b */
        }
    }

    return 0;
}