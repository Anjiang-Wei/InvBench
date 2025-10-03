#include <assert.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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

    // Assume some initial condition for a and b
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b > 0);

    // Calculate gcd using the Euclidean algorithm
    while (a != b) {
        if (__VERIFIER_nondet_bool()) {
            if (a > b) {
                a = a - b;
            } else {
                b = b - a;
            }
        }
    }

    // Post-condition: a should be the gcd of the initial values of a and b
    __VERIFIER_assert(a > 0);

    return 0;
}