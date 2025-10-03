#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

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

// Function that simulates a binary search on an ordered array
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
    return -1; // Not found
}

int main() {
    int arr[100];
    int i, n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    // Fill the array with non-decreasing values
    for (i = 0; i < n; i++) {
        arr[i] = i + __VERIFIER_nondet_int() % 3; // Ensuring no decreases
    }

    int target = __VERIFIER_nondet_int();

    // Perform a binary search
    int result = binary_search(arr, n, target);

    // Assert that if the result is not -1, the target was found
    if (result != -1) {
        __VERIFIER_assert(arr[result] == target);
    }

    return 0;
}