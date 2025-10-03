#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    // Variables for computation
    int start, target, steps;
    int current;

    // Non-deterministic assignment
    start = __VERIFIER_nondet_int();
    target = __VERIFIER_nondet_int();
    steps = __VERIFIER_nondet_int();

    // Assuming certain constraints for meaningful computation
    assume_abort_if_not(target > start);
    assume_abort_if_not(steps > 0);

    current = start;

    // Main computation loop
    while (current < target) {
        current += steps; // Increment current position in steps
        if (current > target) {
            current = target; // Ensure not to exceed target
        }
    }

    // After the loop, current should match the target exactly
    __VERIFIER_assert(current == target);

    return 0;
}