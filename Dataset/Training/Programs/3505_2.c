#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int sum = 0;

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(c > 0);

    // Ensuring initial condition
    assume_abort_if_not(sum == 0);

    for (int i = 0; i < c; i++) {
        if (i % 2 == 0) {
            sum += a;
        } else {
            sum += b;
        }
    }

    // Intended postcondition: after each iteration, sum should be equal or greater than a
    __VERIFIER_assert(sum >= a);

    return 0;
}