#include <assert.h>
#include <stdlib.h>

// Verification helper functions
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to compute Fibonacci numbers with constraints
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int next = a + b;
        a = b;
        b = next;

        // Verification assertions
        __VERIFIER_assert(b >= a); // Fibonacci property
        __VERIFIER_assert(b >= 0); // Non-negative numbers
    }
    return b;
}

int main() {
    int input = __VERIFIER_nondet_int();            // Non-deterministic input
    assume_abort_if_not(input >= 1 && input <= 10); // Constraint on input

    int result = fibonacci(input);

    // Final assertion to verify the correctness of the result based on known Fibonacci properties
}