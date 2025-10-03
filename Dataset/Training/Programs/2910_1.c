#include <stdio.h>
#include <stdlib.h>

/* Program to determine if a number is a perfect cube or not */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "cube_verification.c", 3, "reach_error"); }
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
    int n, result = 0;
    long long a, b, cube;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    a = 0;
    cube = 0;

    while (cube <= n) {
        cube = a * a * a;

        if (cube == n) {
            result = 1;
            break;
        }

        b = a + 1;
        if (b * b * b > n) {
            break;
        }

        a = b;
    }

    if (result) {
        printf("%d is a perfect cube.\n", n);
    } else {
        printf("%d is not a perfect cube.\n", n);
    }

    __VERIFIER_assert((result == 1 && cube == n) || (result == 0 && cube != n));

    return 0;
}