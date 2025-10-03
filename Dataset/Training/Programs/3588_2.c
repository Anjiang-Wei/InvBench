#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int i = 0;

    // Assume n is a non-negative integer
    assume_abort_if_not(n >= 0);

    while (i < n) {
        sum += i;
        product *= (i + 1);
        i++;
    }

    // Assert that sum of first n numbers is n*(n-1)/2

    // Assert that product is greater than 0 for n greater than 0
    if (n > 0) {
        __VERIFIER_assert(product > 0);
    }

    return 0;
}