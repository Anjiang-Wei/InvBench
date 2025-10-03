#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error() { assert(0); }

// Mock nondeterministic integer generator
int __VERIFIER_nondet_int(void) {
    return rand() % 101; // returns a pseudo-random number between 0 and 100
}

// Mock nondeterministic boolean generator
_Bool __VERIFIER_nondet_bool(void) {
    return rand() % 2; // returns 0 or 1
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constraint: a + b <= 150
    if (!(a + b <= 150)) {
        return 0;
    }

    int sum = 0;
    int product = 1;

    // Loop that calculates the sum and product of integers from 1 to a
    for (int i = 1; i <= a; i++) {
        sum += i;
        product *= i;
    }

    // Verify that the sum is non-negative and product is positive when a is positive
    if (a > 0) {
        __VERIFIER_assert(product > 0);
    }

    return 0;
}