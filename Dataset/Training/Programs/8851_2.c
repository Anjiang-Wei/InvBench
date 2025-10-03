#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, sum, diff;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume certain limits on a and b
    assume_abort_if_not(a >= 0 && b >= 0 && a <= 100 && b <= 100);

    sum = 0;
    diff = a;

    for (int i = 0; i < b; ++i) {
        sum = sum + 1;
        diff = diff - 1;
    }

    // Assuming b steps were taken, sum should be equal to b and diff should be a - b
    __VERIFIER_assert(diff == (a - b));

    return 0;
}