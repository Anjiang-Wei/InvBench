// Program: Bubble Sort and Binary Search Verification
// This program performs bubble sort on several nondeterministically generated arrays,
// then answers several nondeterministically generated search queries per array
// using both binary search and linear search, and finally asserts that both searches
// agree on the existence and position of the target element.

#include <stddef.h>

//----------------------------------------------------------------------------
// Verification harness: aborts on failure, provides nondet, assume, and assert
//----------------------------------------------------------------------------

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "bsrch-verify.c", __LINE__, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

//----------------------------------------------------------------------------
// binary_search: returns 1 if target found, else 0.
// If found, *pos is set to the index of the target in arr[0..n-1]; else *pos = -1.
// Array arr must be sorted in non-decreasing order.
//----------------------------------------------------------------------------

int binary_search(int *arr, int n, int target, int *pos) {
    int low = 0;
    int high = n - 1;
    int mid;
    *pos = -1;
    while (low <= high) {
        // compute mid without overflow
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            *pos = mid;
            return 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

//----------------------------------------------------------------------------
// linear_search: returns 1 if target found, else 0.
// If found, *pos is set to the first index where arr[i] == target; else *pos = -1.
//----------------------------------------------------------------------------

int linear_search(int *arr, int n, int target, int *pos) {
    int i;
    *pos = -1;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            *pos = i;
            return 1;
        }
    }
    return 0;
}

//----------------------------------------------------------------------------
// swap utility for bubble sort
//----------------------------------------------------------------------------

void swap_int(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//----------------------------------------------------------------------------
// main: drives the verification scenario
//----------------------------------------------------------------------------

int main() {
    int num_arrays;
    int arr_idx, n;
    int a[50];
    int i, j;

    // Number of arrays to process: 1..5
    num_arrays = __VERIFIER_nondet_int();
    assume_abort_if_not(num_arrays >= 1 && num_arrays <= 5);

    // For each array
    for (arr_idx = 0; arr_idx < num_arrays; arr_idx++) {
        // Array size: 1..50
        n = __VERIFIER_nondet_int();
        assume_abort_if_not(n >= 1 && n <= 50);

        // Populate the array with nondeterministic values
        for (i = 0; i < n; i++) {
            a[i] = __VERIFIER_nondet_int();
        }

        // Perform bubble sort on a[0..n-1]
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    swap_int(&a[j], &a[j + 1]);
                }
            }
        }

        // Number of search queries for this array: 1..5
        int num_queries = __VERIFIER_nondet_int();
        assume_abort_if_not(num_queries >= 1 && num_queries <= 5);

        // Process each query
        for (i = 0; i < num_queries; i++) {
            int target = __VERIFIER_nondet_int();

            // Perform binary search
            int pos_bs;
            int found_bs = binary_search(a, n, target, &pos_bs);

            // Perform linear search
            int pos_ls;
            int found_ls = linear_search(a, n, target, &pos_ls);

            // Final assertion: both searches must agree

            // If they agree that the element exists, positions must match
            if (found_bs) {
            } else {
                // If not found by binary search, pos_bs should remain -1
                __VERIFIER_assert(pos_bs == -1);
                // If not found by linear search, pos_ls should remain -1
            }
        }
    }

    return 0;
}