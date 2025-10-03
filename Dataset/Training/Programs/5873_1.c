#include <assert.h>
#include <limits.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
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
    int max_val, i, found;

    max_val = __VERIFIER_nondet_int();
    if (max_val <= 0) {
        return 0;
    }
    assume_abort_if_not(max_val <= 2147483647);

    int *array = (int *)malloc(sizeof(int) * max_val);
    if (!array) {
        return 0;
    }

    int target = __VERIFIER_nondet_int();

    // Initialize the array with sequential values starting from 1
    for (i = 0; i < max_val; i++) {
        array[i] = i + 1;
    }

    found = 0;

    // Search for the target in the array
    for (i = 0; i < max_val; i++) {
        if (array[i] == target) {
            found = 1;
            break;
        }
    }

    // Verify that the target is indeed in the array, or not
    __VERIFIER_assert(found ? array[i] == target : found == 0);

    free(array);
    return 0;
}