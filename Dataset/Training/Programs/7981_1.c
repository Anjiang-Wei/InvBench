// Compute the greatest common divisor (GCD) of two non-negative integers
#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
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
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    int result = gcd(a, b);

    // Verification conditions
    __VERIFIER_assert(result >= 0);

    printf("GCD of %d and %d is %d\n", a, b, result);
    return 0;
}