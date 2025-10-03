#include <assert.h>
#include <stdlib.h>

// Custom error function
void reach_error(void) { assert(0); }

// Function to simulate non-deterministic behavior for integers
extern int __VERIFIER_nondet_int(void);
// Function to simulate non-deterministic behavior for booleans
extern _Bool __VERIFIER_nondet_bool(void);

// Custom assert function that calls reach_error on false conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Helper function to use with non-deterministic conditions
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    // Non-deterministically initialize two integer variables
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume some initial conditions for the variables to narrow down inputs for analysis
    assume_abort_if_not(a >= 0 && a <= 1000);
    assume_abort_if_not(b >= 0 && b <= 1000);

    int sum = 0;
    int product = 1;

    // Main loop with non-deterministic continuation
    while (__VERIFIER_nondet_bool()) {
        sum += a;
        product *= b;

        // Modify a and b in the loop to ensure the computation progresses
        a = (a + 1) % 1000;
        b = (b + 2) % 1000;

        // Break condition for demonstration purposes
        if (sum > 10000 || product == 0) {
            break;
        }
    }

    // Assert condition after loop termination
    __VERIFIER_assert(sum >= 0 && product >= 0);

    return 0;
}