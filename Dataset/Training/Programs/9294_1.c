// C Program for Binary Search with automated verification functions

#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "binary_search.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

#define SIZE 10

int binary_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int array[SIZE];
    int i;

    // Fill the array with nondeterministic values ensuring ascending order
    for (i = 0; i < SIZE; i++) {
        if (i == 0) {
            array[i] = __VERIFIER_nondet_int();
            assume_abort_if_not(array[i] >= 0); // Ensure non-negative values
        } else {
            int next_value = __VERIFIER_nondet_int();
            assume_abort_if_not(next_value >= array[i - 1]); // Make sure array is sorted
            array[i] = next_value;
        }
    }

    int target = __VERIFIER_nondet_int();

    // Ensure that the target is one of the elements in the array
    int index = __VERIFIER_nondet_int();
    assume_abort_if_not(index >= 0 && index < SIZE);
    target = array[index];

    int result = binary_search(array, SIZE, target);

    // Verify the result
    if (result != -1) {
        __VERIFIER_assert(array[result] == target);
    }

    return 0;
}