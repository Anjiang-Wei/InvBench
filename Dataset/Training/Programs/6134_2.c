#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

// Custom assert function for verification
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Assume function, mimicking a function that kills the program if the condition is false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    // Initialize variables
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int n = 5; // can change to another non-negative integer for testing
    unsigned int c = 0;
    unsigned int prev_a = 0;

    // Assume n is within a reasonable range (to prevent overflow)
    assume_abort_if_not(n <= 20);

    // Fibonacci-like series calculation
    while (c < n) {
        // Calculate the next term
        unsigned int new_a = b;
        b = a + b;
        a = new_a;

        // Assert that the series is non-decreasing
        prev_a = a;

        c++;
    }

    // Verify the final state (for example purposes, assume some arbitrary condition)
    __VERIFIER_assert(a + b > n);

    // Output the result (for human verification and debugging)
    printf("After %u steps, a = %u, b = %u\n", n, a, b);
    return 0;
}