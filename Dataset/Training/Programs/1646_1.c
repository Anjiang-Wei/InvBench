#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assume initial conditions
    assume_abort_if_not(x >= 0 && x <= 1000);
    assume_abort_if_not(y >= 0 && y <= 100);

    // Loop to perform computations
    for (int i = 0; i < y; i++) {
        sum += x;
        product *= 2;

        // If product overflows, abort
        assume_abort_if_not(product > 0);
    }

    // Postcondition: sum must always be non-negative
    __VERIFIER_assert(sum >= 0);

    // Postcondition: product should not exceed a threshold
}