#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
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
    if (N <= 0 || N > 1000) {
        return 1; // assume reasonable bounds for N
    }
    int *arr = (int *)malloc(N * sizeof(int));
    assume_abort_if_not(arr != NULL);

    // Initialize the array with a sequence
    for (int i = 0; i < N; i++) {
        arr[i] = i * i; // squares of indices
    }

    int sum = 0, sum_of_squares = 0;

    // Calculate the sum and the sum of squares
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        sum_of_squares += arr[i] * arr[i];
    }

    // Constraint: the sum must be less than a given threshold
    // Assume a hypothetical maximum threshold
    int threshold = 10000;

    if (N > 1) {
        assume_abort_if_not(sum < threshold);
    }

    // Additional computation: calculate the mean square
    // Use integer division assuming the result is a whole number
    int mean_square = (N > 0) ? sum_of_squares / N : 0;

    // Ensure the mean square is a specific value
    // Placeholder for checking a condition
    // (e.g., mean square must be positive)
    __VERIFIER_assert(mean_square >= 0);

    free(arr);

    return 0;
}