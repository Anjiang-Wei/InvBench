#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

/*
  The following program performs binary search on a sorted array.
  Precondition: The array is sorted in non-decreasing order.
*/

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[10];

    // Initialize array with sorted values (non-decreasing order)
    for (int i = 0; i < 10; ++i) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(i == 0 || arr[i] >= arr[i - 1]);
    }

    int target = __VERIFIER_nondet_int();

    int index = binary_search(arr, 10, target);

    // Postcondition: The target should be found where indicated by index, or index is -1 if not present
    if (index != -1) {
        __VERIFIER_assert(arr[index] == target);
    }

    return 0;
}