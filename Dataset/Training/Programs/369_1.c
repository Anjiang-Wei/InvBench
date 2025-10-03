#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 8, "reach_error"); }
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

// Function to perform binary exponentiation
long long binary_exponentiation(int base, int exp) {
    long long result = 1;
    long long power = base;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * power;
        }
        power = power * power;
        exp = exp / 2;
    }
    return result;
}

int main() {
    int base, exp;
    long long computed_result, expected_result;

    base = __VERIFIER_nondet_int();
    exp = __VERIFIER_nondet_int();

    assume_abort_if_not(base >= 0 && base <= 5); // Restrict base
    assume_abort_if_not(exp >= 0 && exp <= 5);   // Restrict exponent

    computed_result = binary_exponentiation(base, exp);
    expected_result = 1;

    // Compute the expected result using simple multiplication
    for (int i = 0; i < exp; i++) {
        expected_result *= base;
    }

    // Assert the correctness of the binary exponentiation function
    __VERIFIER_assert(computed_result == expected_result);

    // Print results for manual verification if needed (not essential for verification tools)
    printf("Base: %d, Exponent: %d, Result: %lld\n", base, exp, computed_result);

    return 0;
}