#include <assert.h>

extern void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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

    // Initialize variables
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    sum = 0;
    product = 1;
    i = 0;

    // Loop that calculates the sum and product of the first n natural numbers
    while (i <= n) {
        // Avoid overflow by assuming sum and product do not exceed some large bounds
        assume_abort_if_not(sum <= 100000 && product <= 100000);

        sum += i;
        product *= (i == 0) ? 1 : i; // Avoid multiplying by 0
        i++;
    }

    // Post-condition validation
    __VERIFIER_assert(sum >= 0 && product >= 1);

    // Final check to illustrate meaningful computation without loop invariants

    return 0;
}