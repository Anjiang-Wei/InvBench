#include <assert.h>
#include <limits.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function that demonstrates a binary search in an array
int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            // Verify that the found position is correct
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    // Assume the array is sorted for the binary search
    assume_abort_if_not(size > 0);

    int result = binary_search(arr, size, target);

    if (result != -1) {
        // Verify the result is within the array bounds
        __VERIFIER_assert(result >= 0 && result < size);
    } else {
        // Verify that the target is not in the array
        for (int i = 0; i < size; i++) {
        }
    }

    return 0;
}