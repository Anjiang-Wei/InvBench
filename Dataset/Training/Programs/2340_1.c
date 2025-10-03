#include <stdio.h>
#include <stdlib.h>

// Function declarations for potential verification hooks
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Function to simulate abort if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function simulating a verification assert
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

#define MAX_ITERATIONS 100

long long compute_series(int z, int limit) {
    long long sum = 0;
    long long current_term = 1;
    int iteration_count = 0;

    // Loop to compute the series while respecting a maximum iteration constraint
    while (iteration_count < MAX_ITERATIONS) {
        iteration_count++;
        if (iteration_count >= limit) {
            break;
        }
        sum += current_term;
        current_term *= z;

        // Ensure the current term does not exceed predefined limits to prevent overflow
        assume_abort_if_not(current_term >= 0);
    }

    return sum;
}

int main() {
    int z, n;
    long long result;

    // Initialize variables with non-deterministic values
    z = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Constrain the inputs to prevent extreme or undefined behavior
    assume_abort_if_not(z >= 0 && z <= 5);
    assume_abort_if_not(n >= 0 && n <= 10);

    // Compute a series based on the input parameters
    result = compute_series(z, n);

    // Check a basic condition
    __VERIFIER_assert(result >= 0);

    // Return successfully
    return 0;
}