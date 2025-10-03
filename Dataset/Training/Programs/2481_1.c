#include <stdio.h>
#include <stdlib.h>

// Declare external functions for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function to trigger an error in verification
void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }

// Function for verification assertions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to simulate non-deterministic integer generation
extern int __VERIFIER_nondet_int(void);

// Assumption function to terminate if condition is false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Main function of the program
int main(void) {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    c = 0;

    // Begin a loop that will manipulate 'a' and 'b'
    while (a > 0 && b > 0) {
        if (a > b) {
            a -= b; // Decrease 'a' by 'b'
        } else {
            b -= a; // Decrease 'b' by 'a'
        }
        c++; // Count the number of operations
    }

    // Expect that one of 'a' or 'b' should be zero after the loop exits
    __VERIFIER_assert(a == 0 || b == 0);

    // Print the result of computation for clarity
    printf("Number of operations: %d\n", c);
    printf("Final values - a: %d, b: %d\n", a, b);

    return 0;
}