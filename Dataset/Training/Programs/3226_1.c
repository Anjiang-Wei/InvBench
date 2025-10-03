#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);

void reach_error(void) {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Program to compute the greatest common divisor (GCD) of two numbers
   using the Euclidean algorithm with verification logic integrated */

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume both numbers are non-negative for the computation of GCD
    if (a < 0 || b < 0) {
        return 0;
    }

    int original_a = a;
    int original_b = b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    // Postconditions to verify
    __VERIFIER_assert(a >= 0);

    printf("The GCD is: %d\n", a);

    return 0;
}