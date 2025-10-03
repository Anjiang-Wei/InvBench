#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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

int main(void) {
    long long a, b, n, sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 1);
    assume_abort_if_not(n >= 1);

    sum = 0;
    product = 1;
    int i = 1;

    while (i <= n) {
        sum = sum + (a * i);
        product = product * (b + i);
        i++;
    }

    __VERIFIER_assert(product > 0);

    return 0;
}