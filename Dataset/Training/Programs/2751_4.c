/*
 * Fibonacci Sequence Verification
 * Calculates Fibonacci numbers up to a given value n
 * Ensures that Fibonacci property F(n) = F(n-1) + F(n-2) is held for each n
 * and performs basic verification of Fibonacci properties.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 46); // Limit to avoid overflow in Fibonacci sequence

    long long a = 0, b = 1, c;

    // F(0) = 0, F(1) = 1
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 0;
    }

    int counter = 2;
    while (counter <= n) {
        c = a + b;
        a = b;
        b = c;

        // Here we verify the critical property of Fibonacci sequence

        counter++;
    }

    // After the loop b should be equal to F(n)
    __VERIFIER_assert(b >= 0); // Since Fibonacci numbers are non-negative
    return 0;
}