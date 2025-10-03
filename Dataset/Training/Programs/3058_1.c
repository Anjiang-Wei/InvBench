#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* This program performs some arithmetic operations with constraints and verifies that certain bounds are maintained during execution.
   It models a situation where two variables interact under a set condition, influenced by unpredictable inputs.
   The correctness property asserts that "sum" is always greater than or equal to the original "start" value.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int start = 0; // Start from zero
    int sum = start;

    if (!(a > 0 && b > 0)) {
        return 0; // Ensure both a and b are positive
    }

    while (__VERIFIER_nondet_bool()) {
        if (a % 2 == 1) { // If a is odd
            sum = sum + b;
            a--;                 // Make a even
        } else if (b % 2 == 0) { // If b is even
            sum = sum + a * 2;
            b--; // Make b odd
        } else {
            sum += 1; // Just increment if conditions aren't met
            a = a / 2;
            b = b / 2;
        }
        __VERIFIER_assert(sum >= start); // Ensure sum has not decreased past the original value
    }

    printf("Final sum = %d\n", sum); // To give some execution output

    return 0;
}