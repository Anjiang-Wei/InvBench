#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }
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
    assume_abort_if_not(n >= 1 && n <= 100);

    int sum = 0;
    int product = 1;
    int i = 1;

    while (i <= n) {
        sum += i;
        product *= i;

        // Verify that the sum of the first i numbers is equal to i * (i + 1) / 2

        // Verify that the product is positive and not zero
        __VERIFIER_assert(product > 0);

        i++;
    }

    // Final assertions

    return 0;
}