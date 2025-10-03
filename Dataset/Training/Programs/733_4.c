// A C program that calculates the factorial of a non-negative integer
// It contains verification constructs and meaningful computational logic

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assert function using verifier tools
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to compute factorial iteratively
int factorial(int n) {
    int result = 1;
    int i;
    for (i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n, fact_result;

    // Obtain a non-deterministic number
    n = __VERIFIER_nondet_int();

    // Ensure n is within our assumable range (example: 0 to 10)
    // Larger numbers can cause overflow for typical integer types
    assume_abort_if_not(n >= 0 && n <= 10);

    // Calculate factorial using a loop
    fact_result = factorial(n);

    // Validate result for small known values
    if (n == 0 || n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
        __VERIFIER_assert(fact_result == 24);
    } // Add more specific checks for hypothetical deeper analysis

    // Print result (for possible manual inspection/testing, though not needed for verification)
    printf("Factorial of %d is %d\n", n, fact_result);

    return 0;
}