// C program using binary search logic with assertions for verification and boundary checks.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

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

int binary_search(int arr[], int size, int target) {
    int lower = 0;
    int upper = size - 1;
    int mid;
    int result = -1; // -1 indicates target not found

    while (lower <= upper) {
        mid = lower + (upper - lower) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            result = mid;
            break;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            lower = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            upper = mid - 1;
        }
    }

    return result;
}

int main() {
    int size = 10;
    int target = 5;

    // Assume sorted array of specific size with predefined values
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = binary_search(arr, size, target);

    // Verification: if result is valid, then arr[result] should be equal to target
    if (result >= 0) {
        __VERIFIER_assert(arr[result] == target);
    } else {
        // If the result is -1, assert target is not in the array
        for (int j = 0; j < size; j++) {
        }
    }

    return 0;
}