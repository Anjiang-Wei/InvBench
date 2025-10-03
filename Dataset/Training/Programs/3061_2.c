#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 6, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int factorial = 1;

    // Assume n is positive and less than a reasonable bound
    assume_abort_if_not(n >= 0 && n < 15);

    for (int i = 1; i <= n; ++i) {
        sum += i;
        factorial *= i;

        // Assert that sum is always the sum of the first i natural numbers

        // Assert the factorial condition
        __VERIFIER_assert(factorial == (i == 0 ? 1 : factorial));
    }

    // Final assertions outside the loop

    printf("Sum of first %d natural numbers is: %d\n", n, sum);
    printf("Factorial of %d is: %d\n", n, factorial);

    return 0;
}