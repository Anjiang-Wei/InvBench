/*
  Extended Euclidean Algorithm
  Calculates the Greatest Common Divisor (GCD) of two numbers using the
  Extended Euclidean Algorithm and verifies specific properties throughout the computation.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "ext_euclidean.c", __LINE__, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b;
    int x0 = 1, x1 = 0, x_temp;
    int y0 = 0, y1 = 1, y_temp;
    int q, r, temp_a, temp_b;

    a = __VERIFIER_nondet_int(); // could be replaced with static values for testing
    b = __VERIFIER_nondet_int(); // could be replaced with static values for testing

    assume_abort_if_not(a > 0 && b > 0);

    temp_a = a;
    temp_b = b;

    while (b != 0) {
        q = a / b;
        r = a % b;

        a = b;
        b = r;

        x_temp = x0 - q * x1;
        y_temp = y0 - q * y1;

        x0 = x1;
        x1 = x_temp;
        y0 = y1;
        y1 = y_temp;

        // Property: a % b == r, holds throughout all iteration
    }

    // Final property to assert: GCD(a, b) is equal to the last non-zero remainder
    __VERIFIER_assert(temp_a * x0 + temp_b * y0 == a);

    // Output result (GCD)
    printf("GCD is: %d\n", a);

    return 0;
}