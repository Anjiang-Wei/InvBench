#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
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
    assume_abort_if_not(n >= 1 && n <= 10); // Constraint on input

    int sum = 0;
    int product = 1;
    int i = 1;

    while (i <= n) {
        sum += i;
        product *= i;

        // Assertions to check properties
    }

    // Final assertions
    __VERIFIER_assert(sum == n * (n + 1) / 2); // Verify that sum is the sum of first n natural numbers
    __VERIFIER_assert(product > 0);            // Product should be positive for n >= 1

    printf("Sum: %d, Product: %d, n: %d\n", sum, product, n);
    return 0;
}