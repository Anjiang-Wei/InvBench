#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
  Compute the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
  The function should terminate with correctly computing the GCD.
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
    int a, b;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    // Compute gcd
    int result = gcd(a, b);

    __VERIFIER_assert(result > 0);

    printf("The GCD of %d and %d is %d\n", a, b, result);

    return 0;
}