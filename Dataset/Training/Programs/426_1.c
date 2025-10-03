#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

extern int __VERIFIER_nondet_int(void);
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

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 1000);

    int *array = malloc(N * sizeof(int));
    int i, largest, second_largest;

    // Initialize array with nondeterministic values
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Assume first two elements are distinct and set largest and second_largest
    assume_abort_if_not(array[0] != array[1]);
    if (array[0] > array[1]) {
        largest = array[0];
        second_largest = array[1];
    } else {
        largest = array[1];
        second_largest = array[0];
    }

    // Iterate through the rest of the array to find largest and second largest
    for (i = 2; i < N; i++) {
        if (array[i] > largest) {
            second_largest = largest;
            largest = array[i];
        } else if (array[i] > second_largest) {
            second_largest = array[i];
        }
    }

    // Verification condition: largest must be greater than or equal to second_largest
    __VERIFIER_assert(largest >= second_largest);

    free(array);
    return 0;
}