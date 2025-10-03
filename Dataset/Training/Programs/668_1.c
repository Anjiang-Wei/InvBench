#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int M = __VERIFIER_nondet_int();
    if (M <= 0 || M > 1000) {
        return 1; // Prevent overly large or small arrays
    }
    assume_abort_if_not(M <= 2147483647 / sizeof(int));

    int *array = malloc(sizeof(int) * M);
    if (!array) {
        return 1; // Check for allocation failure
    }

    int i;
    unsigned long long sum = 0;

    // Fill the array with random nondeterministic values
    for (i = 0; i < M; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Ensure all values are positive for simplicity
    for (i = 0; i < M; i++) {
        if (array[i] < 0) {
            array[i] = -array[i];
        }
    }

    // Compute the sum of the even-indexed elements
    // and the product of the odd-indexed elements
    unsigned long long product = 1;
    for (i = 0; i < M; i++) {
        if (i % 2 == 0) {
            sum += array[i];
        } else {
            product *= array[i];
        }
    }

    // Assert that sum is non-negative and product is non-negative
    __VERIFIER_assert(sum >= 0);

    free(array);
    return 0;
}