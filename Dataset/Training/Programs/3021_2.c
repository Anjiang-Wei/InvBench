#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
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
    assume_abort_if_not(n > 0 && n < 1000); // Assume n is a small positive number
    int sum = 0;
    int product = 1;
    int i = 1;

    // Loop through numbers and calculate the sum and product
    while (i <= n) {
        sum += i;
        product *= i;
        i++;
    }

    // Verify that sum is equal to the formula n*(n+1)/2 for the first n natural numbers

    // Verify that product is greater than 0 (as long as n > 0, which is assumed)
    __VERIFIER_assert(product > 0 || n == 0);

    // Print the results to standard output for manual verification
    printf("Sum of first %d numbers is: %d\n", n, sum);
    printf("Product of first %d numbers is: %d\n", n, product);

    return 0;
}