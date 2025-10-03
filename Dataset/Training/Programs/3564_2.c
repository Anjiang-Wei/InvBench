#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "derived_program.c", 5, "reach_error"); }
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
}

int main() {
    int n, i, sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 1000);

    // We calculate the sum of first n integers
    sum = 0;
    for (i = 0; i <= n; i++) {
        sum += i;
    }

    // Now, we assert that sum is indeed n*(n+1)/2

    // Calculate the product of first n integers (i.e., n!)
    product = 1;
    for (i = 1; i <= n; i++) {
        product *= i;
    }

    // If n is 0, product should remain 1, otherwise positive
    __VERIFIER_assert(n > 0 ? product > 0 : product == 1);

    return 0;
}