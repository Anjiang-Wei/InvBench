#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error() { assert(0); }

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
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Precondition constraints
    assume_abort_if_not(a > 1);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(n > 0);

    int sum = 0;
    int product = 1;

    // Loop to calculate sum and product of 'a' up to 'n' times
    for (int i = 0; i < n; ++i) {
        sum += a;
        product *= b;
    }

    // Postcondition: check that sum and product reach a certain condition
    __VERIFIER_assert(product > 0);

    return 0;
}