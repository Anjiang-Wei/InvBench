#include <limits.h>
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
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 1000000); // Ensure N is positive and within a reasonable range

    int i, positive_sum = 0, negative_count = 0;
    int *array = malloc(sizeof(int) * N);
    assume_abort_if_not(array != 0); // Ensure memory allocation is successful

    // Initialize the array with random numbers between -100 and 100
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int() % 201 - 100;
    }

    // Process the array to calculate positive sum and count negative numbers
    for (i = 0; i < N; i++) {
        if (array[i] > 0) {
            positive_sum += array[i];
        } else if (array[i] < 0) {
            negative_count++;
        }
    }

    // Check some property for testing
    __VERIFIER_assert(positive_sum >= 0);   // Sum of positives should always be non-negative
    __VERIFIER_assert(negative_count <= N); // Negative count should never be more than total elements

    free(array);
    return 0;
}