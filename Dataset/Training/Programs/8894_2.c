#include <stdio.h>

// Function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Error function that triggers a verification error
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

// Custom assertion function for verification
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function simulating nondeterministic input
extern int __VERIFIER_nondet_int(void);

int main(void) {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assume a constraint to ensure n is reasonable
    if (n < 1 || n > 10) {
        return 0; // Early exit if n is out of bounds
    }

    // Loop to compute the sum of numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // Verification conditions:
    // 1. Verify the computed sum is accurate using the formula n(n + 1)/2

    // 2. Verify a simple property of the product
    // Verify that the product is always positive for the given range
    __VERIFIER_assert(product > 0);

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}