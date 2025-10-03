#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
void reach_error(void);
void assume_abort_if_not(int cond);
void __VERIFIER_assert(int cond);
int __VERIFIER_nondet_int(void);

/* Error function, called when an assertion fails */
void reach_error() {
    abort();
}

/* Assumption function: triggers abort if condition is false */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Assertion function: checks condition and calls reach_error on failure */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Nondeterministic integer generator */
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // A deterministic stub to represent nondeterministic behavior
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);     // Ensure N is positive
    assume_abort_if_not(N <= 1000); // Assume N is within a reasonable range

    int *array = (int *)malloc(N * sizeof(int));
    if (!array) {
        return 1; // Allocation failed
    }

    // Initialize array
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int() % 50; // Fill with random numbers % 50
    }

    int sum = 0;
    int product = 1;
    for (int i = 0; i < N; i++) {
        if (array[i] % 3 == 0) { // If number is divisible by 3, add to sum
            sum += array[i];
        } else if (array[i] % 3 == 1) { // If remainder is 1, multiply into product
            product *= array[i];
        }
    }

    // Check a condition involving sum and product
    if (N > 10) { // Only perform check if N is significant
        __VERIFIER_assert((sum % 3 == 0) || (product % 3 == 1));
    }

    free(array);
    return 0;
}