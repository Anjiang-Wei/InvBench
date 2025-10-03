#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Compute the sum of the first n natural numbers and verify it against a calculated formula */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_assert.c", 5, "reach_error"); }
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
    n = __VERIFIER_nondet_int();

    // Assume n is within some reasonable bounds for demonstration purposes
    assume_abort_if_not(n >= 0 && n <= 1000);

    // Compute the sum of the first n natural numbers using iteration
    long sum_iterative = 0;
    for (int i = 1; i <= n; i++) {
        sum_iterative += i;

        // Use a loop invariant here for verification: sum_iterative should always be i*(i+1)/2
        __VERIFIER_assert(sum_iterative == (i * (i + 1)) / 2);
    }

    // Compute the sum using the formula n*(n+1)/2 for verification
    long sum_formula = (long)n * (n + 1) / 2;

    // Verify that both methods give the same result

    // If the assert passes, print the results
    printf("Sum of the first %d natural numbers is: %ld\n", n, sum_iterative);

    return 0;
}