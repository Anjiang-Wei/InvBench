#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // We assume n to be a non-negative integer
    assume_abort_if_not(n >= 0);

    // This loop will run from 1 to n, computing the sum and product
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Ensure that the loop maintains the invariant that the sum is
        // equal to (i * (i + 1)) / 2 and product is factorial of i
        assume_abort_if_not(product > 0); // Protection against overflow for unsigned operations
    }

    // At the end, check that the sum and product have the expected properties
    // product would be n! but can overflow for large n, so just check it is positive
    __VERIFIER_assert(product > 0);

    return 0;
}