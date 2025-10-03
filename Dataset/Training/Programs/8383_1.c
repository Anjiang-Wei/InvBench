/*
 * A Program to Calculate Factorials of Numbers from 1 to a Given Limit
 * and Verifies the Sum of Factorials with Precomputed Constraint Conditions
 * Program can be used for automated verification to assert that a sum
 * of factorials is consistent within the bounds of computation.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int k, i;
    long long sum = 0;
    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 1 && k <= 10);

    for (i = 1; i <= k; i++) {
        sum += factorial(i);
    }

    // Constraint: sum should be less than or equal to a precomputed limit.
    // For k=1 to 10, this should hold: sum <= 4037913 (10!)
    __VERIFIER_assert(sum <= 4037913);

    printf("Sum of factorials till %d is %lld\n", k, sum);
    return 0;
}