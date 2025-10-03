// This program is designed for automated verification tools and performs processing with a condition involving nondeterministic behavior.

#include <stdbool.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a = 0, b = 0, limit = 100;
    int count = 0;
    int step_a, step_b;

    // Initialize with nondeterministic steps
    step_a = __VERIFIER_nondet_int();
    step_b = __VERIFIER_nondet_int();

    // Assume steps are positive but within bounds
    if (step_a < 0 || step_a > 5) {
        step_a = 1;
    }
    if (step_b < 0 || step_b > 5) {
        step_b = 1;
    }

    while (count < 50) {
        if (__VERIFIER_nondet_bool()) {
            if (__VERIFIER_nondet_bool()) {
                a += step_a;
                if (a >= limit) {
                    a = 0; // reset `a` once it reaches the limit
                }
            }
        }

        if (__VERIFIER_nondet_bool()) {
            if (__VERIFIER_nondet_bool()) {
                b += step_b;
                if (b >= limit) {
                    b = 0; // reset `b` once it reaches the limit
                }
            }
        }

        // Perform a processed condition to keep the program balanced
        __VERIFIER_assert(a < limit && b < limit);

        count++;
    }
    return 0;
}