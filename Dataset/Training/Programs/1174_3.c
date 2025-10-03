// This program explores a sequence of math operations
// with loop invariants that can be verified by automated tools

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sequence_verifier.c", __LINE__, "reach_error"); }
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
    return;
}

int main() {
    int x = 2;
    int y = 3;
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0 && a < 10 && b < 10);

    for (int i = 0; i < a; i++) {
        y += x * i;
        x *= 2;
    }

    while (a > 0) {
        b = b + a - a / 2;
        a = a / 2;
    }

    __VERIFIER_assert(b >= 0);

    printf("Final Values: x = %d, y = %d, b = %d\n", x, y, b);

    return 0;
}