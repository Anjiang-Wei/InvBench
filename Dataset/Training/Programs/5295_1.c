#include <stdio.h>
#include <stdlib.h>

// Function prototypes for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "custom_program.c", 5, "reach_error");
}

// Assumption and assertion macros
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

// Non-deterministic input functions
extern int __VERIFIER_nondet_int(void);

int main() {
    // Get non-deterministic input for n
    int n = __VERIFIER_nondet_int();

    // Assume n to be in a suitable range, otherwise abort
    assume_abort_if_not(n >= 0 && n < 100);

    int sum = 0;
    int product = 1;
    int factor = __VERIFIER_nondet_int();

    // Assume factor to be positive
    assume_abort_if_not(factor > 0 && factor < 10);

    // Iterate over the range
    for (int i = 1; i <= n; ++i) {
        sum += i;          // Adding i to sum
        product *= factor; // Calculating product with a factor
    }

    // Check that calculations followed constraints
    __VERIFIER_assert(sum >= 0);    // Sum should be non-negative
    __VERIFIER_assert(product > 0); // Product should be positive

    // Output some values for sanity check (not for verification)
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}