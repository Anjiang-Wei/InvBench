#include <assert.h>
#include <limits.h>

// External functions for nondeterministic inputs and verification
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to verify correctness conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main(void) {
    int m, n;
    int sum, product;

    // Getting nondeterministic values for m and n
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Constraint to avoid overflow and ensure positive values
    assume_abort_if_not(m >= 0 && n >= 0 && m < 1000 && n < 1000);

    sum = 0;
    product = 1;

    // Loop for calculating sum of the first n natural numbers
    for (int i = 0; i < n; ++i) {
        sum += i + 1;
    }

    // Loop for computing the factorial of m
    while (m > 0) {
        product *= m;
        m--;
    }

    // Asserting that the sum of first n numbers is correctly calculated
    __VERIFIER_assert(sum == n * (n + 1) / 2);

    // The above program attempts to compute the factorial of 'm' and the
    // sum of the first 'n' natural numbers using different loop constructs
    return 0;
}