#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Custom function to calculate factorials using loops and recursion constraints
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
        __VERIFIER_assert(result > 0); // Ensure factorial does not overflow to negative
    }
    return result;
}

int main() {
    int n, factorial_result;

    // Get a nondeterministic input
    n = __VERIFIER_nondet_int();

    // Assume n is in a safe range to prevent overflow when calculating factorial
    assume_abort_if_not(n >= 0 && n <= 12); // 12! < INT_MAX for 32-bit int

    factorial_result = factorial(n);

    // Make sure the result is a positive number; factorial is always positive for non-negative n

    printf("Factorial of %d is %d\n", n, factorial_result);

    return 0;
}