#include <stdio.h>
#include <stdlib.h>

/* Extern functions to simulate non-deterministic input and control */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 6, "reach_error"); }
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
    long long sum, prod, i, temp;

    // Non-deterministic input, ensure it's positive for the loop to make sense
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100); // assuming a reasonable limit for computations

    sum = 0;
    prod = 1;
    i = 1; // Start from 1 to avoid multiplication by zero

    while (i <= n) {
        sum += i;
        prod *= i;

        // The product should not exceed a large limit to avoid overflow
        assume_abort_if_not(prod < 1000000);

        i++;
    }

    // At the end of the loop, checking properties
    __VERIFIER_assert((sum * 2) > n);

    // Print results for human verification if needed
    printf("Sum: %lld, Product: %lld\n", sum, prod);

    return 0;
}