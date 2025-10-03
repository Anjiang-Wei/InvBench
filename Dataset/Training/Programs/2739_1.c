#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }
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

int __VERIFIER_nondet_int(void) {
    return rand() % 21; // random number between 0 and 20
}

int main() {
    int a, b, n;
    long long sum_a, sum_b, product;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 10);

    sum_a = 0;
    sum_b = 0;
    product = 0;

    for (int i = 0; i < n; i++) {
        sum_a += a;
        sum_b += b;
        product += a * b;

        __VERIFIER_assert(sum_a == a * (i + 1) && sum_b == b * (i + 1));
    }

    // Verify the final computations

    return 0;
}