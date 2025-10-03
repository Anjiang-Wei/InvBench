#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int target = __VERIFIER_nondet_int();
    assume_abort_if_not(target > 0 && target <= 20); // Ensure target is within a defined range

    int sum = 0;
    int steps = 0;

    // Simulate the sum of squares sequence
    while (sum < target && steps < 10) {
        steps++;
        sum += steps * steps;

        // Ensure safety condition that should always hold
    }

    // Verify the final condition of sum being at least the target
    __VERIFIER_assert(sum >= target);

    return 0;
}