#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 1) {
        return 1;
    }
    assume_abort_if_not(n <= 1000); // Avoid excessive allocations

    int i, j;
    int **matrix = malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            matrix[i][j] = __VERIFIER_nondet_int();
        }
    }

    int rowSum, colSum;
    int isMagicSquare = 1;

    // Calculate the sum of the first row
    rowSum = 0;
    for (j = 0; j < n; j++) {
        rowSum += matrix[0][j];
    }

    // Check each row sum
    for (i = 1; i < n; i++) {
        int currentRowSum = 0;
        for (j = 0; j < n; j++) {
            currentRowSum += matrix[i][j];
        }
        if (currentRowSum != rowSum) {
            isMagicSquare = 0;
            break;
        }
    }

    // Check each column sum
    if (isMagicSquare) {
        for (j = 0; j < n; j++) {
            int currentColSum = 0;
            for (i = 0; i < n; i++) {
                currentColSum += matrix[i][j];
            }
            if (currentColSum != rowSum) {
                isMagicSquare = 0;
                break;
            }
        }
    }

    int diag1 = 0, diag2 = 0;
    // Calculate the sum of the first diagonal
    for (i = 0; i < n; i++) {
        diag1 += matrix[i][i];
    }

    // Calculate the sum of the second diagonal
    for (i = 0; i < n; i++) {
        diag2 += matrix[i][n - i - 1];
    }

    if (diag1 != rowSum || diag2 != rowSum) {
        isMagicSquare = 0;
    }

    __VERIFIER_assert(!isMagicSquare || (diag1 == diag2 && diag1 == rowSum));

    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}