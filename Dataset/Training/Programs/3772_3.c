#include <stdio.h>

// Function to simulate an assertion failure
void reach_error() {
    printf("A verification error occurred.\n");
    abort();
}

// Aborts if condition is false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assertion function to verify conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

// Simulate non-deterministic integer generation for testing
int __VERIFIER_nondet_int() {
    return rand() % 100; // Random value for simplicity
}

int main() {
    int a, b, result;
    a = __VERIFIER_nondet_int(); // Non-deterministic input
    b = __VERIFIER_nondet_int(); // Non-deterministic input

    assume_abort_if_not(a >= 0 && b >= 0);

    result = 0;
    int counter = 0;

    // Loop to perform multiplication by repeated addition
    while (counter < b) {
        result += a;
        counter++;
    }

    // Verify the result of multiplication operation

    // Loop to check square root approximation with the condition
    counter = 0;
    int approx_sqrt = 0;

    while (approx_sqrt * approx_sqrt <= a) {
        approx_sqrt++;
        counter++;
        if (counter > a) {
            break; // Break to prevent infinite loop in case of logic error
        }
    }

    // Check if estimated square root approximation is logical
    __VERIFIER_assert(approx_sqrt * approx_sqrt > a);

    printf("Multiplication of %d and %d is %d\n", a, b, result);
    printf("Approximate square root of %d is %d\n", a, approx_sqrt - 1);

    return 0;
}