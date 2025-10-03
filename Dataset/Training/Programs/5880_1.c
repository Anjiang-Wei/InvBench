#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }

// This function is similar to the reach_error function in the examples
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int main() {
    // Arbitrary boundaries for nondeterministic values
    int N = __VERIFIER_nondet_int();
    if (N < 1 || N > 10) {
        // Assumption to restrict N to a meaningful range
        return 0;
    }

    int array[N];
    int sum = 0;
    int expected_sum = N * (N - 1) / 2; // The expected sum of first N natural numbers

    // Initializing the array with first N natural numbers
    for (int i = 0; i < N; i++) {
        array[i] = i;
        sum += array[i];
    }

    // Verify that the sum of elements is as expected
    __VERIFIER_assert(sum == expected_sum);

    // Compute some property involving the elements in the array
    int product = 1;
    for (int i = 0; i < N; i++) {
        product *= (array[i] + 1); // Avoid multiplying by zero
    }

    // Check the final product for some condition

    printf("Sum = %d, Product = %d\n", sum, product);
    return 0;
}