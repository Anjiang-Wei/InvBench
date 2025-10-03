#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
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
    int a, b, t;

    // Assume a and b are non-negative integers
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Inputs must be non-negative integers
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Avoid trivial case where both are zero
    assume_abort_if_not(a > 0 || b > 0);

    // Euclidean algorithm to compute the GCD
    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }

    // Ensure the result satisfies GCD properties
    __VERIFIER_assert(a >= 0); // GCD must be non-negative
    return 0;
}