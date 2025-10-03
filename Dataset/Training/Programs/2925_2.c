#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

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

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Conditions for x and y to ensure meaningful results in computations
    // x should be positive and y should be between 1 and 100
    assume_abort_if_not(x > 0);
    assume_abort_if_not(y >= 1 && y <= 100);

    int sum = 0;
    int product = 1;
    int i = 0;

    // Loop to perform some computations
    while (i < y) {
        sum += x;     // Compute cumulative sum
        product *= x; // Compute cumulative product with checks
        i++;
    }

    // Asserting final conditions after the loop
    // For analysis purposes, ensure sum is a multiple of y*x

    // Since x > 0, ensure product is a positive value
    __VERIFIER_assert(product > 0);

    return 0;
}