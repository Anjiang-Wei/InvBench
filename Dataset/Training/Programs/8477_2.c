#include <assert.h>
#include <stdio.h>

// Error handler function
void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Function to assume a condition with possibility to abort if false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to assert a condition and call error handler if false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Some arithmetic function involving loops and validation checks
int main() {
    int m, n;
    int sum = 0;
    int product = 1;

    // Get non-deterministic values
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Left just assure some realistic bounds for m and n
    assume_abort_if_not(m >= 1 && m <= 100);
    assume_abort_if_not(n >= 1 && n <= 100);

    // Loop to calculate the sum of natural numbers up to m
    for (int i = 1; i <= m; i++) {
        sum += i;
    }

    // Loop to compute the product of numbers till n (factorial)
    for (int j = 1; j <= n; j++) {
        product *= j;
    }

    // Assert some conditions that relate m, n, sum, and product
    __VERIFIER_assert(product >= n);

    // Output result for debugging or insights
    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}