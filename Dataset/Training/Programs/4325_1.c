#include <stdio.h>
#include <stdlib.h>

/* This program calculates the factorial of a number using a loop.
 * It then verifies if the factorial number equals a known product of that number with a decremental sequence.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 11, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n, k;
    unsigned long long fact = 1, product = 1;

    n = 5; // Testing for a fixed number, can be varied
    k = n;

    assume_abort_if_not(n >= 0 && n <= 20); // Keeping within reasonable bounds for computation

    while (k > 0) {
        fact *= k;
        product *= (n - k + 1);
        k--;
    }

    __VERIFIER_assert(fact == product);

    return 0;
}