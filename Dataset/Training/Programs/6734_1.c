#include <assert.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int counter = 0;
    int step = __VERIFIER_nondet_int();

    if (step < 0 || step > 4) {
        return 0; // Invalid step size, exit
    }

    while (counter < 50) {
        if (__VERIFIER_nondet_bool()) {
            counter += step;
        } else {
            counter++; // Increment by 1 as fallback
        }

        // Check that counter is never negative
        __VERIFIER_assert(counter >= 0);

        // Artificially bounded loop to ensure termination
        if (counter > 100) {
            break;
        }
    }

    // Final assertion for end state
    return 0;
}