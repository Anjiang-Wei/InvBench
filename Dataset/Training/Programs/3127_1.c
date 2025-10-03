#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program:
Verifies reaching a target number by iteratively doubling a value
in a bounded manner.
Variables: currentValue, target, iterations
Precondition: target > 0 && target is a power of 2
Loop Invariant: currentValue >= 0
Postcondition: currentValue == target
*/
int main() {
    int currentValue = __VERIFIER_nondet_int();
    int target = __VERIFIER_nondet_int();

    if (!(target > 0)) {
        return 0;
    }

    // Verify if target is a power of 2
    if ((target & (target - 1)) != 0) {
        return 0;
    }

    currentValue = 1;
    int iterations = 0;

    while (currentValue < target) {
        // Double the current value
        currentValue *= 2;
        iterations++;

        // Ensure we are within a reasonable limit
        if (iterations > 100) {
            return 0;
        }
    }

    // Postcondition to be verified
    __VERIFIER_assert(currentValue == target);

    return 0;
}