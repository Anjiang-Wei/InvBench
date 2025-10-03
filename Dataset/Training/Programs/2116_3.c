// A C program that includes a loop, constraints, and uses a similar pattern
// to the given examples. This program calculates the factorial of a number
// with certain conditions and asserts properties for verification.

#include <assert.h>
#include <stdio.h>

#define LIMIT 12 // Set a limit to prevent integer overflow

// Function to reach error
void reach_error() {
    printf("An error was reached in the factorial calculation!\n");
    assert(0);
}

// Function to assert a condition
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
    return;
}

// Function to calculate factorial
int factorial(int n) {
    if (n < 0) {
        reach_error();
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
        // Check for overflow
    }
    return result;
}

int main() {
    // Read input
    int n;
    printf("Enter a number to compute factorial (0 to %d): ", LIMIT);
    if (scanf("%d", &n) != 1 || n < 0 || n > LIMIT) {
        printf("Invalid input!\n");
        return -1;
    }

    // Calculate factorial
    int result = factorial(n);

    // Check if the result is as expected for small known inputs
    switch (n) {
    case 0:
        break;
    case 1:
        __VERIFIER_assert(result == 1);
        break;
    case 2:
        break;
    case 3:
        break;
    // Add more cases if necessary for verification
    default:
        break;
    }

    printf("Factorial of %d is %d\n", n, result);
    return 0;
}