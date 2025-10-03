/*
  Algorithm for calculating the greatest common divisor (GCD) of two non-negative integers.
  This program uses the Euclidean algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

extern void __VERIFIER_error(void);
void reach_error() { __VERIFIER_error(); }

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

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b, computed_gcd;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0);

    computed_gcd = gcd(a, b);

    // Expected properties:
    // - GCD is non-negative and divides both numbers
    __VERIFIER_assert(computed_gcd >= 0);

    printf("GCD of %d and %d is %d\n", a, b, computed_gcd);
    return 0;
}