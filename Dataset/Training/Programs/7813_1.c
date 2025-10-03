/*
 * Program for validating parity manipulation and demonstrating constraint conditions
 */

#include <limits.h>  // For INT_MAX
#include <stdbool.h> // For boolean data type
#include <stdlib.h>  // For malloc

extern void abort(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 100);

    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        return 1; // Allocation failed
    }

    int odd_count = 0, even_count = 0;

    // Fill the array and compute odd_even parity information
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        if (array[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Constraint: Check that the count of even numbers plus the count of odd numbers equals N
    __VERIFIER_assert(odd_count + even_count == N);

    // Parity modification loop
    for (int i = 0; i < N; i++) {
        if ((i % 2 == 0 && array[i] % 2 != 0) || (i % 2 != 0 && array[i] % 2 == 0)) {
            array[i] = array[i] + 1; // adjust parity
            continue;
        }
        if (i % 2 == 0 && array[i] % 2 == 0) {
            array[i]++;
            even_count--;
            odd_count++;
        }
    }

    // Final constraint verification
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
        } else {
        }
    }

    free(array);
    return 0;
}