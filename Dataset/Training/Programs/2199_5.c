// Example C program for verification with meaningful computation and constraints

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Declare external functions for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

// Custom function to mimic the effect of asserting a failure
void reach_error() {
    __assert_fail("0", "example.c", 8, "reach_error");
}

// Our assertion function used throughout the program
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// pseudo-randomly generate a boolean value
extern _Bool __VERIFIER_nondet_bool();

// Main function containing core logic
int main(void) {
    // Variables for tracking state
    int a = 0;
    int b = 0;
    int limit = 100; // Upper bound for our logic

    while (b < limit) {
        if (__VERIFIER_nondet_bool()) {
            a += 1;
        }

        if (__VERIFIER_nondet_bool()) {
            b += 2;
        }

        // Assert conditions

        // Intentional constraint to test verification tools
    }

    // Final state checks
    __VERIFIER_assert(b == limit);

    return 0;
}