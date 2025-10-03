#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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

int main(void) {
    int m, n;
    long long sum, product;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 1 && m <= 10);
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    product = 1;

    int i = 0;

    while (i < n) {
        sum += m;     // This will compute m * n incrementally
        product *= m; // This computes m^n incrementally
        i++;
    }

    __VERIFIER_assert(product > 0); // Ensures product doesn't overflow in the given range

    // Output the results for verification purposes
    printf("Computed Sum: %lld\n", sum);
    printf("Computed Product: %lld\n", product);

    return 0;
}