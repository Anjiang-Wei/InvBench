#include <stdio.h>
#include <stdlib.h>

/*
 * Automated verification friendly program
 * This program calculates a simple cumulative operation
 * on an array of integers with dynamic constraints.
 */

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 1000);

    int *array = (int *)malloc(sizeof(int) * N);
    if (!array) {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        array[i] = i + 1; // Initialize the array
        sum += array[i];  // Calculate the sum simultaneously
    }

    int product = 1;
    for (int i = 0; i < N; i++) {
        product *= array[i]; // Compute product of all elements
    }

    // Verification condition: if N=3, then sum=6 and product=6 (triangular number case)
    // This serves as a simple logical verification condition that can fail for other values of N
    if (N == 3) {
        __VERIFIER_assert(sum == 6 && product == 6);
    }

    free(array);
    return 0;
}