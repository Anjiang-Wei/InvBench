/*
 * GCD calculation using subtraction method with verification conditions
 */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_subtraction.c", 10, "reach_error"); }
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

int counter = 0;

int gcd_subtraction(int a, int b) {
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    while (counter++ < 100) {
        __VERIFIER_assert(a > 0 && b > 0);
        if (a == b) {
            break;
        }
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    return a;
}

int main() {
    int x, y, result;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 1);
    assume_abort_if_not(y >= 1);

    result = gcd_subtraction(x, y);

    printf("GCD of %d and %d is %d\n", x, y, result);

    return 0;
}