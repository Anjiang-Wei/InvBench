#include <assert.h>
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define THRESHOLD 50

int main() {
    int count = __VERIFIER_nondet_int();
    assume_abort_if_not(count >= 0); // Ensure that count starts at a non-negative number

    int sum = 0;
    int i;

    for (i = 0; i < count; ++i) {
        int value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= 0); // Assume all input values are non-negative

        sum += value;

        // If sum exceeds a certain threshold, reset it
        if (sum > THRESHOLD) {
            sum = 0;
        }
    }

    // Verify that the sum at the end of computation remains below a particular bound
    __VERIFIER_assert(sum <= THRESHOLD);

    return 0;
}