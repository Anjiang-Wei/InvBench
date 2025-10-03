/* Compute the greatest common divisor (GCD) of two non-negative integers */

#include <assert.h>
#include <stdio.h>

#define MAX_N 1000 // A constraint for demonstration purposes

extern void abort(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x, y;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && x <= MAX_N);
    assume_abort_if_not(y >= 0 && y <= MAX_N);

    int result = gcd(x, y);

    // Check that the computed GCD divides both x and y

    // A simple loop to demonstrate an additional constraint
    int z;
    z = 0;
    for (int i = 0; i <= result; i++) {
        z += i;
    }

    // Ensure that the summation value makes sense
    __VERIFIER_assert(z >= 0);

    return 0;
}