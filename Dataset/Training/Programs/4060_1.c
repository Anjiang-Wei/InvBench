#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern int __VERIFIER_nondet_int(void);

void reach_error() { __assert_fail("0", "example_program.c", 7, "reach_error"); }

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
    // Start with unknown values for n and m
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 20);

    int sum_items = 0;
    int product_items = 1;
    int i = 0;

    // Compute the sum of numbers from 1 to n and product of numbers from 1 to m
    while (i < n || i < m) {
        if (i < n) {
            sum_items += i + 1; // sum of series 1 to n
        }
        if (i < m) {
            product_items *= i + 1; // product of series 1 to m
        }
        i++;
    }

    // Constraint: Sum should not exceed 55 and product should not exceed 2432902008176640000
    __VERIFIER_assert(sum_items <= 55);
    // Let's also assume that int can't overflow, even though this is platform dependent

    return 0;
}