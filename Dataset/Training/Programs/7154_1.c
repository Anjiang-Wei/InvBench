#include <assert.h>
#include <stdio.h>

// Function prototypes
void reach_error(void);

// Verifier function for checking conditions during runtime
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate a possible external input as a non-deterministic integer
extern int __VERIFIER_nondet_int(void);

// Dummy function to simulate an assertion failure (as reach_error)
void reach_error(void) {
    assert(0);
}

/*
This program utilizes a modified arithmetic sequence under certain constraints.
It initializes variables x, y, z which provide constraints and conditions.
The loop iteratively computes modified values of x and y, asserting relationships among them.
*/

int main() {
    // Variable Declarations
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    // Ensures initial conditions are met
    if (!(x > 0 && y > 0 && z > 0)) {
        return 0;
    }

    // Counter for the loop
    int loop_counter = 0;

    // Loop iterating as long as the condition is true
    while (x < 1000) {
        // Make some calculations
        x = x + y;
        y = y + z;
        z = z + 1;

        // Verify a complex condition
        __VERIFIER_assert(x + y - z > 0);

        // Increment the loop counter
        loop_counter++;

        // Conditional break to prevent long unintended execution
        if (loop_counter > 1000) {
            break;
        }
    }

    // Check a final assertion after loop execution

    // Return statement for successful execution
    return 0;
}