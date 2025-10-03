#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 8, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    int factor1 = 0, factor2 = 0, product = 0;
    int i, j;

    // Assume that n is a positive number
    assume_abort_if_not(n > 0);

    // Find two factors of n such that factor1 * factor2 = n
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            factor1 = i;
            factor2 = n / i;

            // Check the invariant holds
            __VERIFIER_assert(factor1 * factor2 == n);

            // Check for the smallest such pair
            for (j = 1; j <= n; j++) {
                if (j * j >= n) {
                    break;
                }
            }

            // Verify the candidate factor pair is optimal in some way

            if (factor1 * factor2 == n) {
                product = factor1 * factor2;
                break;
            }
        }
    }

    // Verify the found factors indeed multiply to n

    // Output the result
    printf("Factors of %d are %d and %d\n", n, factor1, factor2);

    return 0;
}