#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

// Program states that the sum of the differences between consecutive elements of an array must be zero.
int main() {
    int N = __VERIFIER_nondet_int();

    assume_abort_if_not(N > 0 && N <= 1000); // Boundary condition to prevent excessive memory usage

    int *array = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL); // Ensure memory allocation was successful

    int i;

    // Initialize the array with some values
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int diff_sum = 0;
    int prev_val = array[0];

    for (i = 1; i < N; i++) {
        diff_sum += (array[i] - prev_val);
        prev_val = array[i];
    }

    // Validate that the sum of differences equals the difference between first and last elements
    __VERIFIER_assert(diff_sum == (array[N - 1] - array[0]));

    free(array);
    return 0;
}