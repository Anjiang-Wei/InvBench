#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
This program performs a simulation of a bouncing ball, which loses energy
with each bounce. The height it reaches decreases by a factor on each bounce.
We assert that the height never becomes negative during the simulation.
*/

int main() {
    int initialHeight = __VERIFIER_nondet_int();
    int bounceFactor = __VERIFIER_nondet_int(); // This should be a value between 0 and 100

    // Ensure valid inputs for initial height and bounce factor
    if (!(initialHeight > 0 && bounceFactor > 0 && bounceFactor < 100)) {
        return 0;
    }

    int currentHeight = initialHeight;
    int bounces = 0;

    while (currentHeight > 0 && __VERIFIER_nondet_bool()) {
        currentHeight = (currentHeight * bounceFactor) / 100;
        bounces++;

        // Assert that the current height never becomes negative
        __VERIFIER_assert(currentHeight >= 0);
    }

    // Optionally, we can assert that the number of bounces is reasonable
}