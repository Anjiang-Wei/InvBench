// New C program for verification using automated tools

#include <stdio.h>
#include <stdlib.h>

// Function for reaching an error state
void reach_error() {
    printf("Error reached\n");
    exit(1);
}

// Function to simulate non-deterministic integer
int __VERIFIER_nondet_int(void) {
    return rand() % 10; // Simulating with a random number for example
}

// Function to abort if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Simulates assertions to reach an error if a condition is false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main program logic
int main() {
    int n, sum, product, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 5);

    sum = 0;
    product = 1;
    i = 1;

    while (i <= n) {
        sum += i;
        product *= i;
    }

    // Check final conditions without asserting invariants in the loop
    __VERIFIER_assert(sum == (n * (n + 1)) / 2);    // Verify sum of first n natural numbers
    __VERIFIER_assert(product == 0 || product > 0); // Verify product has valid value

    return 0;
}