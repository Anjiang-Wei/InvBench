#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "computation.c", 4, "reach_error"); }
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
    int n, m;
    long long sum, seq, test, product;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 1 && n <= 100);
    assume_abort_if_not(m >= 1 && m <= 100);

    sum = 0;
    seq = 1;
    test = 0;
    product = 1;

    while (test++ < n) {
        sum += seq;
        product *= (seq + m);
        seq += 1;
    }

    __VERIFIER_assert(sum > 0);

    printf("Sum: %lld, Product: %lld\n", sum, product);

    return 0;
}