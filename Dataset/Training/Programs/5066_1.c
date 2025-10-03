#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 9, "reach_error"); }
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
}

int main() {
    int n, m;
    long long sum, product;

    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0 && n <= 10);
    assume_abort_if_not(m > 0 && m <= 10);

    sum = 0;
    product = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum = sum + i + j;
            product = product * (i + 1) * (j + 1);

            __VERIFIER_assert((sum >= 0) && (product >= 1)); // basic sanity checks
        }
    }

    // Check if product is within expected logical boundaries
    __VERIFIER_assert(product >= 1);

    // Output the final results
    printf("Final Sum: %lld\n", sum);
    printf("Final Product: %lld\n", product);

    return 0;
}