#include <stdio.h>
#include <stdlib.h>

// Function prototypes for external verification tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Function prototypes for aborting execution
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Main function
int main() {
    // Variables
    int x = 5;
    int y = 10;
    int z = 15;
    int target = 100;
    int sum = 0;

    // Constraint condition
    assume_abort_if_not(x > 0 && y > 0 && z > 0);

    // Loop with meaningful computations
    while (sum < target) {
        sum = x + y + z;

        // Update values in each iteration
        if (sum < target) {
            x += 1;
            y += 2;
            z += 3;
        }

        // Verification conditions
        __VERIFIER_assert(x > 0 && y > 0 && z > 0);
    }

    // Final assertions

    return 0;
}