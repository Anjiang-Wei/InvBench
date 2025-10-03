#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Calculate the sum of all even numbers and the product of all odd numbers up to a nondeterministic number `n`
int main() {
    int n = __VERIFIER_nondet_int();
    if (!(n >= 0)) {
        return 0; // assume n is non-negative
    }

    int sum_of_even = 0;
    int product_of_odd = 1;
    int i = 0;

    // Iterate over all numbers from 0 to n
    while (i <= n) {
        if (i % 2 == 0) {
            sum_of_even += i;
        } else {
            product_of_odd *= i;
        }
        i++;
    }

    // Some external assumptions to ensure the loop performed correctly
    __VERIFIER_assert(product_of_odd != 0 || (n == 0 || n == 1)); // product_of_odd should not be zero if n > 1

    // Print results for verification
    printf("Sum of even numbers: %d\n", sum_of_even);
    printf("Product of odd numbers: %d\n", product_of_odd);

    return 0;
}