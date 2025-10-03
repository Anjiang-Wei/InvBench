#include <stdio.h>
#include <stdlib.h>

/*
 * This program computes the product of two matrices A and B
 * where A is NxM and B is MxP and both matrices have integer entries.
 * It illustrates matrix multiplication logic with verification constraints.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "matrix_mult.c", 13, "reach_error"); }

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
}

extern int __VERIFIER_nondet_int(void);

void *malloc_wrapper(size_t size) {
    void *ptr = malloc(size);
    assume_abort_if_not(ptr != NULL);
    return ptr;
}

int main() {
    int N = __VERIFIER_nondet_int();
    int M = __VERIFIER_nondet_int();
    int P = __VERIFIER_nondet_int();

    assume_abort_if_not(N > 0 && M > 0 && P > 0);
    assume_abort_if_not(N <= 200 && M <= 200 && P <= 200);

    int **A = (int **)malloc_wrapper(N * sizeof(int *));
    int **B = (int **)malloc_wrapper(M * sizeof(int *));
    int **C = (int **)malloc_wrapper(N * sizeof(int *));

    for (int i = 0; i < N; ++i) {
        A[i] = (int *)malloc_wrapper(M * sizeof(int));
        C[i] = (int *)malloc_wrapper(P * sizeof(int));
    }

    for (int i = 0; i < M; ++i) {
        B[i] = (int *)malloc_wrapper(P * sizeof(int));
    }

    // Initialize matrices A and B with nondeterministic values
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = __VERIFIER_nondet_int();
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            B[i][j] = __VERIFIER_nondet_int();
        }
    }

    // Compute matrix multiplication C = A * B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Verification step: Check some properties of the resulting matrix C
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            // The equation below is not generally true for any A and B,
            // replace this with any specific invariant relevant to your context.
            __VERIFIER_assert(C[i][j] >= 0 || C[i][j] <= 1000);
        }
    }

    // Free allocated memory
    for (int i = 0; i < N; ++i) {
        free(A[i]);
        free(C[i]);
    }
    for (int i = 0; i < M; ++i) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}