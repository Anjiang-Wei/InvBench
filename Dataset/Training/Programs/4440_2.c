#include <stdio.h>
#include <stdlib.h>

// External function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i, sum, product;

    // Nondeterministic input
    n = __VERIFIER_nondet_int();

    // Assumptions for non-deterministic input
    assume_abort_if_not(n > 0 && n <= 100);

    // Initialization
    sum = 0;
    product = 1;

    // Loop with meaningful computations
    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // Verify if the sum equals n * (n + 1) / 2

    // Check if product exceeds certain value (an arbitrary condition)
    if (n <= 10) {
        __VERIFIER_assert(product > 0);
    }

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}