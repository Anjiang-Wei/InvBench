#include <stdio.h>
#include <stdlib.h>

// Automated verification related functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new-program.c", 2, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

// Assertion macro used in place of asserts to reach_error
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

// Useful function to skip conditions
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// New function demonstrating a simple transformation logic
// with constraints that can be verified.
int transformation(int a, int b, int n) {
    int result = a;
    int increment = b;
    int i = 0;

    while (i < n) {
        if (result > 1000) {
            result -= increment;
        } else {
            result += increment;
        }
        ++i;
    }

    // Verification assertions
    // Ensure that the result follows expected boundaries.
    __VERIFIER_assert(result < 2000);

    return result;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Ensure the initial values are within reasonable bounds.
    assume_abort_if_not(a >= 0 && a < 1000);
    assume_abort_if_not(b > 0 && b < 100);
    assume_abort_if_not(n > 0 && n < 1000);

    int result = transformation(a, b, n);

    // Additional validation if needed
    printf("Transformation result: %d\n", result);

    return 0;
}