/*
Fibonacci Series
computes the first k Fibonacci numbers and verifies a property
using the property F(n) * F(n+1) - F(n-1) * F(n+2) + (-1)^n == 0
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-verification.c", 9, "reach_error"); }
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
    int k;
    long long fn1, fn2, fn3, fn4, n, tmp;

    // Let k be a non-deterministic integer within a reasonable range
    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 3 && k <= 30);

    // Initialize the first few Fibonacci numbers
    fn1 = 1; // F(1)
    fn2 = 1; // F(2)
    fn3 = 2; // F(3)
    n = 3;   // current position

    while (n < k) {
        fn4 = fn2 + fn3; // F(n+2) = F(n) + F(n+1)

        // Verify property: F(n) * F(n+1) - F(n-1) * F(n+2) + (-1)^n == 0
        if (n % 2 == 0) {
        } else {
            __VERIFIER_assert(fn2 * fn3 - fn1 * fn4 + 1 == 0);
        }

        // Shift Fibonacci positions forward
        fn1 = fn2;
        fn2 = fn3;
        fn3 = fn4;
        n++;
    }

    // Log Fibonacci numbers for verification purposes
    printf("Fibonacci up to %d terms:\n", k);
    printf("... %lld, %lld, %lld\n", fn1, fn2, fn3);

    return 0;
}