#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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
    int m, n, sum = 0;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume m and n are positive integers
    assume_abort_if_not(m > 0 && n > 0);

    int i = 0;

    while (i < n) {
        __VERIFIER_assert(sum == i * m);
        sum += m;
        i++;
    }

    return 0;
}