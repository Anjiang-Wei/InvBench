#include <stdio.h>
#include <stdlib.h>

// Define the error-reach function
void reach_error() {
    printf("Verification failed!\n");
    exit(1);
}

// A simplified assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

// Non-deterministic integer generator for simulation
int __VERIFIER_nondet_int() {
    return rand() % 50; // returns a random integer between 0 and 49
}

// Program exercises Fibonacci sequence properties
int main() {
    int fib1 = 0;
    int fib2 = 1;
    int fibNext;
    int i = 0;

    // Total number of fibonacci numbers to generate
    int n = __VERIFIER_nondet_int();

    // We restrict n to avoid very large computations for this example
    if (n < 0 || n > 25) {
        return 0;
    }

    // Creating a Fibonacci sequence up to the nth position
    while (i < n) {
        fibNext = fib1 + fib2;

        // Check basic property: fibNext should always be positive
        __VERIFIER_assert(fibNext >= 0);

        fib1 = fib2;
        fib2 = fibNext;
        i++;
    }

    // Verify the last index of sequence

    printf("Fibonacci number at position %d is: %d\n", n, fibNext);
    return 0;
}