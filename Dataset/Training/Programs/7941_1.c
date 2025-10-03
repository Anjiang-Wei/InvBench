// Your complete C program here

#include <stdio.h>
#include <stdlib.h>

// This program verifies a simple boolean algebra identity using nondeterministic inputs
// The identity is: (~(A & B)) == (~A | ~B)

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "boolean_identity.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int A, B;
    A = __VERIFIER_nondet_int();
    B = __VERIFIER_nondet_int();

    // Assume the inputs are either 0 or 1, representing boolean values
    assume_abort_if_not(A == 0 || A == 1);
    assume_abort_if_not(B == 0 || B == 1);

    // Boolean algebra identity to be verified
    int left_side = ~(A & B);
    int right_side = (~A | ~B);

    // Verification loop
    int i = 0;
    while (i < 10) {
        __VERIFIER_assert(left_side == right_side);
        i++;
    }

    return 0;
}