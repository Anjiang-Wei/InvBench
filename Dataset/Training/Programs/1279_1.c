#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 4, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

/*
 * New Program:
 * - Computes the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
 */

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Ensure x and y are non-negative for a meaningful GCD computation
    assume_abort_if_not(x >= 0);
    assume_abort_if_not(y >= 0);

    int result = gcd(x, y);

    // Verifying a post-condition: GCD of a number and itself is the number
    if (x == y) {
        __VERIFIER_assert(result == x);
    }

    printf("GCD of %d and %d is %d\n", x, y, result);

    return 0;
}