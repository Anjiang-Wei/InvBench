#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }
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

int counter = 0;

int main() {
    int n, sum, product;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // Assuming n is a non-negative integer

    sum = 0;
    product = 1;

    while (counter++ < n) {
        __VERIFIER_assert(sum >= 0);     // Sum should always be non-negative
        __VERIFIER_assert(product >= 1); // Product should always be at least 1

        // If counter is even, add to sum, else multiply to product
        if (counter % 2 == 0) {
            sum += counter;
        } else {
            if (counter != 1) { // Avoid multiplying by 1
                product *= counter;
            }
        }
    }

    printf("Final sum: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}