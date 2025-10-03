#include <stdio.h>
#include <stdlib.h>

/* This program calculates the factorial of a number n
   using an iterative method and verifies the result
   by comparing it with a predefined checker function.
*/

extern void abort(void);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        {
            reach_error();
            abort();
        }
    }
    return;
}

unsigned int factorial_calculator(unsigned int n) {
    unsigned int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

unsigned int factorial_checker(unsigned int n) {
    // Simple recursive factorial to verify result
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_checker(n - 1);
}

int main() {
    unsigned int n = 5; // Example input, can be replaced with any non-negative integer
    unsigned int factorial_result;
    unsigned int checked_result;

    factorial_result = factorial_calculator(n);
    checked_result = factorial_checker(n);

    printf("Factorial of %u is %u\n", n, factorial_result);

    // Verify that calculated factorial matches the checker function
    __VERIFIER_assert(factorial_result == checked_result);

    return 0;
}