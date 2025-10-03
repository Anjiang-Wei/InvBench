#include <stdio.h>
#include <stdlib.h>

// Function prototypes for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Error handling function to reach an error state
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }

// Function prototype for nondeterministic inputs
extern int __VERIFIER_nondet_int(void);

// Helper function to abort if condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Verification assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Main function for the program
int main() {
    // Variables for computation
    int n, i, factorial, sum;

    // Get nondeterministic input for 'n' and assume it is between 1 and 10
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    // Initialize variables
    factorial = 1;
    sum = 0;

    // Loop to compute factorial of n and sum of integers from 1 to n
    for (i = 1; i <= n; i++) {
        factorial *= i;
        sum += i;
    }

    // Check that factorsial of n and sum computation is correct
    __VERIFIER_assert(factorial >= 1);

    // Print the results
    printf("Factorial of %d is %d\n", n, factorial);
    printf("Sum of integers from 1 to %d is %d\n", n, sum);

    return 0;
}