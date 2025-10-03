#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int product = 0;
    int original_a = a;
    int original_b = b;

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    while (b > 0) {
        if (b % 2 == 1) {
            product += a;
        }
        a *= 2;
        b /= 2;

        // Ensure product is coherent during each step
        __VERIFIER_assert(product + a * b == original_a * original_b);
    }

    // Ensure final product matches the mathematical product

    printf("Product of %d and %d is: %d\n", original_a, original_b, product);

    return 0;
}