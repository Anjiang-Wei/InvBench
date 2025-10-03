#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
void reach_error() { __assert_fail("0", "custom.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, x, y, z, i;
    int result = 0;

    // Non-deterministically assign a positive integer value to `n`
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100);

    // Initialize variables
    x = 0;
    y = 1;
    z = 1;

    // Begin a loop that simulates a series sequence
    for (i = 0; i < n; i++) {
        // Ensure the sequence maintains calculation constraints
        __VERIFIER_assert(z == x + y);

        // Calculate new values in the sequence
        result += z;
        x = y;
        y = z;
        z = x + y;
    }

    // Validate the result with an adjustment based on loop logic

    return 0;
}