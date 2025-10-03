#include <stdio.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() {
    printf("Error: Reached a condition that violates expectations!\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int(); // Unconstrained input
    if (n < 0) {
        return 0;
    }

    int sum = 0;
    int product = 1;

    // Loop designed to calculate sum of integers from 1 to n and product of those integers
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // Post condition assertions
    __VERIFIER_assert(sum >= n);     // Basic condition: sum should be at least n
    __VERIFIER_assert(product >= 1); // Basic condition: product should be at least 1

    // The expected sum of the first n natural numbers
    int expected_sum = n * (n + 1) / 2;
    printf("Product of first %d numbers is %d\n", n, product);

    return 0;
}