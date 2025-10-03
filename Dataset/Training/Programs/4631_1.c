#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
   This program simulates the process of a bounded random walk.
   The walk will move between -10 and +10 based on random steps,
   ensuring that it remains within these bounds.
*/

int main() {
    int position = 0;
    int step;
    int lower_bound = -10, upper_bound = 10;
    int steps_taken = 0;
    const int max_steps = 100;

    // Ensure position starts within bounds
    if (!(position >= lower_bound && position <= upper_bound)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool() && steps_taken < max_steps) {
        step = __VERIFIER_nondet_int(); // Random step size

        if (step >= -3 && step <= 3) { // Constraint step to values between -3 and 3
            position += step;

            // Ensure position stays within bounds
            if (position > upper_bound) {
                position = upper_bound;
            } else if (position < lower_bound) {
                position = lower_bound;
            }
        }

        steps_taken++;
    }

    // Check final position is within bounds
    __VERIFIER_assert(position >= lower_bound && position <= upper_bound);

    return 0;
}