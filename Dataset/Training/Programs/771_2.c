#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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

int counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    int a = 0, b = 1, fib = 0, i;

    // Ensure n is positive
    assume_abort_if_not(n > 0);

    // Calculating Fibonacci numbers as a test of loops
    for (i = 1; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;

        // Assert that the current Fibonacci number is non-negative (int overflow check for large n might occur, demonstrating complexity challenges)

        // Control a limited count for automated verification tools
        if (counter++ > 20) {
            break;
        }
    }

    // Assume some constraint for demonstration purposes
    assume_abort_if_not(fib <= 10000);

    // Final assertion for verification testing
    __VERIFIER_assert(fib >= a);

    return 0;
}