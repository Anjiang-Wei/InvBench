/*
 * New C program inspired by the provided examples:
 * Demonstrates constraint verification and loop logic.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int X = __VERIFIER_nondet_int();
    int Y = __VERIFIER_nondet_int();
    int Z = __VERIFIER_nondet_int();

    assume_abort_if_not(X > 0 && X < 100);
    assume_abort_if_not(Y > 0 && Y < 100);
    assume_abort_if_not(Z > 0 && Z < 100);

    int sum = 0;
    int product = 1;

    for (int i = 1; i <= X; i++) {
        sum += i;
        product *= 2;
        __VERIFIER_assert(sum <= (i * (i + 1)) / 2);
    }

    for (int j = 1; j <= Y; j++) {
        sum += j;
        product *= 3;
    }

    for (int k = 1; k <= Z; k++) {
        sum += k;
        product *= 4;
    }

    return 0;
}