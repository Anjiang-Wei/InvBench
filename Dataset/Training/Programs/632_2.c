#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }
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
    int n, x, y, sum, product;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1); // Assume n is a positive integer

    x = 0;
    y = 0;
    sum = 0;
    product = 1;

    while (1) {
        if (!(x < n)) {
            break; // Loop until x equals n
        }

        // Calculate sum of first n natural numbers
        sum = sum + x;
        // Calculate product of first n non-zero natural numbers
        if (x > 0) {
            product = product * x;
        }

        x = x + 1;
    }

    printf("Sum of first %d natural numbers: %d\n", n - 1, sum);
    printf("Product of first %d non-zero natural numbers: %d\n", n - 1, product);

    __VERIFIER_assert(product > 0); // product should be positive at the end

    return 0;
}