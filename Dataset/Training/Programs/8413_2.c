#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Algorithm to find the maximum divisor of two numbers
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (a <= 0 || b <= 0) {
        return 0;
    }

    int gcd = 0;
    int min = (a < b) ? a : b;

    while (min > 0) {
        if (a % min == 0 && b % min == 0) {
            gcd = min;
            break;
        }
        min--;
    }

    // Assert that the gcd is calculated correctly
    __VERIFIER_assert(gcd <= a && gcd <= b);

    printf("The greatest common divisor of %d and %d is %d.\n", a, b, gcd);
    return 0;
}