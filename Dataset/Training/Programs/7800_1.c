// New C program for automated verification

#include <stdio.h>

// External functions for abort and assert, typically used in verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Reach error function for error assertion
void reach_error() { __assert_fail("0", "custom-program.c", 7, "reach_error"); }

// Custom assert function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function simulating non-deterministic integer input typically used in verification
extern int __VERIFIER_nondet_int(void);

// Assumption function for program properties
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, sum, product, i;

    // Non-deterministic integer n representing the loop bound
    n = __VERIFIER_nondet_int();
    // Constraint on n to be between 0 and 10 for feasible verification
    assume_abort_if_not(n >= 0 && n <= 10);

    sum = 0;
    product = 1;
    i = 1;

    while (i <= n) {
        sum += i;     // Accumulating the sum of natural numbers
        product *= i; // Calculating the product of natural numbers
        i++;
    }

    printf("Sum is: %d, Product is: %d\n", sum, product);

    // Verification condition: product should always be greater than or equal to n!
    // Sum should be n*(n+1)/2 (as a trivial verification target)
    __VERIFIER_assert(product >= 1);

    return 0;
}