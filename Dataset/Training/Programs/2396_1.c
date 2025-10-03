#include <limits.h>
#include <stdio.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() {
    printf("Assertion failed!\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int __VERIFIER_nondet_int(void);

int main() {
    int n, sum = 0, product = 1, count = 0;
    n = __VERIFIER_nondet_int();

    // The program only processes positive integers.
    assume_abort_if_not(n > 0 && n <= 10000);

    while (count < n) {
        int value = __VERIFIER_nondet_int();
        // Value must be between 1 and 100 to be processed
        assume_abort_if_not(value > 0 && value <= 100);

        sum += value;
        product *= value;
        count++;

        // Watch for potential integer overflow
        assume_abort_if_not(sum >= 0 && product >= 0);
    }

    // Ensure the final computed values are logically consistent
    __VERIFIER_assert(sum >= n);     // If n values were added, sum must be at least n
    __VERIFIER_assert(product >= 1); // Product of positive integers is positive

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}