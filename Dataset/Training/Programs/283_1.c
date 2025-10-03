#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "my_program.c", 5, "reach_error"); }
int __VERIFIER_nondet_int();

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, i, factorial, product;

    // Getting a nondeterministic number within a specific range
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    factorial = 1;
    product = 1;

    // Calculate factorial
    for (i = 2; i <= n; i++) {
        factorial *= i;
    }

    // Verify if the factorial is greater than a threshold
    assume_abort_if_not(factorial > 0);

    i = 1;
    while (i <= n) {
        product *= 2;
        i++;
    }

    // Ensure the product is as expected
    __VERIFIER_assert(product == (1 << n));

    printf("Factorial of %d is %d\n", n, factorial);
    printf("2 raised to %d is %d\n", n, product);

    return 0;
}