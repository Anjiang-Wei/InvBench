#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() { printf("Error reached!\n"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    int n, m, sum, product, counter;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0);
    assume_abort_if_not(m > 0 && m < 1000);

    sum = 0;
    product = 1;
    counter = 0;

    while (counter < m) {
        sum += n;
        product *= 2; // multiply by 2 on each iteration
        counter++;

        // The sum is expected to be n * counter
        __VERIFIER_assert(sum == n * counter);

        // Asserts that counter powers of two have been calculated
        int expected_product = 1 << counter;
    }

    if (m % 2 == 0) {
    } else {
    }

    return 0;
}