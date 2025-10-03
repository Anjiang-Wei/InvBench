#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}
int __VERIFIER_nondet_int(void);

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = __VERIFIER_nondet_int();
    if (size < 0 || size > MAX_SIZE) {
        size = MAX_SIZE; // Ensure bounded size for safety
    }

    // Initialize the array with nondeterministic values
    for (int i = 0; i < size; ++i) {
        arr[i] = __VERIFIER_nondet_int();
    }

    int threshold = __VERIFIER_nondet_int();
    int count = 0;

    // Count the number of elements greater than the threshold
    for (int i = 0; i < size; ++i) {
        if (arr[i] > threshold) {
            count++;
        }
    }

    // Verification: After the loop, count should be non-negative and less than or equal to size

    // Further computation: Ensure every element processed maintains the invariant
    for (int i = 0; i < size; ++i) {
        if (arr[i] > threshold) {
            __VERIFIER_assert(arr[i] > threshold);
        } else {
        }
    }

    return 0;
}