/*
  Algorithm for checking the sum of two numbers and ensuring that it
  respects certain constraints, verifiable by automated tools.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verify_sum.c", 6, "reach_error"); }
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

int main() {
    int x, y, sum;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Assume some constraints on x and y
    assume_abort_if_not(x >= 1 && x <= 100);
    assume_abort_if_not(y >= 1 && y <= 100);

    sum = 0;

    // Loop to compute sum of x and y
    for (int i = 0; i < x; i++) {
        sum++;
    }
    for (int j = 0; j < y; j++) {
        sum++;
    }

    // Assert that the sum is x + y
    __VERIFIER_assert(sum == x + y);

    // Additional constraints or properties to check
}