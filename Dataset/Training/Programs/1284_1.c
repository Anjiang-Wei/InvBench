#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

#define MAX_SIZE 1000000

int main() {
    int array[MAX_SIZE];
    int i, n, sum = 0, product = 1;

    n = __VERIFIER_nondet_int();
    if (n < 1 || n > MAX_SIZE) {
        return 0;
    }

    // Fill the array with non-deterministic values
    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate the sum and product of the array elements
    for (i = 0; i < n; i++) {
        sum += array[i];
        if (array[i] != 0) {
            product *= array[i];
        }
    }

    // Perform a verification check
    __VERIFIER_assert(sum >= n || product != 0);

    // Output results (for clarity, though not needed for verification)
    printf("Sum: %d, Non-zero Product: %d\n", sum, product);

    return 0;
}