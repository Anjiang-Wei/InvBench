#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int gcd(int x, int y) {
    while (y != 0) {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int main() {
    int a, b, gcd_a_b, count;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && b > 0);

    gcd_a_b = gcd(a, b);
    __VERIFIER_assert(gcd_a_b > 0);

    count = 0;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            count++;
        }
    }

    if (gcd_a_b < 10) {
        while (gcd_a_b < 20) {
            gcd_a_b++;
        }
    }

    printf("GCD of %d and %d is %d\n", a, b, gcd_a_b);

    return 0;
}