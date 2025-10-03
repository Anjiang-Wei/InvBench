#include <stdio.h>
#include <stdlib.h>

// Function declarations for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

// Function to abort if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Placeholder for an external, non-deterministically chosen integer
extern int __VERIFIER_nondet_int(void);

// Function for custom assertions
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Constraint to ensure that n is a reasonable array size
    assume_abort_if_not(n > 0 && n < 1000);

    // Allocate two integer arrays of size n
    int *x = (int *)malloc(sizeof(int) * n);
    int *y = (int *)malloc(sizeof(int) * n);

    // Ensure malloc was successful
    assume_abort_if_not(x != NULL && y != NULL);

    int sum = 0;

    // Initialize arrays and compute a running sum
    for (int i = 0; i < n; i++) {
        x[i] = __VERIFIER_nondet_int();
        y[i] = __VERIFIER_nondet_int();
        sum += x[i] + y[i];
    }

    // Assign the sum to each element of y
    for (int i = 0; i < n; i++) {
        y[i] = sum;
    }

    // Verify that all elements of y have the value of the final sum
    for (int i = 0; i < n; i++) {
        __VERIFIER_assert(y[i] == sum);
    }

    // Free allocated memory
    free(x);
    free(y);

    return 0;
}