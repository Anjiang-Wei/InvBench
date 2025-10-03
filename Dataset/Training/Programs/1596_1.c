#include <assert.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

/**
 * The goal of this program is to manipulate an array such that the elements
 * are in non-decreasing order after the loop. The loop will swap adjacent
 * elements that are out of order. The correctness criteria is that after
 * the number of steps—where the number is not known beforehand—the array
 * will be sorted.
 */

#define ARRAY_SIZE 5

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int is_sorted(const int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int arr[ARRAY_SIZE];

    // Initialize the array with non-deterministic values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Perform a simple bubble sort
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                sorted = 0;
            }
        }
    }

    // Verify that the array is sorted
    __VERIFIER_assert(is_sorted(arr, ARRAY_SIZE));

    return 0;
}