#include <stdio.h>
#include <stdlib.h>

// Assertion function for verification
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Sample function to calculate factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    // Variables for controlling the loop and storing results
    int n = 5; // Calculate factorial of 5
    int result = 1;
    int expected = 120; // 5! = 120
    int i;

    // Loop to compute factorial iteratively
    for (i = 1; i <= n; i++) {
        result *= i;
    }

    // Assert the result is what we expect
    __VERIFIER_assert(result == expected);

    // Print the result for verification purpose
    printf("Factorial of %d is %d\n", n, result);

    return 0;
}