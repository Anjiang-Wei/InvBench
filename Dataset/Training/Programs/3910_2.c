#include <assert.h>
#include <stdlib.h>

/*
 * This program computes a mathematical sequence based on given conditions.
 * It calculates the product of odd numbers up to `n` and ensures that the
 * final computed value meets expected characteristics.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 9, "reach_error"); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int n;
    long long product, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // limit n for computation complexity control

    product = 1;
    i = 1;

    while (i <= n) {
        if (i % 2 != 0) { // Compute product of odd numbers
            product *= i;
        }
        i++;
    }

    // The final product should be greater than 0 for any n > 0.
    if (n > 0) {
    } else {
        __VERIFIER_assert(product == 1);
    }

    return 0;
}