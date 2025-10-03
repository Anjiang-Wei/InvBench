// A comprehensive C program designed for static analysis and verification.
// It computes Pascal's triangle, Fibonacci numbers, factorials, and uses
// various loops and assertions to enforce properties without revealing
// explicit loop invariants.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "generated_program.c", 10, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

extern _Bool __VERIFIER_nondet_bool(void);
extern int __VERIFIER_nondet_int(void);
extern short __VERIFIER_nondet_short(void);

#define MAX_N 20

int main() {
    short N;
    int i, j, k, n;
    int c;

    /* Nondeterministically choose N in [0..MAX_N] */
    N = __VERIFIER_nondet_short();
    assume_abort_if_not(N >= 0 && N <= MAX_N);

    /* Arrays for computations */
    int C[MAX_N + 1][MAX_N + 1];   /* Pascal's triangle */
    long long f[MAX_N + 2];        /* Fibonacci sequence */
    long long fact[MAX_N + 1];     /* Factorials */
    int mat[MAX_N + 1][MAX_N + 1]; /* A simple matrix */

    /* 1) Compute Pascal's triangle up to row N */
    for (n = 0; n <= N; n++) {
        C[n][0] = 1;
        C[n][n] = 1;
        /* Check the edges */
        __VERIFIER_assert(C[n][0] == 1);

        for (k = 1; k < n; k++) {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
            /* Each entry is positive */
        }
        /* Symmetry check */
        for (k = 0; k <= n; k++) {
        }
    }

    /* 2) Compute Fibonacci numbers up to f[N] */
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= N; i++) {
        f[i] = f[i - 1] + f[i - 2];
        /* Fibonacci is non-negative and monotonic after index 1 */
    }
    /* Basic checks */

    /* 3) Compute factorials 0! through N! */
    fact[0] = 1;
    for (i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
        /* Factorial grows quickly but remains positive */
    }
    /* Check divisibility: i divides i! */
    for (i = 1; i <= N; i++) {
    }

    /* 4) Initialize a matrix mat with simple values */
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            mat[i][j] = i + j;
        }
    }

    /* 5) A nondeterministic exploration loop accessing Pascal and Fibonacci */
    c = 0;
    while (__VERIFIER_nondet_bool() == 0) {
        /* Pick random indices */
        i = __VERIFIER_nondet_int();
        j = __VERIFIER_nondet_int();
        assume_abort_if_not(i >= 0 && i <= N);
        assume_abort_if_not(j >= 0 && j <= i);

        /* Access Pascal entry */
        /* Symmetry still holds */

        /* Randomly update Fibonacci or Pascal diagonal */
        if (__VERIFIER_nondet_bool()) {
            f[i] = f[i] + 1;
            /* Fibonacci increments keep the sequence non-decreasing */
            if (i + 1 <= N) {
            }
        } else {
            C[i][i] = C[i][i] + f[i];
            /* Diagonal grows but remains > 0 */
        }

        if (++c > 1000) {
            break;
        }
    }

    /* 6) Another nondeterministic loop manipulating factorials */
    c = 0;
    while (__VERIFIER_nondet_bool() == 0) {
        i = __VERIFIER_nondet_int();
        assume_abort_if_not(i >= 0 && i <= N);

        /* Reset or increment factorial entry */
        if (fact[i] > 100000) {
            fact[i] = 1;
        } else {
            fact[i] = fact[i] + i;
        }
        /* Maintain divisibility property */
        if (i > 0) {
        } else {
        }

        if (++c > 500) {
            break;
        }
    }

    /* 7) A nested loop over the matrix with dynamic checks */
    c = 0;
    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            /* Each mat[i][j] <= 2*N */
        }
    }

    /* Final nondeterministic matrix updates */
    c = 0;
    while (__VERIFIER_nondet_bool() == 0) {
        i = __VERIFIER_nondet_int();
        j = __VERIFIER_nondet_int();
        assume_abort_if_not(i >= 0 && i <= N);
        assume_abort_if_not(j >= 0 && j <= N);

        /* Flip or reset an entry */
        if (mat[i][j] > N) {
            mat[i][j] = 0;
        } else {
            mat[i][j] = mat[i][j] + 1;
        }

        if (++c > 300) {
            break;
        }
    }

    return 0;
}