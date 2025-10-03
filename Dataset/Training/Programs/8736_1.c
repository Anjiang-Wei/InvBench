#include <assert.h>
#include <stdlib.h>

/*
Simple Matrix Addition and Verification
This program creates two matrices filled with random integers,
adds them into a third matrix, and verifies the sum against
each calculated element.
*/

#define MAX_SIZE 5

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "matrix_add.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

void matrix_add_and_verify(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
            // Verify the addition result
            __VERIFIER_assert(C[i][j] == A[i][j] + B[i][j]);
        }
    }
}

int main() {
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size >= 1 && size <= MAX_SIZE);

    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = __VERIFIER_nondet_int();
            B[i][j] = __VERIFIER_nondet_int();
        }
    }

    matrix_add_and_verify(A, B, C, size);

    return 0;
}