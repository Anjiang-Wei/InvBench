/* Binary search for position of an element in a rotated sorted array */
/* This program includes a constraint checking if intended value exists in the array */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error() { assert(0); }

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
    return;
}

// Function to find the position of target in array
int find_position(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        __VERIFIER_assert(mid >= 0 && mid < size); // ensuring index stays in bounds

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[left] <= arr[mid]) {
            // Left part is sorted
            if (target >= arr[left] && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right part is sorted
            if (target > arr[mid] && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[7];
    // Fill the rotated sorted array
    arr[0] = 11;
    arr[1] = 15;
    arr[2] = 8;
    arr[3] = 9;
    arr[4] = 10;
    arr[5] = 2;
    arr[6] = 5;

    int size = sizeof(arr) / sizeof(arr[0]);
    int target = __VERIFIER_nondet_int();

    assume_abort_if_not(target >= 2 && target <= 15); // Giving valid target in arr

    int found_index = find_position(arr, size, target);
}