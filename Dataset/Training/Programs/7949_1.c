/*
 * Incremental Binary Search with Verification:
 * This program incrementally performs a binary search on an array, ensuring
 * that the item is located correctly if present. If the element is not present
 * in the array, it will also handle such cases appropriately.
 */

#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "incremental_bsearch.c", 15, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int found = -1; // Indicating not found

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If target is present at mid
        if (arr[mid] == target) {
            found = mid;
            break;
        }

        // If target greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return found;
}

int main() {
    const int MAX_SIZE = 10;
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size > 0 && size <= MAX_SIZE);

    int arr[MAX_SIZE];
    for (int i = 0; i < size; ++i) {
        arr[i] = __VERIFIER_nondet_int();
        // Ensure the array is sorted or assume it in ascending order
        if (i > 0) {
            assume_abort_if_not(arr[i] >= arr[i - 1]);
        }
    }

    int target = __VERIFIER_nondet_int();
    int index = binary_search(arr, size, target);

    // Verification: If the target is found, its index should be valid.
    if (index != -1) {
        __VERIFIER_assert(arr[index] == target);
    }

    return 0;
}