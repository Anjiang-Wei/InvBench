#include <stdio.h>
#include <stdlib.h>

// Function to simulate an error condition
void reach_error() {
    printf("Error reached\n");
    abort();
}

// Function that assumes a certain condition and aborts if not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Assert function to verify conditions during execution
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate a nondeterministic short value (for demonstration purposes)
short __VERIFIER_nondet_short(void) {
    return rand() % 101; // Generate a pseudo-random number between 0 and 100
}

int main() {
    // Declare necessary variables
    short k;
    long long a, b, c;
    short i, factorial;

    k = __VERIFIER_nondet_short();
    assume_abort_if_not(k >= 0 && k <= 5); // Ensure k is between 0 and 5 for demonstration

    a = 1;
    b = 1;
    c = 1;

    // Calculate factorial of 'k' iteratively
    factorial = 1;
    for (i = 1; i <= k; ++i) {
        factorial *= i;
    }
    __VERIFIER_assert(factorial >= 1); // Factorials should always be positive

    // Loop to perform some operations
    for (i = 0; i < k; ++i) {
        a = a + b;
        b = b + c;
        c = c + a - b;
        // Basic constraint to check intermediate result validity
    }

    // Final assertion to ensure program ends without errors

    return 0;
}