#include <stdlib.h>

/*
 * This program is designed to model a sequence of operations
 * on two variables controlled by nondeterministic inputs and incorporates
 * verification of a property after transformations of the variables.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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
}

int main() {
    int A = 0;
    int B = 0;
    int C = __VERIFIER_nondet_int();
    int i;

    // Assume C is non-negative and within reasonable bounds
    assume_abort_if_not(C >= 0);
    assume_abort_if_not(C <= 1000);

    for (i = 0; i < C; i++) {
        A = A + (i % 2 == 0 ? 5 : 3);
        B = B + (i % 3 == 0 ? 2 : 1);
    }

    // Check the relationships between A, B, and C
    __VERIFIER_assert(A >= B);

    return 0;
}