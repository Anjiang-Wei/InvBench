/* Calculate the Greatest Common Divisor (GCD) using a combinational approach. */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_combination.c", 3, "reach_error"); }
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
    int gcd_value = 1;
    int i;

    assume_abort_if_not(a >= 1 && b >= 1);

    /* Find all common divisors and capture the largest */
    for (i = 1; i <= (a < b ? a : b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd_value = i;
        }
    }

    return gcd_value;
}

int main() {
    int a, b, result;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && b > 0);

    result = gcd(a, b);

    /* Assume this is a property we'd like to check: the value returned should divide both a and b */
    __VERIFIER_assert((a % result == 0) && (b % result == 0));

    printf("GCD of %d and %d is %d\n", a, b, result);

    return 0;
}