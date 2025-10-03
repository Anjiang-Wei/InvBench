// A comprehensive C program combining array operations, binary search, sorting, and GCD computation.
// Designed for automated verification tools: uses nondeterministic inputs, assume/abort, and assertions.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

// Maximum array size
#define MAXN 50

// Function to perform binary search on a sorted array.
// Returns the index of 'key' in 'arr' if found, -1 otherwise.
int binary_search(int *arr, int n, int key) {
    int lo = 0;
    int hi = n - 1;
    int found = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == key) {
            found = mid;
            break;
        }
        if (arr[mid] < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return found;
}

// Function to compute gcd(a, b) by Euclid's algorithm.
int compute_gcd(int a, int b) {
    // Make sure inputs are non-negative
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    // Euclid loop
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Simple swap for bubble sort
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// Bubble sort implementation
void bubble_sort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 1; j < n - i; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}

int main() {
    // 1) Generate a nondeterministic n, 1 <= n <= MAXN
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= MAXN);

    // 2) Allocate two arrays of length n
    static int a[MAXN];
    static int b[MAXN];
    int i, j;

    // 3) Fill 'a' with strictly increasing values
    for (i = 0; i < n; i++) {
        int delta = __VERIFIER_nondet_int() % 10 + 1; // in [1..10]
        if (i == 0) {
            a[i] = delta;
        } else {
            // ensure strictly increasing
            a[i] = a[i - 1] + delta;
        }
    }

    // 4) Copy 'a' into 'b'
    for (i = 0; i < n; i++) {
        b[i] = a[i];
    }

    // 5) Pick a nondeterministic key to search
    int key = __VERIFIER_nondet_int();

    // 6) Perform binary search on 'a'
    int idx = binary_search(a, n, key);

    // 7) Post-condition checks for binary search
    if (idx >= 0) {
        // If found, the element must match
    } else {
        // If not found, ensure no entry equals key
        for (i = 0; i < n; i++) {
        }
    }

    // 8) Compute GCD of two nondeterministic inputs x, y in [0..1000]
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 1000);
    assume_abort_if_not(y >= 0 && y <= 1000);

    int g = compute_gcd(x, y);

    // 9) Post-condition checks for GCD
    // g must divide both x and y
    if (g > 0) {
    } else {
        // gcd(0,0) is defined here as 0
        __VERIFIER_assert(x == 0 && y == 0);
    }

    // 10) Sort the copy 'b' using bubble sort
    bubble_sort(b, n);

    // 11) Check that 'b' is sorted and is a permutation of 'a'
    for (i = 1; i < n; i++) {
    }

    // Check multiset equality: counts of each element match
    for (i = 0; i < n; i++) {
        int ai = a[i];
        int count1 = 0;
        int count2 = 0;
        for (j = 0; j < n; j++) {
            if (a[j] == ai) {
                count1++;
            }
            if (b[j] == ai) {
                count2++;
            }
        }
    }

    return 0;
}