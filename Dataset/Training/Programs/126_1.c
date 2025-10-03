#include <stdio.h>
#include <stdlib.h>

// Function to simulate assertion failure
void reach_error() {
    printf("Verification failed.\n");
    abort();
}

// Simulated nondeterministic int generator
int __VERIFIER_nondet_int() {
    return rand(); // For demonstration purposes, using rand()
}

// Simulated assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

// Function to simulate verification condition
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int result = 1;
    int counter = 0;

    assume_abort_if_not(a >= 1 && b >= 0);

    // Calculation of a^b using simple iteration
    while (counter < b) {
        result *= a;
        counter++;
    }

    // Verify if result is positive when a is positive and b is non-negative
    __VERIFIER_assert(result >= 1);

    printf("Result of %d^%d = %d\n", a, b, result);
    return 0;
}