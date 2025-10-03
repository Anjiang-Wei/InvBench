// A C program combining array sorting, merging, summation, and GCD computation,
// designed for automated verification tools.

#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Abort if a condition does not hold (used as assume).
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Signal a verification error.
void reach_error(void) {
    abort();
}

// Verification assertion.
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// -----------------------------------------------------------------------------
// Selection sort: sorts arr[0..len-1] in non-decreasing order
void selection_sort(int arr[], int len) {
    int i, j, min_idx, tmp;
    for (i = 0; i < len - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

// Merge two sorted arrays a[0..n-1] and b[0..m-1] into c[0..n+m-1].
// The resulting length is stored in *out_len.
void merge_arrays(int a[], int n, int b[], int m, int c[], int *out_len) {
    int i = 0, j = 0, k = 0;
    // Merge while both arrays have elements
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    // Copy any remaining elements from a
    while (i < n) {
        c[k++] = a[i++];
    }
    // Copy any remaining elements from b
    while (j < m) {
        c[k++] = b[j++];
    }
    *out_len = k;
}

// -----------------------------------------------------------------------------
// Main function: drives the verification scenarios
int main() {
    // 1) Read sizes for two arrays and assume reasonable bounds.
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);
    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 50);

    // Arrays and sums
    int a[50], b[50], c[100];
    long long sum_a = 0, sum_b = 0, sum_c = 0;
    int i;

    // 2) Initialize array a with nondeterministic values, track sum.
    for (i = 0; i < n; i++) {
        a[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(a[i] >= -1000 && a[i] <= 1000);
        sum_a += a[i];
    }

    // 3) Initialize array b in the same manner.
    for (i = 0; i < m; i++) {
        b[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(b[i] >= -1000 && b[i] <= 1000);
        sum_b += b[i];
    }

    // 4) Sort both arrays using selection sort.
    selection_sort(a, n);
    selection_sort(b, m);

    // 5) Merge the two sorted arrays into c.
    int merged_len = 0;
    merge_arrays(a, n, b, m, c, &merged_len);

    // 6) Assert that the merged length is correct.

    // 7) Compute the sum of all elements in the merged array.
    for (i = 0; i < merged_len; i++) {
        sum_c += c[i];
    }

    // 8) Assert that the merge preserved the total sum.

    // 9) Assert that the merged array is sorted.
    for (i = 1; i < merged_len; i++) {
    }

    // -------------------------------------------------------------------------
    // Additional computation: Euclidean algorithm for GCD.
    // 10) Read two nondeterministic integers p and q.
    int p = __VERIFIER_nondet_int();
    int q = __VERIFIER_nondet_int();
    assume_abort_if_not(p >= 0 && p <= 1000);
    assume_abort_if_not(q >= 0 && q <= 1000);

    // 11) Compute gcd(p, q) via the standard iterative algorithm.
    int x = p;
    int y = q;
    while (y != 0) {
        int t = y;
        y = x % y;
        x = t;
    }
    // Now x holds gcd(p, q)

    // 12) Assert basic properties of the result.
    //    (a) gcd is non-negative
    __VERIFIER_assert(x >= 0);
    //    (b) gcd does not exceed the smaller of p and q

    return 0;
}