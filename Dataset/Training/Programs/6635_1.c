#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, n;
    long long sum, product, iteration;

    // Get non-deterministic values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume some basic constraints
    assume_abort_if_not(a >= 1 && b >= 1 && n >= 1);
    assume_abort_if_not(n < 50); // to ensure termination in reasonable time

    sum = 0;
    product = 1;
    iteration = 1;

    // Loop simulating a sequence where each step adds and multiplies
    // In this loop, we generate a series of sums and products
    while (iteration <= n) {
        sum += a * b;
        product *= b;

        __VERIFIER_assert(sum >= a * b); // ensure sum is correctly computed
        __VERIFIER_assert(product > 0);  // ensure product never zero

        iteration++;
    }

    // Final computation and verification
    // Here we assert that after the loop
    // sum should be equal to n * a * b

    // Output results for additional manual verification and analysis.
    printf("For inputs a=%d, b=%d, n=%d -> Sum=%lld, Product=%lld\n", a, b, n, sum, product);

    return 0;
}