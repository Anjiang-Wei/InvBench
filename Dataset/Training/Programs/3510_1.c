#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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
    int n, x, sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    sum = 0;
    product = 1;
    x = 1;

    while (x <= n) {
        sum = sum + x;
        product = product * x;

        // Check if sum of integers from 1 to x equals x*(x+1)/2
        __VERIFIER_assert(sum == (x * (x + 1)) / 2);

        x = x + 1;
    }

    printf("Sum of 1 to %d is %d\n", n, sum);
    printf("Product of 1 to %d is %d\n", n, product);

    return 0;
}