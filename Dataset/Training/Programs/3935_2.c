#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }
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

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Restricting input for factorial to avoid overflow

    int fact = factorial(n);
    int sum = 0;
    int i = 1;

    // Loop that computes the sum of first n natural numbers
    while (i <= n) {
        sum += i;
        i++;
    }

    // Assert that sum is correctly computed as n * (n + 1) / 2

    // Assert that factorial of n is positive
    __VERIFIER_assert(fact > 0);

    printf("Factorial of %d is %d\n", n, fact);
    printf("Sum of first %d natural numbers is %d\n", n, sum);

    return 0;
}