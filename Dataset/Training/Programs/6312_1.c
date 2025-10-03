#include <stdbool.h>
#include <stdio.h>

/* A program that computes the greatest common divisor (GCD) of two non-negative integers */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 7, "reach_error"); }
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

    assume_abort_if_not(x >= 0);
    assume_abort_if_not(y >= 0);

    int result = gcd(x, y);

    // Simple property to check GCD result
    // GCD of x and 0 or y and 0 should be the number itself
    if (x == 0 || y == 0) {
        __VERIFIER_assert(result == (x == 0 ? y : x));
    } else {
    }

    printf("GCD of %d and %d is: %d\n", x, y, result);
    return 0;
}