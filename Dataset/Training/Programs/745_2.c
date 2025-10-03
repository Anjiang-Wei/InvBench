#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int();

// Function to compute the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assume n is a non-negative integer less than 10
    if (n < 0 || n >= 10) {
        n = 5; // Default value for safety
    }

    int fact = factorial(n);
    // Assert that factorial of n is greater than or equal to n (for n >= 0)

    // Verify a specific factorial value
    if (n == 5) {
        __VERIFIER_assert(fact == 120);
    }

    return 0;
}