#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }
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

int main(void) {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 50);
    assume_abort_if_not(y >= 0 && y <= 50);

    int s1 = 0;
    int s2 = 0;
    int i;

    // Calculate sum of first 'x' natural numbers
    for (i = 1; i <= x; i++) {
        s1 += i;
    }

    // Calculate sum of squares of first 'y' natural numbers
    i = 1;
    while (i <= y) {
        s2 += i * i;
        i++;
    }

    // Checks to verify constraints on sums
    __VERIFIER_assert(s1 >= 0);

    return 0;
}