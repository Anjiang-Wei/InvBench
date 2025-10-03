#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

#define MAX_SIZE 512

int main() {
    unsigned int size = __VERIFIER_nondet_uint();

    if (size > MAX_SIZE) {
        return 0; // Avoids unmanageable array sizes
    }

    int array[size];
    unsigned int i, j;
    int sum = 0;

    // Fill the array with non-deterministic values
    for (i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate the sum of elements greater than zero
    for (i = 0; i < size; i++) {
        if (array[i] > 0) {
            sum += array[i];
        }
    }

    // Example validation: ensuring the sum is non-negative

    // Another computation using nested loops for at least linear complexity
    int product = 1;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (array[j] < 2 && array[j] > -2) {
                product *= array[j] + 1; // Simple computation to induce constraints
                if (product == 0) {
                    product = 1; // Ensure product does not freeze at zero
                }
            }
        }
    }

    // Validate some property of the product
    __VERIFIER_assert(product != -1);

    // Output the results of our computations
    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}