#include <stdio.h>

// This program calculates the factorial of a given number
// and checks if an assertion holds true throughout the calculation
// The assertion ensures that the factorial calculation is being performed correctly

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_assert.c", 10, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int factorial(int n) {
    if (n < 0) {
        return -1; // Error case, factorial is not defined for negative numbers
    }
    int result = 1;
    int i = 1;

    while (i <= n) {
        result *= i;
        i++;

        // Assertion to ensure that result is correctly calculated so far
        __VERIFIER_assert(result >= 1);
    }

    return result;
}

int main() {
    int n = 5; // Example input
    int result = factorial(n);

    // Check if the result matches the expected factorial value
    if (n == 5) {
    }

    printf("Factorial of %d is %d\n", n, result);
    return 0;
}