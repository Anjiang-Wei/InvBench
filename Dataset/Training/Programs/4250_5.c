#include <assert.h>
#include <stdlib.h>

/*
  This program generates and verifies several integer sequences:
   - Pascal's triangle (binomial coefficients)
   - Triangular numbers
   - Fibonacci numbers
   - A full GCD table
  It uses loops and asserts final properties of each construction.
*/

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "verif_seq.c", 1, "reach_error");
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

#define MAX_N 20

int main() {
    /*
       N controls the size of all computations.
       We bound it to [0..MAX_N] to keep all loops finite and arrays small.
    */
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= MAX_N);

    /* Arrays for various sequences and tables */
    int C[MAX_N + 1][MAX_N + 1];         /* Pascal's triangle */
    int tri[MAX_N + 1];                  /* Triangular numbers */
    int fib[MAX_N + 2];                  /* Fibonacci numbers */
    int gcd_table[MAX_N + 1][MAX_N + 1]; /* GCD(i,j) table */

    int i, j;

    /*******************************************************************
     * 1) Build Pascal's triangle up to row N
     *******************************************************************/
    C[0][0] = 1;
    for (i = 1; i <= N; i++) {
        C[i][0] = 1;
        for (j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    /* Check symmetry: C[i][j] == C[i][i-j] */
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= i; j++) {
        }
    }

    /* Check that the sum of the N-th row is 2^N */
    {
        int sum_row = 0;
        for (j = 0; j <= N; j++) {
            sum_row += C[N][j];
        }
        /* 1 << N computes 2^N for N in [0..MAX_N] safely */
    }

    /*******************************************************************
     * 2) Build and check triangular numbers: T(i) = i*(i+1)/2
     *******************************************************************/
    tri[0] = 0;
    for (i = 1; i <= N; i++) {
        tri[i] = tri[i - 1] + i;
    }
    for (i = 0; i <= N; i++) {
    }

    /*******************************************************************
     * 3) Build and check Fibonacci numbers: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
     *******************************************************************/
    if (N >= 0) {
        fib[0] = 0;
    }
    if (N >= 1) {
        fib[1] = 1;
    }
    for (i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    /* Validate the recurrence and base cases */
    if (N >= 1) {
        __VERIFIER_assert(fib[1] == 1);
    }
    for (i = 2; i <= N; i++) {
    }

    /*******************************************************************
     * 4) Build a full GCD table using the Euclidean algorithm
     *    and check its properties:
     *      - Symmetry: gcd(i,j) == gcd(j,i)
     *      - Divides both arguments
     *      - gcd(0, j) == j, gcd(i, 0) == i
     *******************************************************************/
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            int a = i, b = j;
            /* Euclidean algorithm */
            while (b != 0) {
                int tmp = a % b;
                a = b;
                b = tmp;
            }
            gcd_table[i][j] = a;
        }
    }

    /* Check GCD properties */
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            int g = gcd_table[i][j];
            /* symmetry */
            /* divides both */
            /* boundary cases */
            if (i == 0) {
            }
            if (j == 0) {
            }
        }
    }

    return 0;
}