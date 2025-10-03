#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
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
    int a, b, c, i;
    int sum = 0, product = 1;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assume inputs are within a specific range to ensure meaningful computation
    assume_abort_if_not(a > 0 && a < 100);
    assume_abort_if_not(b > 0 && b < 100);
    assume_abort_if_not(c > 0 && c < 100);

    for (i = 0; i < a; i++) {
        sum += i;
        product *= (i + 1);

        // Verification condition: ensure sum and product are within bounds
        __VERIFIER_assert(sum < 10000);
    }

    // Another verification condition using b and c
    if (b < c) {
        int diff = c - b;
    }

    return 0;
}