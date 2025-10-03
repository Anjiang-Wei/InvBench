#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
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
    int n, sum = 0, product = 1;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Constraint to keep n within a manageable range

    int i = 0;
    while (i < n) {
        sum += i;
        product *= (i + 1);
    }

    // Final assertions
    __VERIFIER_assert(sum == n * (n - 1) / 2); // Verify the sum of first n natural numbers
    __VERIFIER_assert(product >= 1);           // Product will always be at least 1 for n >= 0

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}