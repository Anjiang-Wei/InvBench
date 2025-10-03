#include <stdio.h>
#include <stdlib.h>

// Error assertion function
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "pattern_example.c", 10, "reach_error"); }

// Function to simulate non-deterministic integer input
extern int __VERIFIER_nondet_int(void);

// Function to assert conditions, calls reach_error if condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Assumption function
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to compute the factorial of a number
int factorial(int n) {
    if (n < 0) {
        return -1; // Invalid input
    }
    if (n == 0) {
        return 1; // Base case
    }
    return n * factorial(n - 1);
}

int main() {
    // Non-deterministic input
    int n = __VERIFIER_nondet_int();

    // Constrain the input value
    assume_abort_if_not(n >= 0 && n <= 10);

    // Compute factorial
    int fact = factorial(n);

    // Loop for verification purposes
    int counter = 0;
    int sum = 0;
    while (counter < n) {
        sum += counter;
        counter++;
    }

    // Assert that factorial computation is correct for the constrained input
    if (n > 0) {
    } else {
        __VERIFIER_assert(fact == 1);
    }

    // Output result
    printf("Factorial of %d is %d\n", n, fact);

    return 0;
}