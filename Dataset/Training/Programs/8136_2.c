#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 10, "reach_error"); }
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

unsigned int factorial(unsigned int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    unsigned int n = 5; // Compute factorials up to 5
    unsigned int i;
    unsigned int sum_factorials = 0;
    unsigned int known_sum = 153; // 1! + 2! + 3! + 4! + 5!

    for (i = 1; i <= n; ++i) {
        unsigned int f = factorial(i);
        sum_factorials += f;
        printf("Factorial of %u is %u\n", i, f);

        // Verification: check if the partial sum is less than or equal to the known sum
    }

    printf("Sum of factorials from 1 to %u is %u\n", n, sum_factorials);

    // Final verification: check if the total sum is exactly the known sum
    __VERIFIER_assert(sum_factorials == known_sum);

    return 0;
}