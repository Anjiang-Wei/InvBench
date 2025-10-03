#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, n;
    long long sum, product, count;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);
    assume_abort_if_not(n > 0);

    sum = 0;
    product = 1;
    count = 0;

    while (count < n) {
        sum += a;
        product *= b;

        // Maintain some reasonable constraint
        __VERIFIER_assert(sum == a * (count + 1));

        count++;
    }

    // Final assertion to ensure logical relationships hold
    printf("Final product: %lld\n", product);

    return 0;
}