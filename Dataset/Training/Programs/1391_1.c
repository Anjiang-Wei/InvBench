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
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n, sum, product, i;
    n = __VERIFIER_nondet_int();

    // Assume n is a positive integer
    assume_abort_if_not(n > 0);

    sum = 0;
    product = 1;
    i = 1; // Start index from 1

    while (i <= n) {
        sum += i;     // Sum of first n natural numbers
        product *= i; // Product of first n natural numbers
        i++;
    }

    // Verify if the computed product is non-negative
    __VERIFIER_assert(product >= 1);

    // Verify if the computed sum is correct using the formula

    return 0;
}