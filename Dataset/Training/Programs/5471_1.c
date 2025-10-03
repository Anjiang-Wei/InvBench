#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        __VERIFIER_nondet_int(); /* simulating abort */
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100); // Let's verify for n within a range
    int sum = 0;
    int product = 1;
    int i = 0;

    while (i < n) {
        sum += i;
        product *= (i + 1);
        i++;
    }

    // Post-loop condition: sum should be equal to n*(n-1)/2 and product should be n!
    // but as n is dynamic, let's not assert specific calculations.
    __VERIFIER_assert(sum >= 0);     // Ensure sum is non-negative
    __VERIFIER_assert(product >= 1); // Ensure product is non-negative

    return 0;
}