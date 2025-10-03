#include <stdio.h>
#include <stdlib.h>

// Declaration of external functions used for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom-verifier.c", 8, "reach_error"); }

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
    int n, k;
    long long sum, product, factorial;

    // Non-deterministically assign values
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // reasonable size limits
    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 1 && k <= n); // k should be within the range of n

    sum = 0;
    product = 1;
    factorial = 1;

    int i;
    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;
        if (i <= k) {
            factorial *= i;
        }
    }

    // Check some properties
    __VERIFIER_assert(sum == n * (n + 1) / 2); // Arithmetic sum of first n numbers

    // Print out for debug purposes, might be removed in actual verification environment
    printf("Sum: %lld\n", sum);
    printf("Product: %lld\n", product);
    printf("Factorial of %d: %lld\n", k, factorial);

    return 0;
}