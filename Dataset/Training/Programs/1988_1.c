/*
 * This program demonstrates a simple verification scenario where
 * a 1D array of integers is filled and then a certain property is checked
 * relating to the sum of its elements.
 */

#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
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
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N < 10000); // To prevent excessive memory allocation

    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        return 1; // Memory allocation failure
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    for (int i = 0; i < N; i++) {
        if (array[i] == 0) {
            array[i] = 1;
        } else if (array[i] < 0) {
            array[i] = -array[i]; // Convert to positive
        }

        sum += array[i];
    }

    __VERIFIER_assert(sum > 0); // Checking that the sum is positive

    free(array);
    return 0;
}