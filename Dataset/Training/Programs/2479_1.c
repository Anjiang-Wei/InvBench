/*
Mixed Arithmetic Computations:
This program performs a series of arithmetic operations under various constraints.
It calculates the sum of squares of two numbers, x and y, and verifies specific
properties using assertions.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "mixed_arithmetic.c", 15, "reach_error"); }
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
    return;
}

int counter = 0;

int sum_of_squares(int a, int b) {
    return a * a + b * b;
}

int product(int a, int b) {
    return a * b;
}

int main() {
    int x, y, limit;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && y >= 0 && limit > 0);

    int squared_sum = 0;
    int prod = product(x, y);

    while (counter++ < 20) {
        if (prod > limit) {
            squared_sum += sum_of_squares(x, y);
        } else {
            squared_sum -= sum_of_squares(x, y);
        }

        if (counter >= 20) {
            break;
        }

        x += 1;
        y += 1;

        if (x > limit || y > limit) {
            break;
        }
    }

    // Verify computed result for mixed arithmetic logic
    __VERIFIER_assert((squared_sum >= 0 && prod > limit) || (squared_sum <= 0 && prod <= limit));

    return 0;
}