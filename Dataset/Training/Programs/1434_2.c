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
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int i, sum_odd = 0, product_even = 1;

    // Assume n is a positive integer
    assume_abort_if_not(n > 0);

    // Allocate memory for an array of size n
    int *arr = malloc(n * sizeof(int));

    // Initialize array with nondet values
    for (i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Process the array
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            product_even *= arr[i] != 0 ? arr[i] : 1; // Avoid multiplying by zero
        } else {
            sum_odd += arr[i];
        }
    }

    // Ensure that sum_odd is non-negative and product_even is non-zero
    __VERIFIER_assert(product_even != 0);

    free(arr);
    return 0;
}