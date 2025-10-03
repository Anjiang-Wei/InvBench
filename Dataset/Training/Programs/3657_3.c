/*
  A composite verification benchmark in C:
  - Computes binomial coefficients (Pascal's triangle)
  - Computes factorials
  - Computes Fibonacci numbers
  - Builds a GCD table using Euclid's algorithm
  Uses __VERIFIER_nondet_int, assume_abort_if_not, and __VERIFIER_assert
  to enable automated verification tools to check correctness properties.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "composite_verif.c", 10, "reach_error");
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

#define MAX_N 10

int main() {
    int N;
    /* choose problem size */
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= MAX_N);

    /* 1) Pascal's triangle: C[row][k] = binomial(row, k) */
    int C[MAX_N + 1][MAX_N + 1];
    int row, k;
    int rowSum;

    /* base case */
    C[0][0] = 1;

    /* build rows 1..N */
    for (row = 1; row <= N; row++) {
        /* edges are 1 */
        C[row][0] = 1;
        C[row][row] = 1;
        __VERIFIER_assert(C[row][row] == 1);

        /* inner entries by Pascal identity */
        for (k = 1; k < row; k++) {
            C[row][k] = C[row - 1][k - 1] + C[row - 1][k];

            /* the new entry is positive */

            /* symmetry: binomial(row, k) == binomial(row, row-k) */
        }

        /* sum of row entries should be 2^row */
        rowSum = 0;
        for (k = 0; k <= row; k++) {
            rowSum += C[row][k];
        }
    }

    /* 2) Factorial table: F[i] = i! */
    int F[MAX_N + 1];
    int i;
    /* base factorial */
    F[0] = 1;

    for (i = 1; i <= N; i++) {
        F[i] = i * F[i - 1];
        /* check factorial recurrence */
        /* factorial grows at least as fast as previous */
    }

    /* 3) Fibonacci numbers: Fib[0]=0, Fib[1]=1, Fib[i]=Fib[i-1]+Fib[i-2] */
    int Fib[MAX_N + 1];
    /* base cases */
    Fib[0] = 0;
    Fib[1] = 1;

    for (i = 2; i <= N; i++) {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
        /* check Fibonacci recurrence */
        /* Fibonacci is non-decreasing from i>=1 */
    }

    /* 4) GCD table: G[i][j] = gcd(i,j) via Euclid's algorithm */
    int G[MAX_N + 1][MAX_N + 1];
    int a, b, r;
    int j;

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            /* compute gcd of i and j */
            a = i;
            b = j;
            while (b != 0) {
                r = a % b;
                a = b;
                b = r;
            }
            G[i][j] = a;

            /* gcd is at least 1 and no more than min(i,j) */

            /* gcd divides both operands */
        }
    }

    return 0;
}