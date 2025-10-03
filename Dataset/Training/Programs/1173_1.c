#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("ERROR\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int __VERIFIER_nondet_int();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int(); // Some non-deterministic input
    if (n <= 0) {
        return 0; // Exit if n is not positive
    }

    int sum = 0;
    int product = 1;
    int i, j;

    // Double loop for some computational logic
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            sum += j;
            product *= j;
            if (product > n) {
                product = 1; // Reset product to prevent overflow
            }
            __VERIFIER_assert(sum > 0);
        }
    }

    // Validating the final value of sum

    return 0;
}