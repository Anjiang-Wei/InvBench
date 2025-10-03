#include <limits.h>
#include <stdio.h>

// External verifier functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to compute factorial iteratively
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }

    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    // Non-deterministic input for verification
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Constraint: 0 <= n <= 20 to prevent overflow

    // Calculate factorial
    unsigned long long result = factorial(n);

    // Assertions for verification
    if (n == 0 || n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(result == 2);
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    }

    // Print the result for visual confirmation (can be removed for verification tasks)
    printf("Factorial of %d is %llu\n", n, result);

    return 0;
}