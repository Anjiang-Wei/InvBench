#include <stdlib.h>

// External declarations for verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assert function for verification
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int X, Y, Z;
    long long sum1 = 0, sum2 = 0;

    // Getting non-deterministic inputs
    X = __VERIFIER_nondet_int();
    Y = __VERIFIER_nondet_int();
    Z = __VERIFIER_nondet_int();

    // Constraints on inputs
    assume_abort_if_not(X >= 0 && X <= 100);
    assume_abort_if_not(Y >= 0 && Y <= 100);
    assume_abort_if_not(Z >= 0 && Z <= 100);

    // First loop: Compute sum1 as the sum of first X odd numbers
    for (int i = 0; i < X; i++) {
        sum1 += 2 * i + 1; // Sum of odd numbers
    }

    // Second loop: Compute sum2 as sum of an arithmetic series with first term Y, common difference 1
    for (int j = 0; j < Z; j++) {
        sum2 += Y + j;
    }

    // Verification condition that sum1 should be equal to sum of squares of natural numbers
    __VERIFIER_assert(sum1 == X * X);

    // Verification condition on the sum of arithmetic series

    return 0;
}