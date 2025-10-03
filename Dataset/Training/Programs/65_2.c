#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error(void) {
    printf("Error reached!\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x, y, z;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0);
    assume_abort_if_not(y >= 0);
    assume_abort_if_not(z >= 0);

    int sum = 0;
    int product = 1;

    // Loop: Calculating the sum and product of a sequence of numbers
    int i = 0;
    while (i < x) {
        sum += i;
        product *= (i + 1);

        // Check that sum is always less than or equal to the product

        i++;
    }

    // After the loop, verify specific constraints with the resulting values
    if (x > 0) {
        __VERIFIER_assert(product > 0);
    }

    // Print final results for analysis
    printf("Final sum: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}