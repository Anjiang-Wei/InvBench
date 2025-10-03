#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Function to trigger an error
void reach_error() {
    assert(0);
}

// Example value generation function, for demonstration
int __VERIFIER_nondet_int() {
    return rand() % 100; // Generate a pseudo-random integer
}

// A simple verification function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Check if a number is even
int is_even(int num) {
    return num % 2 == 0;
}

// Main computational function
int compute(int n) {
    int sum = 0;
    int i;

    for (i = 0; i < n; ++i) {
        if (is_even(i)) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int(); // Get a non-deterministic integer value
    if (n < 10) {
        n = 10; // Ensure n has a minimal value for meaningful computation
    }

    int result = compute(n);

    // Ensure result is reasonable (a basic, implicit postcondition)
    __VERIFIER_assert(result >= 0);

    // Output the result
    printf("Sum of even numbers less than %d is: %d\n", n, result);

    return 0;
}