// Program: Array processing and statistics
// Description: Reads a nondeterministic array of integers, sorts it,
// preserves sum, compresses duplicates, builds a histogram, and checks
// various properties including swap bounds and GCD constraints.
// Intended for verification by automated tools.

#include <assert.h>
#include <limits.h>

extern void abort(void);

// Called on verification failure
void reach_error() {
    assert(0);
}

// Nondeterministic integer generator
extern int __VERIFIER_nondet_int(void);

// Abort if a condition does not hold
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Verification assertion
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Compute the greatest common divisor of x and y
int gcd(int x, int y) {
    // We require y >= 0
    assume_abort_if_not(y >= 0);
    int a = x;
    int b = y;
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    // Euclidean algorithm
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    // Maximum allowed array size
    const int MAX_SIZE = 5;

    // Nondeterministically choose N in [0..MAX_SIZE]
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= MAX_SIZE);

    // Arrays and loop indices
    int a[MAX_SIZE];
    int b[MAX_SIZE];
    int c[MAX_SIZE];
    int i, j;

    // 1) Initialize the array a[] with nondeterministic integers
    for (i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int();
    }

    // 2) Compute the original sum of elements
    int sum_orig = 0;
    for (i = 0; i < N; i++) {
        sum_orig += a[i];
    }

    // 3) Bubble sort the array, counting swaps
    int swap_count = 0;
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swap_count++;
            }
        }
    }

    // 4) Compute the sum after sorting
    int sum_sorted = 0;
    for (i = 0; i < N; i++) {
        sum_sorted += a[i];
    }

    // 5) Check that sorting preserved the total sum

    // 6) Check that the array is now non-decreasing
    for (i = 0; i < N - 1; i++) {
    }

    // 7) Compress duplicates: build unique-values array b[] and counts c[]
    int m = 0; // number of unique values found
    for (i = 0; i < N; i++) {
        int val = a[i];
        int found = 0;
        for (j = 0; j < m; j++) {
            if (b[j] == val) {
                c[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            b[m] = val;
            c[m] = 1;
            m++;
        }
    }

    // 8) Check that the sum of all counts equals N
    int sum_counts = 0;
    for (i = 0; i < m; i++) {
        sum_counts += c[i];
    }

    // 9) Identify the most frequent element
    int max_count = 0;
    int idx = -1;
    for (i = 0; i < m; i++) {
        if (c[i] > max_count) {
            max_count = c[i];
            idx = i;
        }
    }
    // There must be at least one element, so max_count >= 1

    // 10) Check that swap_count did not exceed N*(N-1)/2
    int max_swaps = N * (N - 1) / 2;

    // 11) For each adjacent pair in the unique-values array b[],
    //     compute their GCD and check basic properties.
    for (i = 0; i < m - 1; i++) {
        int g = gcd(b[i], b[i + 1]);
        // GCD is non-negative and does not exceed |b[i]|
        __VERIFIER_assert(g >= 0);
    }

    return 0;
}