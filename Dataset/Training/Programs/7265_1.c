#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
extern void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define SIZE 100

int main() {
    int i, max_value = -1, min_value = 2147483647;
    int *array = malloc(sizeof(int) * SIZE);

    // Array initialization with unknowns
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Processing loop: find the max and min value in the array
    for (i = 0; i < SIZE; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
        if (array[i] < min_value) {
            min_value = array[i];
        }
    }

    // Check to see if our processing is in a reasonable range
    __VERIFIER_assert(max_value >= min_value);

    free(array);
    return 0;
}