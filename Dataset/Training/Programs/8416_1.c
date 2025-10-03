#include <stdio.h>
#include <stdlib.h>

// Aborts execution of the program
extern void abort(void);
void reach_error() { abort(); }

// Generates a nondeterministic integer
extern int __VERIFIER_nondet_int(void);

// Verifier assertion
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Main function
int main() {
    int n = __VERIFIER_nondet_int();
    // Ensure n is positive and within a reasonable range
    if (n <= 0 || n > 50) {
        return 0;
    }

    int i, factorial = 1, sum = 0;

    for (i = 1; i <= n; i++) {
        factorial *= i; // Calculate factorial iteratively
        sum += i;       // Calculate the sum of numbers from 1 to n
    }

    // Check computational invariants without using explicit assertions inside loops
    __VERIFIER_assert(factorial > 0);

    // Output the results
    printf("Factorial of %d is %d\n", n, factorial);
    printf("Sum of numbers from 1 to %d is %d\n", n, sum);

    return 0;
}