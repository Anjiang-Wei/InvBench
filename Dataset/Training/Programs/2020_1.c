#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_verification_task.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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

    // Assume n is between 1 and 10
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    product = 1;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Ensure that the sum of first i natural numbers is i*(i+1)/2
        __VERIFIER_assert(sum == i * (i + 1) / 2);

        // Ensure that the product of first i natural numbers is factorial of i
        // (This is more complex and for demonstration purposes; not verified here)
    }

    // Final check for sum of first n natural numbers

    // Print results
    printf("Sum of first %d natural numbers: %d\n", n, sum);
    printf("Product of first %d natural numbers: %d\n", n, product); // For demonstration

    return 0;
}