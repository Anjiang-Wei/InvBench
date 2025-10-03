#include <stdio.h>

// Custom verifier functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
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

// Function to calculate Fibonacci using iterative double recursion
// This is intentionally complex to illustrate computational logic
int fibonacci(int n) {
    int prev1 = 0, prev2 = 1, next;
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    for (int i = 2; i <= n; ++i) {
        next = prev1 + prev2;
        prev1 = prev2;
        prev2 = next;
    }
    return prev2;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Limit input range for feasibility

    int fib = fibonacci(n);

    // Check that the Fibonacci number is calculated correctly using another known property
    __VERIFIER_assert(fib >= 0); // Fibonacci numbers are non-negative
    __VERIFIER_assert((n == 0 && fib == 0) || (n > 0 && fib > 0));

    printf("Fibonacci of %d is %d\n", n, fib);

    return 0;
}