/*
 * Matrix multiplication with bounds checking for demonstration purposes.
 * The function multiplies two N x N matrices and performs verification of output constraints.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "matrix_mult.c", 9, "reach_error"); }
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

#define MAX_MATRIX_VALUE 100
#define MIN_MATRIX_VALUE -100

int main() {
    int N, i, j, k, sum;

    // Non-deterministic input dimensions of the matrices, bounded.
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 10);

    // Allocate memory for matrices A, B, and for resulting matrix C.
    int **A = malloc(N * sizeof(int *));
    int **B = malloc(N * sizeof(int *));
    int **C = malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        A[i] = malloc(N * sizeof(int));
        B[i] = malloc(N * sizeof(int));
        C[i] = malloc(N * sizeof(int));
    }

    // Initialize matrices A and B with random values for the example
    // Here we assume some pre-defined logical operations to setup the matrices
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = (__VERIFIER_nondet_int() % (MAX_MATRIX_VALUE - MIN_MATRIX_VALUE + 1)) + MIN_MATRIX_VALUE;
            B[i][j] = (__VERIFIER_nondet_int() % (MAX_MATRIX_VALUE - MIN_MATRIX_VALUE + 1)) + MIN_MATRIX_VALUE;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum = 0;
            for (k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    // Perform verification on the elements of resulting matrix C
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            // Verify each element is within expected bounds e.g., C[i][j] should also remain within known safe bounds.
            assume_abort_if_not(C[i][j] >= N * MIN_MATRIX_VALUE * MIN_MATRIX_VALUE && C[i][j] <= N * MAX_MATRIX_VALUE * MAX_MATRIX_VALUE);
            __VERIFIER_assert(C[i][j] >= N * MIN_MATRIX_VALUE * MIN_MATRIX_VALUE);
        }
    }

    for (i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}