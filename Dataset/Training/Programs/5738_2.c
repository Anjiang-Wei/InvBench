#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int counter = 0;

int main() {
    int a, b, n;
    long long sum, product;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(n > 0);

    sum = 0;
    product = 1;

    while (counter++ < 10) {
        // Incrementally build sum and product based on a linear function
        sum += a;
        product *= b;

        // If the sum exceeds a certain limit, adjust the variables
        if (sum > n) {
            sum -= n / 2;
        }

        // If the product exceeds a certain limit, adjust the variables
        if (product > n * 10) {
            product /= 2;
        }
    }

    // Verify conditions on the sum and product
    __VERIFIER_assert(product >= 1);
    return 0;
}