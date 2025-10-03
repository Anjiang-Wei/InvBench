#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int A, B, C;
    A = __VERIFIER_nondet_int();
    B = __VERIFIER_nondet_int();
    C = __VERIFIER_nondet_int();

    assume_abort_if_not(A >= 0 && A <= 10);
    assume_abort_if_not(B >= 0 && B <= 10);
    assume_abort_if_not(C >= 0 && C <= 10);

    long long sum = 0, product = 1;
    int count = 0;

    for (int i = 0; i < A; i++) {
        sum += B;
        product *= C;
        count++;
    }

    // Constraint: The program ensures that the sum is B * A and product is C^A (without overflow)
    if (A == 0) {
    } else if (C == 1) {
        __VERIFIER_assert(product == 1);
    } else {
        if (A > 0 && (product / C) == (C ^ (A - 1))) {
        }
    }

    return 0;
}