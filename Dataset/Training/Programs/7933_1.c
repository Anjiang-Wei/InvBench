/*
  Power Computation using Exponentiation by Squaring
  Computes power of a number (base^exp) using an efficient method
  and checks if the result is equal to a known value.
*/
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power_computation.c", 8, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int(void);

// Function to compute power using Exponentiation by Squaring
long long int power(int base, int exp) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 != 0) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int main() {
    int base, exp;
    long long int computed_power;

    base = __VERIFIER_nondet_int();
    exp = __VERIFIER_nondet_int();

    // Assumptions to limit the range for demonstrational purposes
    if (base < 0 || base > 10) {
        return 0;
    }
    if (exp < 0 || exp > 10) {
        return 0;
    }

    computed_power = power(base, exp);

    // A simple check: if base = 2 and exp = 3, computed_power should be 8
    if (base == 2 && exp == 3) {
        __VERIFIER_assert(computed_power == 8);
    }

    return 0;
}