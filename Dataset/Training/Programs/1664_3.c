#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
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
    int n;
    long long sum, product;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 3); // Ensures n is within a reasonable range

    sum = 0;
    product = 1;

    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // Post-condition checks
    __VERIFIER_assert((n == 0 && sum == 0) || (n > 0 && product > 0));

    // Print results for verification
    printf("Sum: %lld, Product: %lld\n", sum, product);

    return 0;
}