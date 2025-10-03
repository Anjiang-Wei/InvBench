#include <stdio.h>
#include <stdlib.h>

// External functions for assumptions and verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }
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
    int a, b, sum, product;
    int i;

    // Nondeterministic inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Input constraints
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    // Initialize variables
    sum = 0;
    product = 1;

    for (i = 0; i < a; i++) {
        sum += i;
        if (b > 0 && i % b == 0) {
            product *= b;
        }

        // Maintain logical constraints
        __VERIFIER_assert(product >= 1);
    }

    // Analyzing condition based on computational logic

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}