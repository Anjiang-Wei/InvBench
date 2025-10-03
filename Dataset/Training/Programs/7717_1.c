#include <assert.h>
#include <stdio.h>

// Function to trigger a reach error indication
void reach_error(void) { assert(0); }

// External nondeterministic integer generator
extern int __VERIFIER_nondet_int(void);

// Assert macro for verifications
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Custom external function for aborting conditions
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int(); // Nondeterministic input
    int b = __VERIFIER_nondet_int(); // Nondeterministic input

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    int sum = 0;
    int squared_diff = 0;
    int n = 0;

    // Compute a pseudo-mathematical sequence
    while (n < 100) {
        if (n % 5 == 0) {
            sum += n;
        } else {
            squared_diff += (a - b) * (a - b);
        }

        // Ensuring monotonic increase in sum and bounded growth in squared_diff
        __VERIFIER_assert(sum >= 0);

        if (squared_diff > 10000) {
            break;
        }

        n++;
    }

    // Outcomes of final secured assertions

    // Program must eventually be concluded safely
    if (n < 100) {
        printf("Exited early at iteration: %d\n", n);
    } else {
        printf("Successfully iterated 100 times\n");
    }

    return 0;
}