#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int(); // length of sequence
    assume_abort_if_not(n > 0);      // ensure n is positive
    assume_abort_if_not(n <= 1000);  // avoid overflow and keep problem size reasonable

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        abort(); // fail if memory allocation fails
    }

    // Fill with non-deterministic values
    for (int i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    int sum_even = 0;
    int sum_odd = 0;
    int counter = 0;

    while (counter < n) {
        if (arr[counter] % 2 == 0) {
            sum_even += arr[counter];
        } else {
            sum_odd += arr[counter];
        }
        counter++;
    }

    // Verification of some property
    __VERIFIER_assert(sum_even % 2 == 0); // sum of evens should be even
    free(arr);

    return 0;
}