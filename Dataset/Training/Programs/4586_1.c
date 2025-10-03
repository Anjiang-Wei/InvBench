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
    int n = __VERIFIER_nondet_int();
    int sum = 0, product = 1;
    assume_abort_if_not(n >= 1 && n <= 50);

    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // Post-condition: Check that sum and product hold certain properties
    __VERIFIER_assert(sum >= 1);     // This should always be true as long as n >= 1
    __VERIFIER_assert(product >= 1); // This should always be true as well

    return 0;
}