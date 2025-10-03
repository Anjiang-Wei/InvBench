#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
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
    int n, i;
    long long sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    sum = 0;
    product = 1;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Ensure sum of first 'i' natural numbers is correct
        __VERIFIER_assert(sum == (i * (i + 1)) / 2);

        // Ensure product of numbers does not overflow (simple constraint)
        assume_abort_if_not(product > 0);
    }

    // Final assertion: sum of first 'n' natural numbers

    printf("Sum of first %d natural numbers: %lld\n", n, sum);
    printf("Product of first %d natural numbers: %lld (may overflow)\n", n, product);

    return 0;
}