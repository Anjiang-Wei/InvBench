#include <assert.h>
#include <stdlib.h>

/* This function simulates nondeterministic integer generation */
extern int __VERIFIER_nondet_int(void);

void reach_error(void) { assert(0); }

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
   Program to determine if the product of two number is less than a certain threshold.
   The program will iterate while calculating the multiplication of two numbers an will
   ensure that this product never exceeds a specified threshold.
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int threshold = 1000; // Arbitrary threshold value

    // Assume x and y are within sensible positive bounds to start
    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);

    // Initialize product to zero
    int product = 0;

    // A loop that simulates a multiplication process
    for (int i = 0; i < y; i++) {
        if (product + x <= threshold) {
            product += x; // Increment product by x, simulating multiplication by addition
        } else {
            break; // break if we are going over the threshold
        }
    }

    // Verify the product is never greater than the threshold
    __VERIFIER_assert(product <= threshold);

    return 0;
}