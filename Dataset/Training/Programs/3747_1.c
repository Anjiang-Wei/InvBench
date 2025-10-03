/*
 * Program: Sum of Powers Verification
 *
 * This program computes the sum of powers from 1 to N of a given number X.
 * It verifies at the end that the sum of powers follows a certain mathematical property.
 * The program uses assert statements to ensure the correctness of the computations.
 * The example demonstrates the use of loops, conditionals, and mathematical operations.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_of_powers.c", 12, "reach_error"); }
extern void abort(void);
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int X, N;
    long long sum, expected_sum, power;
    int i;

    X = __VERIFIER_nondet_int();
    N = __VERIFIER_nondet_int();

    assume_abort_if_not(N > 0);
    assume_abort_if_not(X > 0);

    sum = 0;
    power = 1; // X^0 = 1

    for (i = 0; i < N; i++) {
        sum = sum + power;
        power = power * X;
    }

    // Theoretical expected sum of powers: (X^(N) - 1) / (X - 1)
    if (X == 1) {
        expected_sum = N; // Special case when X is 1
    } else {
        expected_sum = (power - 1) / (X - 1);
    }

    // Check if the computed sum matches the expected theoretical sum
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}