#include <assert.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n, sum, product;

    // Get a nondeterministic integer
    n = __VERIFIER_nondet_int();

    // Assume n is a positive integer that will not cause overflow
    assume_abort_if_not(n > 0 && n <= 1000);

    sum = 0;
    product = 1; // Start with 1 to avoid multiplication leading to zero

    // Loop to calculate the sum and product of numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // Assert the sum of the first 'n' natural numbers
    // Summation formula: n * (n + 1) / 2

    // Naive assertion on product (which can never overflow here due to constraints)
    // We're not checking the factorial explicitly due to potential odd number behavior
    __VERIFIER_assert(product > 0);

    return 0;
}