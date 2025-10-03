#include <assert.h>
#include <stdio.h>

// Function to simulate non-deterministic integer generation
int __VERIFIER_nondet_int() {
    // For demonstration purposes, we return a fixed value.
    // In a real verification scenario, this could be any integer.
    return 5;
}

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

// Function that calculates the factorial of a number using a loop
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num = __VERIFIER_nondet_int();
    if (!(1 <= num && num <= 10)) {
        return 0; // Constraint on num for analysis
    }

    int fact = factorial(num);

    int expected = 1;
    for (int i = 1; i <= num; ++i) {
        expected *= i;
    }

    // Verification condition: the calculated factorial should match the expected value
    __VERIFIER_assert(fact == expected);

    printf("Factorial of %d is %d\n", num, fact);
    return 0;
}