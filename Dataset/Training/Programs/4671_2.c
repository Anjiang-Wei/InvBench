/*
  Compute the Greatest Common Divisor (GCD) of two numbers using Euclid's algorithm
  and use runtime verification to ensure that the algorithm is correctly implemented
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 6, "reach_error"); }
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

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int x, y, result;

    // Initialize x and y with non-deterministic values
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Assume inputs are non-negative
    assume_abort_if_not(x >= 0 && y >= 0);

    // Calculate gcd
    result = gcd(x, y);

    // Verify absolute correctness conditions: gcd(x, x) == x and gcd(x, 0) == x
    if (x > 0) {
        __VERIFIER_assert(gcd(x, 0) == x);
    }

    // Output GCD result
    printf("GCD of %d and %d is %d\n", x, y, result);

    return 0;
}