#include <assert.h>

// This program checks if a generated sequence is equal to an expected arithmetic sequence

extern int __VERIFIER_nondet_int(void);
extern void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int counter = 0;

int main() {
    int start, increment, length;
    int i, currentValue;

    start = __VERIFIER_nondet_int();
    increment = __VERIFIER_nondet_int();
    length = __VERIFIER_nondet_int();

    assume_abort_if_not(length > 0);
    assume_abort_if_not(increment != 0);

    currentValue = start;

    for (i = 0; i < length && counter++ < 20; i++) {
        // Check if the sequence generated is correct
        __VERIFIER_assert(currentValue == start + i * increment);
        currentValue += increment;
    }

    // Ensure that we have generated the expected length of sequence

    return 0;
}