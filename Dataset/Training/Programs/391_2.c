#include <stdio.h>
#include <stdlib.h>

/*
Example of a program that performs a simple numerical computation
using a loop and asserts to check for specific properties
*/

extern void abort(void);
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int x, y, sum, product;
    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 1 && x <= 5);

    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y >= 1 && y <= 5);

    sum = 0;
    product = 1;

    // Loop invariant: sum should equal the number of iterations * (x + y)
    int i = 0;
    while (i < 5) {
        sum += x + y;
        product *= 2; // Double the product in each iteration
        i++;

        // Assert that sum and product maintain valid relationships
        __VERIFIER_assert(product == 1 << i); // Power of 2 check
    }

    // Final assertions to verify the correctness of the program
    __VERIFIER_assert(sum == 5 * (x + y));

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}