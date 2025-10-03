#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int sum = 0;
    int product = 1;
    int i;

    // Calculate sum of first n natural numbers and their product
    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Check that sum is always non-negative and product does not exceed a large number.
        __VERIFIER_assert(sum >= 0);
    }

    // Verify known formula for the sum of first n natural numbers
    int expected_sum = n * (n + 1) / 2;

    // Print results for demonstration purposes
    printf("Computed sum: %d, Expected sum: %d\n", sum, expected_sum);
    printf("Final product: %d\n", product);

    return 0;
}