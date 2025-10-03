#include <assert.h>

// Prototypes for external functions to mimic nondeterminism
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

// Function to signal a reachability error
void reach_error(void) {
    assert(0); // Force an assertion failure to indicate an error
}

// Function to conditionally abort execution if the condition is false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Problem Description:
The program calculates the factorial of a given number n, but only if n is
less than or equal to 10, due to constraints to prevent integer overflow.
If n is greater than 10, the program should handle it separately.
The program ensures the factorial calculation is correct using assertions.
*/

int main() {
    int n = __VERIFIER_nondet_int(); // One input to define the factorial number
    int factorial = 1;               // Variable to store the computed factorial
    int original_n = n;              // Preserve the original value of n

    // Precondition: n should be a non-negative number
    if (n < 0) {
        return 0;
    }

    // Constraint: Handle only up to n=10
    if (n > 10) {
        n = 10;
    }

    // Loop to calculate the factorial of n
    while (n > 1) {
        factorial *= n;
        n--;
    }

    // After loop ends, factorial should hold the result
    if (original_n <= 10) {
        __VERIFIER_assert(factorial > 0); // Check if the factorial is positive for allowed n
    }

    return 0; // Terminate program successfully
}