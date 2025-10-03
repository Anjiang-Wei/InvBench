#include <stdio.h>
#include <stdlib.h>

// Function declarations for verification
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int a, b, n;
    long long sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Constraints
    assume_abort_if_not(a >= 1 && a <= 20);
    assume_abort_if_not(b >= 1 && b <= 20);
    assume_abort_if_not(n >= 1 && n <= 20);

    // Initial values
    sum = 0;
    product = 1;

    // Iterative computation
    while (b > 0) {
        sum += a * n;
        product *= b;
        b--;

        // Checkpoint
        __VERIFIER_assert(sum >= 0);
    }

    // Final assertion for correctness

    printf("Sum: %lld, Product: %lld\n", sum, product);

    return 0;
}