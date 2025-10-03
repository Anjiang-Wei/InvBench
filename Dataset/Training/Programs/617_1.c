#include <stdio.h>
#include <stdlib.h>

// Helper functions
extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int x, y, z;
    long long sum, prod, prev_prod;

    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 10);
    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y >= 0 && y <= 10);
    z = __VERIFIER_nondet_int();
    assume_abort_if_not(z >= 0 && z <= 10);

    sum = 0;
    prod = 1;
    prev_prod = 1;

    int i = 0;
    int n = 5; // Number of iterations

    while (i < n) {
        sum += x + y + z;
        prev_prod = prod;
        prod *= (x + y + z + i);
        i++;
    }

    __VERIFIER_assert(sum >= 0);

    // Print results just for the sake of completeness.
    printf("Final sum: %lld\n", sum);
    printf("Final product: %lld\n", prod);

    return 0;
}