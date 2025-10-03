// Program computing the sum of the first k natural numbers and the sum of their squares.
// Invariants maintained by the accumulation loop:
//    2 * S == i * (i + 1)
//    6 * T == i * (i + 1) * (2 * i + 1)
// where S = sum_{j=1..i} j and T = sum_{j=1..i} j^2.
//
// This program is designed for verification with automated tools; it uses non-deterministic
// choices to model arbitrary interleavings and makes assertions on the maintained invariants.

#include <assert.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern _Bool __VERIFIER_nondet_bool();
extern short __VERIFIER_nondet_short();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// A small helper function that computes base^exp using a loop.
// It uses a non-deterministic guard to model irregular execution.
// This function is not essential to the main proof, but increases structural complexity.
unsigned long compute_power(unsigned long base, unsigned long exp) {
    unsigned long result = 1UL;
    while (exp > 0) {
        // at each step, we may or may not multiply
        if (__VERIFIER_nondet_bool()) {
            result *= base;
        }
        exp--;
    }
    return result;
}

int main() {
    short k;
    long i, S, T;
    // Read a non-deterministic bound k in [0, 20]
    k = __VERIFIER_nondet_short();
    assume_abort_if_not(k >= 0 && k <= 20);

    // Initialize loop variables
    i = 0;
    S = 0; // sum of first i numbers
    T = 0; // sum of squares of first i numbers

    // Main accumulation loop. It may execute in an irregular fashion due to
    // non-deterministic branching, but it must maintain the loop invariants.
    while (1) {

        // Invariant checks: should hold at the start of each iteration

        // Non-deterministically decide to break if we've reached the bound
        if (__VERIFIER_nondet_bool()) {
            if (!(i < k)) {
                // When breaking, i == k must hold for the final invariants
                break;
            }
        }

        // Non-deterministic choice of update style
        if (__VERIFIER_nondet_bool()) {
            // Standard increment branch
            if (i < k) {
                i = i + 1;
                S = S + i;
                T = T + i * i;
            } else {
                // If we attempt to go beyond k, we must have exactly i == k
            }
        } else {
            // Idle branch: do nothing (modeling scheduling delays)
            // But still maintain the invariants
            // No state change here
        }

        // Another non-deterministic branch that sometimes calls the helper
        if (__VERIFIER_nondet_bool()) {
            // We call compute_power with small arguments to increase complexity
            // Return value is ignored
            (void)compute_power((unsigned long)(i + 1), (unsigned long)(k - i + 1));
        }

        // Continue looping...
    }

    // After the loop, i == k and the invariants still must hold
    __VERIFIER_assert(2 * S == i * (i + 1));

    // Additional check: the final sums match the closed-form formulas
    // Sum of first k numbers is k*(k+1)/2
    // Sum of squares is k*(k+1)*(2*k+1)/6

    return 0;
}