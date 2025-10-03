#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 4, "reach_error"); }

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

int __VERIFIER_nondet_int(void);

int main() {
    int num, factor;
    long long factorial, product;
    int i = 1;

    num = __VERIFIER_nondet_int();
    assume_abort_if_not(num >= 1 && num <= 10); // Assume valid range for factorial calculation

    factor = __VERIFIER_nondet_int();
    assume_abort_if_not(factor >= 1 && factor <= 5); // Assume multi-factor is within a specific range

    factorial = 1;

    while (i <= num) {
        factorial *= i;
        i++;
    }

    product = factorial * factor;

    __VERIFIER_assert(product % factor == 0); // Ensure product is divisible by the multiplication factor

    printf("Factorial of %d is %lld\n", num, factorial);
    printf("Product with factor %d is %lld\n", factor, product);

    return 0;
}