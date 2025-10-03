#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size > 0 && size < 1000); // Constraint to keep size within feasible limits

    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        return 1; // Check for successful allocation
    }

    int i;
    long long product = 1;

    // Initialize array elements
    for (i = 0; i < size; i++) {
        array[i] = 1 + __VERIFIER_nondet_int() % 10; // Random number between 1 and 10
    }

    // Calculate the product of all array elements
    for (i = 0; i < size; i++) {
        if (array[i] > 5) {
            product *= array[i];
        }
    }

    // Constraint condition: check if product is positive
    __VERIFIER_assert(product > 0);

    free(array);
    return 0;
}