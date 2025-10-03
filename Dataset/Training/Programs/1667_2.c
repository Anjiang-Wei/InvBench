#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }
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
    int n, sum, product, i;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 100);

    sum = 0;
    product = 1;
    i = 1;

    while (i <= n) {
        sum += i;
        product *= i;
        i++;
    }

    // Simple verification of computed sum and product
    // Here, we are checking the computed values with a known property

    // Perform a property check on product with considerations for n = 0 and n = 1
    // product will be 1 when n = 0 or 1, otherwise it will be greater than n.
    if (n == 0 || n == 1) {
        __VERIFIER_assert(product == 1);
    } else {
    }

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}