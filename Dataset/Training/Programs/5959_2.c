#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int();
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

int main() {
    int n = __VERIFIER_nondet_int();
    int *arr;

    // Assume that n is between 1 and 100
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n <= 100);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) { // check malloc success
        abort();
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = __VERIFIER_nondet_int(); // Populate array with random numbers
    }

    // Sum of squares of the elements in the array
    int sum_of_squares = 0;
    for (int i = 0; i < n; ++i) {
        sum_of_squares += arr[i] * arr[i];
        // Check for overflow (if any entry is too large, it may overflow)
    }

    // Verification condition: check if the sum of squares is indeed greater than or equal to 0
    __VERIFIER_assert(sum_of_squares >= 0);

    free(arr);
    return 0;
}