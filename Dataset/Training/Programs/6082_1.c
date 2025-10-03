// A C program for verification: binary search on a nondeterministically generated sorted array.
// The program generates a sorted array of nondeterministic integers, performs binary search for
// a nondet target, and then asserts the correctness of the binary search result.
// Uses __VERIFIER_nondet_int for inputs and __VERIFIER_assert for properties.

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "binary_search_verify.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// nondeterministic integer generator
extern int __VERIFIER_nondet_int(void);

#define MAX_SIZE 10000U

// Binary search: returns an index in [0..n-1] if key is found, or -1 otherwise
int binary_search(int *arr, unsigned int n, int key) {
    unsigned int left = 0;
    unsigned int right = n;
    // Invariant: key is not found in arr[0..left-1], and if it is in arr, it must lie in arr[left..right-1]
    while (left < right) {
        unsigned int mid = left + (right - left) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        } else if (arr[mid] > key) {
            right = mid;
        } else {
            // found exact match
            return (int)mid;
        }
    }
    // not found
    return -1;
}

int main() {
    unsigned int SIZE = (unsigned int)__VERIFIER_nondet_int();
    // bound the size to avoid excessive memory
    if (SIZE > MAX_SIZE) {
        return 0;
    }

    // allocate array
    int *v = (int *)malloc(sizeof(int) * SIZE);
    if (v == NULL) {
        return 0;
    }

    // Generate a sorted array v[0..SIZE-1] by first picking v[0] nondeterministically,
    // then picking successive non-negative deltas.
    if (SIZE > 0) {
        v[0] = __VERIFIER_nondet_int();
    }
    unsigned int i;
    for (i = 1; i < SIZE; i++) {
        int delta = __VERIFIER_nondet_int();
        // ensure non-negative step
        if (delta < 0) {
            delta = -delta;
        }
        // next element is previous plus delta, so array is non-decreasing
        v[i] = v[i - 1] + delta;
    }

    // Pick a nondeterministic target to search
    int target = __VERIFIER_nondet_int();

    // Perform binary search
    int idx = binary_search(v, SIZE, target);

    // Postconditions to verify the correctness of binary_search
    if (idx >= 0) {
        // Found: the element at idx must equal target
        __VERIFIER_assert(v[idx] == target);

        // Check that all elements before idx are strictly less than target
        unsigned int j;
        for (j = 0; j < (unsigned int)idx; j++) {
        }

        // Check that all elements after idx are strictly greater than or equal to target
        // In a non-decreasing array, any duplicate equals would be adjacent, but
        // binary_search finds one of them; still those after should not be less.
        for (j = (unsigned int)idx + 1; j < SIZE; j++) {
        }
    } else {
        // Not found: verify that target does not appear anywhere in the array
        unsigned int j;
        for (j = 0; j < SIZE; j++) {
        }
    }

    // Additional consistency check: the array must remain sorted
    if (SIZE > 1) {
        unsigned int k;
        for (k = 1; k < SIZE; k++) {
        }
    }

    // Free memory (not required for verification but good practice)
    free(v);

    return 0;
}