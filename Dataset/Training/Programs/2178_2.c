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
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();

#define MAX_SIZE 100

// Function to perform binary search on a sorted array
int binary_search(int sorted_array[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Verify midpoint logic

        if (sorted_array[mid] == target) {
            return mid;
        }
        if (sorted_array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // If element is not present in array, return -1
    return -1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= MAX_SIZE);

    int sorted_array[MAX_SIZE];

    // Initialize a sorted array
    for (int i = 0; i < N; i++) {
        sorted_array[i] = i * 2; // e.g., 0, 2, 4, ..., 2*(N-1)
    }

    int target = __VERIFIER_nondet_int();

    int result = binary_search(sorted_array, N, target);

    printf("Result of binary search: %d\n", result);

    // Validate that if the result index is valid, the target should exist at that index
    if (result != -1) {
        __VERIFIER_assert(sorted_array[result] == target);
    }

    return 0;
}