#include <stdio.h>
#include <stdlib.h>

// Define custom error handling
extern void abort(void);
void reach_error() {
    printf("Assertion failed\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Define a nondeterministic input function simulation
int __VERIFIER_nondet_int() {
    return rand() % 20; // Limiting the range for the sake of analysis
}

int main() {
    int n, sum = 0, product = 1; // Initialize sum and product
    n = __VERIFIER_nondet_int();

    // Perform verification that n is within [1, 10] range
    if (n < 1 || n > 10) {
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Verify sum is correct for numeric progression

        // Verify product is positive (simple sanity check)
    }

    // Extra check if loops finish
    __VERIFIER_assert(product > 0); // Product of the first n natural numbers can't be zero

    printf("Sum of first %d natural numbers is: %d\n", n, sum);
    printf("Product of first %d natural numbers is: %d\n", n, product);

    return 0;
}