#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR:
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n, m, sum, product, i;

    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && m >= 0); // We assume positive integers for simplicity

    sum = 0;
    product = 1;

    for (i = 0; i <= n; i++) {
        sum += i;
    }

    for (i = 1; i <= m; i++) {
        product *= i;
        if (product < 0) {
            break; // Avoid overflow
        }
    }

    // Some meaningful assertions about the sum of first n natural numbers and product of first m natural numbers

    // This assertion should be dependent on your verification property and assumed inputs
    __VERIFIER_assert(product == 0 || product >= m);

    printf("Sum of integers from 0 to %d is %d\n", n, sum);
    printf("Product of integers from 1 to %d is %d\n", m, product);

    return 0;
}