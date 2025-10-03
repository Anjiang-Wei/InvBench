#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() {
    assert(0);
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
    int a, b, n, sum, prod;

    // Initializing variables with nondeterministic values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Constraining the inputs
    assume_abort_if_not(a > 0 && b > 0 && n > 0 && n < 10);

    sum = 0;
    prod = 1;

    int i = 0;
    while (i < n) {
        sum += a;
        prod *= b;

        // Increment control variable
        i++;
    }

    // Verify that sum and product have the expected properties
    __VERIFIER_assert(prod > 0);

    printf("Sum of numbers: %d\n", sum);
    printf("Product of numbers: %d\n", prod);

    return 0;
}