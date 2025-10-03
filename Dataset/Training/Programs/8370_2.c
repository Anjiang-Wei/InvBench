#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int(); // number of elements
    assume_abort_if_not(n > 0);      // we require a positive number of elements

    int *array = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(array != NULL);

    int i;
    int sum = 0;
    int product = 1;

    // Populate the array with non-deterministic non-negative integers
    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate sum and product
    for (i = 0; i < n; i++) {
        assume_abort_if_not(array[i] >= 0); // Making sure all elements are non-negative
        sum += array[i];
        product *= (array[i] + 1); // to avoid multiplying by zero
    }

    // Arbitrary condition to check
    __VERIFIER_assert(product > 0);

    free(array);
    return 0;
}