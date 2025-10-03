/*
  Euclidean Algorithm for Computing GCD
  Implementation has been adapted for verification purposes
*/

#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "euclidean-gcd.c", 5, "reach_error"); }
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
    int a, b;
    int x, y, gcd;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b > 0);

    x = a;
    y = b;

    while (x != y) {

        if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }
    }

    gcd = x; // Both x and y are equal and represent the GCD at this point
    __VERIFIER_assert(gcd > 0);

    printf("GCD of %d and %d is %d\n", a, b, gcd);
    return 0;
}