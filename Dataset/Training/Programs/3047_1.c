// New C program using similar patterns as learned from the examples provided.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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
    int a, b, c, n;
    long long sum_a, sum_b, sum_c;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);
    assume_abort_if_not(c >= 0 && c <= 10);
    assume_abort_if_not(n >= 0 && n <= 10);

    sum_a = 0;
    sum_b = 0;
    sum_c = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum_a += a * i;
            sum_b += b * i;
            sum_c += c * i;
        } else {
            sum_a += c * i;
            sum_b += a * i;
            sum_c += b * i;
        }
        __VERIFIER_assert(sum_a >= 0);
    }

    return 0;
}