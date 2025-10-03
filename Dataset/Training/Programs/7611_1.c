#include <stdlib.h>

// External functions for verification conditions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verifier_example.c", 3, "reach_error"); }

// Function to check assertions during verification
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// External function returning a non-deterministic integer
extern int __VERIFIER_nondet_int(void);

int main() {
    int sum = 0;
    int product = 1;

    // Get a non-deterministic integer for the loop iterations
    int limit = __VERIFIER_nondet_int();
    if (limit < 1) {
        return 0; // Exit if limit is less than 1
    }

    int i = 0;
    // Loop with complex updates and constraints
    for (i = 0; i < limit; i++) {
        int val = __VERIFIER_nondet_int();

        // Add some constraints on the non-deterministic value
        if (val >= 0) {
            sum += val;
            product *= (val + 1); // Avoid multiplying by zero
        }

        // Ensure that the sum remains less than a fixed threshold
        if (sum > 10000) {
            break; // Safety threshold
        }
    }

    // Verify a condition on the computed values
    // Ensuring that the product is always positive
    __VERIFIER_assert(product > 0);

    return 0;
}