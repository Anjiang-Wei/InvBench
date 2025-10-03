// This is a C program designed for analysis and verification by automated tools.
//
// SPDX-License-Identifier: MIT

#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    // Assume some constraints on inputs
    assume_abort_if_not(x > 0 && y > 0 && z > 0);
    assume_abort_if_not(x < 100 && y < 100 && z < 100);

    // Example computational logic
    int a = x + y;
    int b = y + z;
    int c = x + z;

    int iterations = 0;
    while (iterations < 10) {
        if (a > b) {
            a -= z;
            c += y;
        } else {
            b -= x;
            c += x;
        }
    }

    // Final assertion to be verified
    __VERIFIER_assert(a + b + c > 0);
    return 0;
}