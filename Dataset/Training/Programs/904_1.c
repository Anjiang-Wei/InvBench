#include <stdlib.h>

/*
 * Program using a modified algorithm with constraints
 * and loops similar to Example Programs.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
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
    int x, y, a, b, t;

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    assume_abort_if_not(x > 0 && x <= 50);
    assume_abort_if_not(y > 0 && y <= 50);
    assume_abort_if_not(x > y);

    a = x;
    b = y;

    while (a != b) {
        __VERIFIER_assert(a >= 0 && b >= 0);

        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    // The program checks the gcd property

    return 0;
}