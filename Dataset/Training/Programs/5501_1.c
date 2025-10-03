#include <stdio.h>

/*
Calculating the power of a number using exponentiation by squaring method.
This method can be used to efficiently raise a number to a large power.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "exp_by_squaring.c", 10, "reach_error"); }
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

long long exp_by_squaring(int base, int exp) {
    if (exp < 0) {
        return 0; // Undefined for negative exponents
    }
    long long result = 1;
    long long p = base;

    assume_abort_if_not(base >= 0 && base <= 10); // Restrict base for simplicity

    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= p;
        }
        exp /= 2;
        p *= p;
    }

    return result;
}

int main() {
    int base = __VERIFIER_nondet_int();
    int exp = __VERIFIER_nondet_int();

    assume_abort_if_not(exp >= 0 && exp <= 20); // Restrict exponent for simplicity

    long long power = exp_by_squaring(base, exp);

    // Check expected conditions
    __VERIFIER_assert(exp >= 0);

    printf("%d^%d = %lld\n", base, exp, power);

    return 0;
}