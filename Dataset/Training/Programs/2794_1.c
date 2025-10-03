#include <stdio.h>
#include <stdlib.h>

// Function declarations for error reporting
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "proposed.c", 7, "reach_error"); }

// Custom assert that triggers error reporting
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to simulate nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

int main() {
    // Declare program variables
    int length = __VERIFIER_nondet_int();
    if (length <= 0) {
        return 0;
    }

    int *array = malloc(sizeof(int) * length);
    if (array == NULL) {
        return 0; // Fail gracefully if allocation fails
    }

    int i;
    int product = 1;

    // Initialize the array with nondeterministic values and compute their absolute product
    for (i = 0; i < length; i++) {
        array[i] = __VERIFIER_nondet_int();
        if (array[i] < 0) {
            array[i] = -array[i]; // Convert to non-negative
        }
        product *= array[i];
    }

    // Check the constraint that the product should always be non-negative
    __VERIFIER_assert(product >= 0);

    // Clean up
    free(array);

    return 0;
}