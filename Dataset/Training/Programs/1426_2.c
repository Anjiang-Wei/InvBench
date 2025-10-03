#include <math.h>
#include <stdlib.h>

// External definitions for assertion and error reporting
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Error function for reporting
void reach_error() { __assert_fail("0", "proposed.c", 4, "reach_error"); }

// Non-deterministic integer generator for experimental purposes
extern int __VERIFIER_nondet_int(void);

// Function to assume a condition, abort if not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to assert a condition, call error function if not met
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Main function
int main() {
    int n, i;
    long long sum_n_squared, sum_cubed, cubed_n;

    // Initialize with a non-deterministic value
    n = __VERIFIER_nondet_int();

    // Assume known boundaries for verification
    assume_abort_if_not(n >= 0 && n <= 10);

    sum_n_squared = 0;
    sum_cubed = 0;
    i = 0;

    // Loop to compute sum of squares and cubes up to n
    while (i <= n) {
        sum_n_squared += i * i;

        cubed_n = i * i * i;
        sum_cubed += cubed_n;
    }

    // Check some post condition
    __VERIFIER_assert(sum_cubed - sum_n_squared >= 0);

    // Return from main
    return 0;
}