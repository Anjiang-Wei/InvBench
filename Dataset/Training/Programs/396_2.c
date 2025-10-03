#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Program involves finding a fixed point for a simple computation
// involving the sum of a sequence with zero check.
int main() {
    int sum = 0;
    int current = 0;
    int target = __VERIFIER_nondet_int(); // Target sum (nondeterministic choice)

    if (target < 0) {
        return 0; // Avoid negative targets for simplicity
    }

    int iterations = 0;
    while (iterations < 100 && sum < target) { // Limit iterations for safety checks
        int step = __VERIFIER_nondet_int();    // Nondeterministic step
        if (step < 0) {
            step = 0; // Ensure step is non-negative
        }

        current += step;
        sum += current;
    }

    // Assert that the loop has correctly computed a sum at least equal to the target
    __VERIFIER_assert(sum >= target);
    return 0;
}