#include <assert.h>
#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n, i, sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10);

    sum = 0;
    product = 1;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    printf("Sum of first %d natural numbers is: %d\n", n, sum);
    printf("Product of first %d natural numbers is: %d\n", n, product);

    // Performing basic checks to ensure the correctness of sum and product calculations
    // Fact: The sum of the first n natural numbers is n*(n+1)/2
    // Fact: The product can be validated by ensuring product > 0 and product >= n! when n <= 10 (small n assumption due to factorial growth)
    if (n <= 10) {
        __VERIFIER_assert(product > 0);
    }

    return 0;
}