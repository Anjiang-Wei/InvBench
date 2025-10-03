#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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
    int sum = 0, product = 1, i = 0;

    assume_abort_if_not(n >= 0 && n <= 1000);

    while (1) {
        sum += i;
        product *= i + 1;

        if (!(i < n)) {
            break;
        }

        i++;
    }

    // Here, sum is the sum of the first n natural numbers: n * (n - 1) / 2
    // and the product is between 1 and the factorial of n, or greater than 0.
    __VERIFIER_assert(product > 0 || n == 0); // product starts from 1 and multiplies (i+1) for `n` times

    return 0;
}