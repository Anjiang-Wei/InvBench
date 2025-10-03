#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

#define THRESHOLD 10

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program simulates a simple counter mechanism with a cap.
 * The counter increases or decreases based on nondeterministic choices.
 * The goal is to maintain the counter within a certain limit (i.e., THRESHOLD).
 *
 * This demonstrates keeping computations within predetermined bounds.
 */

int main() {
    int counter = __VERIFIER_nondet_int();
    int cap = __VERIFIER_nondet_int();

    if (!(cap >= THRESHOLD && counter >= 0 && counter <= cap)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        if (__VERIFIER_nondet_bool()) {
            if (counter < cap) {
                counter++;
            }
        } else {
            if (counter > 0) {
                counter--;
            }
        }
    }

    __VERIFIER_assert(counter >= 0 && counter <= cap);
    return 0;
}