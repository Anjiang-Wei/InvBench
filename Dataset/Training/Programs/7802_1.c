/*
This is a C program that computes the factorial of a non-negative integer using a loop.
It includes assertions to verify certain properties during the execution.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 12, "reach_error"); }
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

int main() {
    int n, i, result;

    // Random non-deterministic input
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limit input range for demonstration

    result = 1;
    i = 1;

    // Compute factorial using a loop
    while (i <= n) {
        result = result * i;

        // Assertions to check properties of computation (avoiding loop invariants)
        __VERIFIER_assert(result >= 1);
    }

    // Output the result
    printf("Factorial of %d is %d\n", n, result);

    return 0;
}