/* Simple program to compute the power of a number using exponentiation by squaring. */

#include <assert.h> // For using assert
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "power_by_squaring.c", 6, "reach_error");
}

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

// Function to compute x^y using exponentiation by squaring
long long power(long long x, int y) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = result * x; // If y is odd, multiply x with the result
        }
        y = y / 2;
        x = x * x; // Change x to x^2
    }
    return result;
}

int main() {
    int base, exp;
    long long result;

    base = __VERIFIER_nondet_int(); // Non-deterministic base
    exp = __VERIFIER_nondet_int();  // Non-deterministic exponent

    assume_abort_if_not(base >= 1 && base <= 10); // Example constraint on base
    assume_abort_if_not(exp >= 0 && exp <= 10);   // Example constraint on exponent

    result = power(base, exp);

    printf("Result of %d^%d is %lld\n", base, exp, result);

    // Verify using a simple assertion
    __VERIFIER_assert(result >= 1); // The lowest possible power is 1 (when both base and exp are valid)

    return 0;
}