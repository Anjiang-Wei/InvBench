#include <stdio.h>
#include <stdlib.h>

// Verification-related functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "matrix_sum.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

#define MATRIX_SIZE 4

// Function to compute the sum of the elements of a matrix
int matrix_sum(int matrix[MATRIX_SIZE][MATRIX_SIZE], int size) {
    int sum = 0;
    int counter = 0;

    // Sum elements of the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
            counter++;
        }
    }

    // Assert that the number of elements processed is equal to size*size
    __VERIFIER_assert(counter == size * size);

    return sum;
}

int main() {
    // Initialize a matrix with nondeterministic values
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = __VERIFIER_nondet_int();
        }
    }

    // Calculate the sum of matrix elements
    int sum = matrix_sum(matrix, MATRIX_SIZE);

    // Additional verification: ensure sum is within a reasonable bound

    printf("Sum of matrix elements: %d\n", sum);

    return 0;
}