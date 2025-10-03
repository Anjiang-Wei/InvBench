#include <stdlib.h>

// Function prototypes for error signaling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function to indicate a reach error
void reach_error() { __assert_fail("0", "example_program.c", 7, "reach_error"); }

// Function to assert a condition, reaching an error if false
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Prototype for a non-deterministic integer return
extern int __VERIFIER_nondet_int(void);

// Main function
int main() {
    int limit = __VERIFIER_nondet_int();
    int product = 1;

    // Ensure a reasonable value for limit
    if (limit <= 0 || limit > 1000000) {
        return 0;
    }

    for (int i = 2; i <= limit; i++) {
        // Incrementally calculate the product of numbers from 1 to limit
        // To avoid overflow, do not multiply if product is too large
        if (product * i > 2147483647 || product * i < 0) {
            product = product;
        } else {
            product *= i;
        }
    }

    // Use the result in a meaningful assertion that should hold
    __VERIFIER_assert(product >= 1);

    return 0;
}