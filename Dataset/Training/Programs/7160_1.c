#include <assert.h>

extern void reach_error(void) { assert(0); }

// External functions for nondeterministic inputs
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Assumption mechanism
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to encapsulate verification and checking mechanism
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int max = __VERIFIER_nondet_int(); // Get an arbitrary limit
    assume_abort_if_not(max > 0);      // Assume it is positive to avoid trivial cases

    int sum = 0, count = 0;

    // Initialize an arbitrary array with nondeterministic size and values
    int array_size = __VERIFIER_nondet_int();
    assume_abort_if_not(array_size > 0 && array_size <= 100); // To ensure reasonable size
    int array[array_size];

    for (int i = 0; i < array_size; i++) {
        array[i] = __VERIFIER_nondet_int(); // Fill with arbitrary values
        assume_abort_if_not(array[i] >= 0); // Assume non-negative values for simplicity
    }

    // Compute the sum of elements in the array until it exceeds 'max'
    for (int i = 0; i < array_size; i++) {
        sum += array[i];
        count++;
        if (sum > max) {
            break;
        }
    }

    // Verify the sum does not exceed the maximum value by more than one element's worth
    __VERIFIER_assert(sum <= max + (count > 0 ? array[count - 1] : 0));

    return 0;
}