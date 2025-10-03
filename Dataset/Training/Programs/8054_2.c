#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        exit(1);
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// This program checks for a special property related to sums and products
int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0;
    }
    assume_abort_if_not(n <= 1000);

    int *array = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(array != NULL);

    int sum = 0;
    int product = 1;
    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 1 && array[i] <= 10); // Constraint on elements
        sum += array[i];
        product *= array[i];

        // Check halfway through the loop for some property
        if (i == n / 2) {
        }
    }

    // Check a final property after processing the whole array
    __VERIFIER_assert(sum >= n && product >= 1); // Meaningful checks based on constraints

    free(array);
    return 0;
}