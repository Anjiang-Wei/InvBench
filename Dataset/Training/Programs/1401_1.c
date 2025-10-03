/*
 * A C Program example inspired by benchmark patterns
 * This program calculates the squares of integers in an array
 * and verifies that each square is greater than or equal to the original number.
 * The program uses verification patterns with assertions and assumes.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "squared_array_verification.c", 9, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1; // If N is not positive, exit early
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int i;
    int *array = malloc(sizeof(int) * N);
    int *squares = malloc(sizeof(int) * N);

    // Initialize the array with nondeterministic values
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Compute squares of each element
    for (i = 0; i < N; i++) {
        squares[i] = array[i] * array[i];
    }

    // Verify that each square is greater than or equal to the original element
    for (i = 0; i < N; i++) {
        __VERIFIER_assert(squares[i] >= array[i]);
    }

    // Clean up
    free(array);
    free(squares);

    return 0;
}