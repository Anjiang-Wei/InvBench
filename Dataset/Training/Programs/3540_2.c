#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern void __VERIFIER_assume(int cond);
extern void __VERIFIER_assert(int cond);
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Initialize variables
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assume m and n are positive between 1 and 10 for this example
    __VERIFIER_assume(m > 0 && m <= 10);
    __VERIFIER_assume(n > 0 && n <= 10);

    // Add m to sum, n times and calculate factorial of m.
    int i = 0;
    while (i < n) {
        sum += m; // Equivalent to sum = m * n
        i++;
    }

    for (i = 1; i <= m; i++) {
        product *= i; // Calculate m!
    }

    // Assert conditions
    __VERIFIER_assert(product >= 1);

    return 0;
}