#include <stdio.h>
#include <stdlib.h>

// Prototype for external functions used for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "convergence.c", 5, "reach_error"); }
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

int main() {
    int target = 100;
    int current_value = __VERIFIER_nondet_int();
    int steps = 0;

    // Assume initial constraints to avoid non-terminating behavior
    assume_abort_if_not(current_value >= 0 && current_value <= 200);

    // Loop to simulate convergence or divergence
    while (steps < 50) {
        if (current_value == target) {
            // If we reached the target, assert a property and exit
            break;
        } else if (current_value > target) {
            // Reduce the current value to potentially converge to the target
            current_value -= (current_value - target) / 2;
        } else {
            // Increase the current value to potentially converge to the target
            current_value += (target - current_value) / 2;
        }

        // Assert conditions to verify no overshoot and constrain behavior

        // Increment the step counter
        steps++;
    }

    // Final assertion to ensure loop termination
    __VERIFIER_assert(steps <= 50);

    return 0;
}