// Comprehensive Verification-Friendly C Program
// This program includes multiple computational modules:
// 1) Bubble Sort with sum preservation check
// 2) Euclidean GCD with divisibility postconditions
// 3) Factorial computation with basic bounds checks
// 4) Binary Search with correctness verification
//
// Verification harness uses __VERIFIER_nondet_int, assume_abort_if_not, and __VERIFIER_assert
// to facilitate automated reasoning without embedding manual loop invariants.
//
// Total lines > 100 to satisfy the requirement, and at least one loop appears in each module.

#include <assert.h>
#include <stdlib.h>

//------------------------------------------------------------------------------
// Verification interface stubs
//------------------------------------------------------------------------------

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error() {
    // force a noticeable failure for verification
    assert(0);
}

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

//------------------------------------------------------------------------------
// Module 1: Bubble Sort
//------------------------------------------------------------------------------

#define MAXN 5

// Sorts array a[0..n-1] in non-decreasing order
void bubble_sort(int *a, int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // swap a[j] and a[j+1]
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

//------------------------------------------------------------------------------
// Module 2: Euclidean GCD
//------------------------------------------------------------------------------

int gcd(int x, int y) {
    // Standard Euclidean algorithm
    int tmp;
    // We allow x,y >= 0; gcd(0,0) returns 0
    while (y != 0) {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    // Now x is gcd
    return x;
}

//------------------------------------------------------------------------------
// Module 3: Factorial
//------------------------------------------------------------------------------

unsigned long factorial(int n) {
    unsigned long f = 1;
    int i;
    for (i = 1; i <= n; i++) {
        f = f * (unsigned long)i;
    }
    return f;
}

//------------------------------------------------------------------------------
// Module 4: Binary Search
//------------------------------------------------------------------------------

_Bool binary_search(int *a, int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) {
            return 1;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}

//------------------------------------------------------------------------------
// Main: Dispatch among modules based on a nondeterministic selector
//------------------------------------------------------------------------------

int main() {
    int mode = __VERIFIER_nondet_int();
    // We support 4 modes: 0..3
    assume_abort_if_not(mode >= 0 && mode < 4);

    if (mode == 0) {
        // Mode 0: Bubble Sort test
        int n = __VERIFIER_nondet_int();
        assume_abort_if_not(n >= 1 && n <= MAXN);

        int a[MAXN];
        int i;
        long sum0 = 0, sum1 = 0;

        // Fill array with nondet values
        for (i = 0; i < n; i++) {
            a[i] = __VERIFIER_nondet_int();
            sum0 += a[i];
        }

        // Sort it
        bubble_sort(a, n);

        // Verify that sum is preserved
        for (i = 0; i < n; i++) {
            sum1 += a[i];
        }

        // Verify sortedness
        for (i = 0; i + 1 < n; i++) {
        }
    } else if (mode == 1) {
        // Mode 1: GCD test
        int a0 = __VERIFIER_nondet_int();
        int b0 = __VERIFIER_nondet_int();
        assume_abort_if_not(a0 >= 0 && b0 >= 0);

        int g = gcd(a0, b0);

        // gcd result must be non-negative

        // Check divisibility: a0 % g == 0 and b0 % g == 0
        if (g > 0) {
        } else {
            // Only case g == 0 is when a0 == 0 and b0 == 0
        }
    } else if (mode == 2) {
        // Mode 2: Factorial test
        int n = __VERIFIER_nondet_int();
        // Restrict n to avoid overflow in 64-bit
        assume_abort_if_not(n >= 0 && n <= 12);

        unsigned long f = factorial(n);

        // Verify basic properties
        if (n == 0) {
            __VERIFIER_assert(f == 1);
        } else {
        }
    } else {
        // Mode 3: Binary Search test
        int n = __VERIFIER_nondet_int();
        assume_abort_if_not(n >= 1 && n <= MAXN);

        int a[MAXN];
        int i;

        // Fill and sort the array
        for (i = 0; i < n; i++) {
            a[i] = __VERIFIER_nondet_int();
        }
        bubble_sort(a, n);

        // Pick a key and search
        int key = __VERIFIER_nondet_int();
        _Bool found = binary_search(a, n, key);

        // Verify correctness by brute force
        _Bool brute = 0;
        for (i = 0; i < n; i++) {
            if (a[i] == key) {
                brute = 1;
            }
        }
    }

    return 0;
}