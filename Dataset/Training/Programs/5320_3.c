#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to simulate nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    // State variables
    int a = 0, b = 0, c = 0;
    int n = 10; // Number of iterations in loops, can be nondeterministic

    // Assume initial conditions
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0);

    // Loop with assertions and conditions
    for (int i = 0; i < n; i++) {
        // Simulate some computation
        a += i;
        b += a;
        c += b;

        // Constraint conditions
        __VERIFIER_assert(c >= b);

        // Check a property that should hold
        if (i > 0) {
        }

        // Break condition to simulate real-world constraints
        if (a > limit) {
            break;
        }
    }

    // Final assertion

    return 0;
}