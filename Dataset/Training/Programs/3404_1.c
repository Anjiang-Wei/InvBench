#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
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
    int a, n;
    long long sum, product;

    a = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(n >= 0);

    sum = 0;
    product = 1;

    for (int i = 0; i < n; i++) {
        sum += a;
        product *= a;

        __VERIFIER_assert(sum == a * (i + 1)); // Check the series sum formula
    }

    __VERIFIER_assert(sum == a * n); // Sum should be equal to a * n after loop
    __VERIFIER_assert(product >= 1); // Product should be at least 1 when n >= 0

    return 0;
}