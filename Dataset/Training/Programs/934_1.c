#include <assert.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program aims to verify a computation involving
 * a simple sequence of operations to calculate the product
 * of two numbers via repeated addition.
 * The constraint is checked to see if the result matches
 * the expected product for non-negative integers.
 */

int multiply_via_addition(int a, int b) {
    int product = 0;
    while (b > 0) {
        product = product + a;
        b--;
    }
    return product;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Ensure x and y are non-negative and within a sensible range
    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);

    // Calculate product using repeated addition
    int result = multiply_via_addition(x, y);

    // Constraint: The result should be the product of x and y
    __VERIFIER_assert(result == x * y);

    return 0;
}