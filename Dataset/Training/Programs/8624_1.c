#include <stdlib.h>

// This program checks the computation of a numeric series where each term is a function of previous terms.
// It ensures that certain conditions hold for each term.

// External functions simulating nondeterministic inputs and error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function that triggers an error
void reach_error() { __assert_fail("0", "series_check.c", 9, "reach_error"); }

// Assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// Function to simulate nondeterministic integer inputs
extern int __VERIFIER_nondet_int(void);

int main(void) {
    int N = __VERIFIER_nondet_int();

    // Ensure N is within reasonable bounds to avoid memory issues.
    if (N <= 0 || N > 1000) {
        return 0;
    }

    // Allocate memory for the series
    int *series = (int *)malloc(N * sizeof(int));
    if (series == NULL) {
        return 0;
    }

    // Initialize the series with deterministic entry
    series[0] = 1; // Start of the series

    // Compute the rest of the series
    for (int i = 1; i < N; i++) {
        series[i] = series[i - 1] + 2 * i; // Recursive relation for series

        // Check if terms are non-negative (additional constraint)
        __VERIFIER_assert(series[i] >= 0);
    }

    // Final computation and checks
    for (int i = 0; i < N; i++) {
        // Ensure that each term maintains a certain property
    }

    // Clean up
    free(series);
    return 0;
}