#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    abort();
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Helper assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i, sum, product;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // Assume the input is a positive integer

    sum = 0;
    product = 1;
    i = 1;

    while (i <= n) {
        sum += i;     // Calculate the sum of integers from 1 to n
        product *= i; // Calculate the product of integers from 1 to n
        i++;
    }

    // Constraint: If n is 5, then sum should be 15 and product should be 120
    if (n == 5) {
        __VERIFIER_assert(sum == 15);
    }

    printf("Sum: %d, Product: %lld\n", sum, product);

    return 0;
}