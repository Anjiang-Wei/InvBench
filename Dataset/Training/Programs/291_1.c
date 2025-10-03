#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 4, "reach_error"); }
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
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    product = 1;

    // Computing the sum of the first `n` natural numbers using a loop
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    // Computing the product of the first `n` natural numbers using a loop
    i = 1;
    while (i <= n) {
        product *= i;
        i++;
    }

    // Assert that sum of first `n` natural numbers is equal to n*(n+1)/2
    __VERIFIER_assert(sum == (n * (n + 1)) / 2);

    // Print the results
    printf("Sum of first %d natural numbers is: %d\n", n, sum);
    printf("Product of first %d natural numbers is: %d\n", n, product);

    return 0;
}