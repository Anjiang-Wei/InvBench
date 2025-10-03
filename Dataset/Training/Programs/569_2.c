#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 5, "reach_error"); }
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
    int x, y;
    long long sum_x, sum_y, product;

    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 1 && x <= 10); // Assume x is between 1 and 10
    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y >= 1 && y <= 10); // Assume y is between 1 and 10

    sum_x = 0;
    sum_y = 0;
    product = 1;

    int i = 1;
    int j = 1;

    // Loop to calculate factorial and sum of series
    while (i <= x) {
        sum_x += i;
        i++;
    }

    while (j <= y) {
        sum_y += j;
        product *= j;
        j++;
    }

    __VERIFIER_assert(sum_y >= y);

    printf("Sum of 1 to %d is %lld\n", x, sum_x);
    printf("Sum of 1 to %d is %lld\n", y, sum_y);
    printf("Factorial of %d is %lld\n", y, product);

    return 0;
}