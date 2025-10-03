#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

// A function that computes the factorial of a number using recursion
int factorial(int n) {
    if (n <= 1) { // Base case
        return 1;
    } else { // Recursive case
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 5; // You can change this value for different tests
    int fact = factorial(n);

    // Check if the factorial of n is correct using a loop
    int expected_fact = 1;
    for (int i = 2; i <= n; i++) {
        expected_fact *= i;
    }

    printf("Factorial of %d is %d\n", n, fact);

    // Verify that the calculated factorial matches the expected factorial
    __VERIFIER_assert(fact == expected_fact);

    return 0;
}