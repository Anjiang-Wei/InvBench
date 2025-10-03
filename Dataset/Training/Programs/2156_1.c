#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size > 0);
    assume_abort_if_not(size <= 1073741824 / sizeof(int)); // Ensure memory allocation does not exceed limits

    int *array = malloc(sizeof(int) * size);
    assume_abort_if_not(array != NULL);

    // Initialize the array with random values.
    for (int i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int count_positive = 0;
    int count_negative = 0;

    // Process the array, counting positive and negative numbers.
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            count_positive++;
        } else if (array[i] < 0) {
            count_negative++;
        }
    }

    // Logic: In an array of size N, the total count of positives and negatives cannot exceed N.
    __VERIFIER_assert(count_positive + count_negative <= size);

    free(array);
    return 0;
}