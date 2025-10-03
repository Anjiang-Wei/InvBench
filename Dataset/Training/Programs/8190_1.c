#include <stdio.h>
#include <stdlib.h>

/*
Euclidean Algorithm for GCD
computes the Greatest Common Divisor (GCD) of two numbers a and b
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_example.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, gcd_result;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0);

    gcd_result = gcd(a, b);

    __VERIFIER_assert(gcd_result > 0); // The GCD of two positive integers must be positive.

    printf("GCD of %d and %d is %d\n", a, b, gcd_result);

    return 0;
}