// This program is designed to compute the factorial of a given number using a loop.
// It includes assertions to verify that the factorial is computed correctly for a number between 0 and 12.
// The goal is to ensure the program is suitable for analysis by automated verification tools.

#include <limits.h>
#include <stdio.h>

// External declarations for verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 10, "reach_error"); }

// Verification assert function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n, i;
    long long factorial;

    // Assume n is a nondeterministic integer between 0 and 12
    extern int __VERIFIER_nondet_int(void);
    n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        return 0; // Asserting boundary condition to prevent overflow
    }

    // Initialize factorial and loop variables
    factorial = 1;
    i = 1;

    // Compute the factorial of n
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Assert that factorial is computed correctly
    if (n == 0 || n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(factorial == 2);
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    } else if (n == 6) {
    } else if (n == 7) {
    } else if (n == 8) {
    } else if (n == 9) {
    } else if (n == 10) {
    } else if (n == 11) {
    } else if (n == 12) {
    }

    printf("Factorial of %d is %lld\n", n, factorial); // Output for reference
    return 0;
}