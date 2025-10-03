#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        printf("Assertion failed!\n");
        abort();
    }
}

int __VERIFIER_nondet_int(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}

int main() {
    int i = 0;
    int n = __VERIFIER_nondet_int(); // unknown upper bound
    int sum = 0;
    int product = 1;

    assume_abort_if_not(n > 0 && n < 100); // ensuring n is within reasonable bounds

    while (i < n) {
        sum += i;
        product *= (i + 1); // avoiding multiplication by zero
        i++;

        // Invariant checks
        __VERIFIER_assert(product > 0);
    }

    // Final assertion to ensure computations are as expected
    if (product <= 0) {
        reach_error();
    }

    printf("Computed sum: %d\n", sum);
    printf("Computed product: %d\n", product);

    return 0;
}