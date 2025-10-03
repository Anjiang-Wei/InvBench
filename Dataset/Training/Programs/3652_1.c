#include <stdio.h>

/*
  Power calculation algorithm with constraints
  Computes power(a, b) and checks constraints
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error(void) { __assert_fail("0", "power.c", 12, "reach_error"); }
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

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int main() {
    int base = __VERIFIER_nondet_int();
    int exp = __VERIFIER_nondet_int();

    assume_abort_if_not(base >= 0);
    assume_abort_if_not(exp >= 0 && exp < 10);

    int result = power(base, exp);

    // Verification of constraints
    __VERIFIER_assert(result >= 0);
    if (exp == 0) {
    }
    if (base == 0 && exp > 0) {
    }

    printf("Base: %d, Exponent: %d, Result: %d\n", base, exp, result);
    return 0;
}