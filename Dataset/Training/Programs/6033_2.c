#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b;
    long long sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    sum = 0;
    product = 1;

    for (int i = 0; i < a; i++) {
        sum += b;
        product *= (b + 1);
    }

    // Ensure that the computed sum and product respect some properties
    __VERIFIER_assert(product >= 1);

    return 0;
}