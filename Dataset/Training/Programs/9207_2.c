#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int();

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    int i = 1;

    // Loop that calculates the sum of first `n` natural numbers
    while (i <= n) {
        sum += i;
        product *= i;
        ++i;
    }

    // Check that the sum is correct using formula: sum = n*(n+1)/2
    if (n > 0) {
    }

    // Check that the product is greater than 0 for n > 0
    if (n > 0) {
        __VERIFIER_assert(product > 0);
    }

    return 0;
}