#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed.c", 3, "reach_error"); }
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
    int a, b, sum, i;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0);
    assume_abort_if_not(a < 100 && b < 100);

    sum = 0;
    i = 0;

    while (i < a) {
        sum += b;
        i++;
    }

    int expected_sum = a * b;
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}