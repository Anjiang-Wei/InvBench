// Verification Task inspired by the provided examples

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verification_task.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int x = 0;
    int y = 5;
    int z = 10;
    int loop_count = 0;

    // Assume inputs to be within certain bounds
    int input = __VERIFIER_nondet_int();
    assume_abort_if_not(input >= 1 && input <= 10);

    // Loop with constraints and conditional logic
    while (loop_count < 100) {
        __VERIFIER_assert(x + y + z < 100);

        if (x < 50) {
            x += input;
        } else if (y < 50) {
            y += input;
        } else {
            z += input;
        }

        // Constraint checks
        if (x + y + z >= 90) {
            break;
        }

        // Increment loop count
        loop_count++;
    }

    // Final assertions to test program invariants

    return 0;
}