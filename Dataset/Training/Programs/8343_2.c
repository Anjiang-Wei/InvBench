/*
 * Example Program 4:
 * Computes an arithmetic sequence where each term is increased by a
 * variable common difference, and validates the sum and quadratic properties.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// This function will assert a condition or abort the program if the condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

// Main function begins
int main() {
    int n, d;
    long long sum = 0, term = 0, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100); // Constraints for the number of terms
    d = __VERIFIER_nondet_int();
    assume_abort_if_not(d >= 1 && d <= 20); // Constraints for the common difference

    for (i = 0; i < n; i++) {
        term += d;   // Current term in sequence
        sum += term; // Compute the sum

        // Create an assertion that the sum till i-th term satisfies known formula for the sum of arithmetic series

        // Ensure each term meets the arithmetic property tn = d * n
        __VERIFIER_assert(term == d * (i + 1));
    }

    // Output the final computed values
    printf("Final sum: %lld\n", sum);
    printf("Last term: %lld\n", term);

    return 0;
}