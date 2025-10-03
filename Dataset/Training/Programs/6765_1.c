#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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
    int n, sum, product, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    sum = 0;
    product = 1;

    for (i = 1; i <= n; ++i) {
        sum += i;
        product *= i;

        // Assert that the current sum equals the sum of the first i numbers
        __VERIFIER_assert(sum == i * (i + 1) / 2);
    }

    // At the end of the loop, sum should be n*(n+1)/2

    // Placeholder assertion to check some property of product at the end
    // In a real analysis, we might check specific product constraints or properties

    return 0;
}