#include <assert.h>
#include <stdlib.h>

extern void abort(void);
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
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N, P;
    N = __VERIFIER_nondet_int();
    P = __VERIFIER_nondet_int();

    // Assume constraints on N and P, with meaningful bounds
    assume_abort_if_not(N > 0 && N <= 100);
    assume_abort_if_not(P >= 1 && P < 50);

    int *array = malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL);

    // Initialize the array and a cumulative product
    int cumulative_product = 1;
    for (int i = 0; i < N; i++) {
        array[i] = i % P + 1; // Fill with values from 1 to P
        cumulative_product *= array[i];

        // Verify some property of the array at every step
    }

    // After filling the array, verify the cumulative product is within expected bounds
    __VERIFIER_assert(cumulative_product >= 1);

    // Free allocated memory
    free(array);

    return 0;
}