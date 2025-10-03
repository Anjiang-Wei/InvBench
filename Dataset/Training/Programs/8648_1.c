#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Reach error\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0;
    }

    // Initialize variables
    int sum = 0;
    int product = 1;
    int counter = 0;

    while (counter < n) {
        __VERIFIER_assert(sum >= 0);     // Sum should always be non-negative
        __VERIFIER_assert(product >= 1); // Product should always be positive

        sum += counter;           // Increment sum by current counter value
        product *= (counter + 1); // Multiply product by (counter + 1)
        counter++;                // Increment counter
    }

    // Check conditions after the loop
    __VERIFIER_assert(sum >= 0 && product >= 1);

    // Output results, used here to verify correct implementation
    printf("Sum of numbers from 0 to %d is %d\n", n - 1, sum);
    printf("Product of numbers from 1 to %d is %d\n", n, product);
    return 0;
}