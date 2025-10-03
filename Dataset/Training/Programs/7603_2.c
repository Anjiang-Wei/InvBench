/*
 * Example program demonstrating basic operations
 * and maintaining minimal invariant properties during loop execution.
 * Designed for analysis and verification by automated tools.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_transformation.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n, i;
    long long A, B, C;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 1000);

    A = 1;
    B = 1;
    C = 2;

    for (i = 0; i < n; i++) {
        // Perform sequential operations
        A += B * C;
        B += A - B;
        C *= 2;

        // Maintaining a condition that can be verified at loop end.
    }

    // Performing some concluding operations
    A = A - n;
    B = B + n;
    C = C - A;

    // Final assertion based on known properties of the transformations
    __VERIFIER_assert(A + B > C);

    printf("Program complete with final values: A=%lld, B=%lld, C=%lld\n", A, B, C);
    return 0;
}