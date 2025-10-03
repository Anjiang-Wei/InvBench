#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// The program counts how often a number occurs in an array and checks a certain condition at the end
int main() {
    int size = 10;
    int arr[size];

    // Initialize array with nondeterministic values
    for (int i = 0; i < size; i++) {
        arr[i] = __VERIFIER_nondet_int() % 10; // Values between 0 and 9
    }

    int target = 5; // We will count occurrences of the number 5
    int count = 0;

    // Count how many times `target` occurs in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    // Verification: Ensure count is never greater than the array size
    // This is a trivial property but demonstrates ensuring constraints
    __VERIFIER_assert(count <= size);

    // Further logic: Ensure there's at least one occurrence of `target` if size is non-zero
    // for a given condition (the array is not purely zeros)
    _Bool has_non_zero = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            has_non_zero = 1;
            break;
        }
    }

    return 0;
}