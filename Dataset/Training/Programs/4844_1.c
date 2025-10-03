#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0 || N > 1000) {
        return 1;
    }

    int sum = 0;
    int product = 1;
    int i;

    // Allocate memory for N integers
    int *array = malloc(N * sizeof(int));
    if (array == NULL) {
        return 1;
    }

    // Initialize the array with nondeterministic values
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Process array elements
    for (i = 0; i < N; i++) {
        if (array[i] % 2 == 0) {
            sum += array[i]; // Sum all even numbers
        } else {
            product *= array[i]; // Multiply all odd numbers
            if (product == 0) {  // Simple check to prevent overflow in product
                reach_error();
                abort();
            }
        }
    }

    // Ensure that sum is a multiple of 2 and product is not zero
    __VERIFIER_assert(sum % 2 == 0);

    free(array);
    return 0;
}