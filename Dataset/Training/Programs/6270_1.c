#include <assert.h>
#include <stdlib.h>

extern void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

/*
 * Problem description:
 * - The program initializes two counters, `x` and `y`.
 * - `x` starts from a random value, `y` is initialized to 0.
 * - The loop runs until `x` is non-positive.
 * - In each iteration, `x` is decremented and `y` is conditionally incremented based on non-deterministic choice.
 * - After the loop, we check a constraint between `y` and the initial value of `x`.
 */
int main() {
    int x = __VERIFIER_nondet_int();
    int y = 0;
    int initial_x = x; // Store initial value of x for post-loop condition checking

    if (x <= 0) {
        return 0; // No loop execution for non-positive x
    }

    // Loop runs until 'x' becomes non-positive
    while (x > 0) {
        x--; // Decrement x
        if (__VERIFIER_nondet_bool()) {
            y++; // Increment y based on a random choice
        }
    }

    // Post-loop condition: y should not exceed the initial value of x
    __VERIFIER_assert(y <= initial_x);
    return 0;
}