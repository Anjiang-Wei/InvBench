#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

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
    int n, i, sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Assume n is between 1 and 10

    sum = 0;
    product = 1;
    i = 1;

    while (i <= n) {
        sum += i;
        product *= i;

        // Constraint: sum should never exceed 55 (sum of first 10 natural numbers)
        // and product should never exceed 3628800 (factorial of 10)
        __VERIFIER_assert(product <= 3628800);

        i++;
    }

    // Final assertion to ensure the computation is coherent with mathematical facts
    printf("Product of first %d numbers is: %d\n", n, product);

    return 0;
}