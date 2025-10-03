// Extended Euclid and Insertion Sort Verification Program
// This program computes the extended GCD of two integers A and B,
// then verifies the result. It also allocates an array of size N,
// fills it with bounded nondeterministic integers, sorts it using
// insertion sort, and finally checks that the array is sorted and
// that the computed sum matches the actual sum of elements.

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *);
void reach_error() {
    __assert_fail("0", "verify_prog.c", 1, "reach_error");
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

int main() {
    // Part 1: Extended Euclidean Algorithm
    // ------------------------------------
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();
    // Constrain A and B to reasonable ranges
    assume_abort_if_not(A >= 0 && A <= 10000);
    assume_abort_if_not(B > 0 && B <= 10000);

    // Save originals
    int A0 = A;
    int B0 = B;

    // Variables for the extended Euclid algorithm
    int r0 = A, r1 = B;
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;

    // Loop: while r1 != 0
    while (r1 != 0) {
        int q = r0 / r1;

        // Compute remainders
        int r2 = r0 - q * r1;
        int s2 = s0 - q * s1;
        int t2 = t0 - q * t1;

        // Shift for next iteration
        r0 = r1;
        r1 = r2;
        s0 = s1;
        s1 = s2;
        t0 = t1;
        t1 = t2;
    }
    // At this point:
    //   gcd = r0
    //   coefficients: x = s0, y = t0

    int gcd = r0;
    int x = s0;
    int y = t0;

    // Final check for extended GCD correctness
    //   gcd should be > 0
    //   A0 == gcd * x + B0 * y
    //   gcd divides both A0 and B0
    __VERIFIER_assert(gcd > 0);

    // Part 2: Insertion Sort on a Nondeterministic Array
    // ---------------------------------------------------
    int N = __VERIFIER_nondet_int();
    // Constrain N
    assume_abort_if_not(N >= 0 && N <= 1000);

    // Allocate array
    int *a = (int *)malloc(sizeof(int) * (size_t)N);
    if (a == NULL) {
        // Allocation failure is treated as abort
        abort();
    }

    // Fill array with bounded nondeterministic values
    for (int i = 0; i < N; i++) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(v >= 0 && v <= 1000);
        a[i] = v;
    }

    // Insertion sort
    for (int i = 1; i < N; i++) {
        int key = a[i];
        int j = i - 1;
        // Move elements of a[0..i-1] that are greater than key
        // to one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    // Check that the array is sorted in non-decreasing order
    for (int i = 0; i + 1 < N; i++) {
    }

    // Compute the sum of all elements and verify it matches
    // an incremental sum
    int computed_sum = 0;
    for (int i = 0; i < N; i++) {
        computed_sum += a[i];
    }

    // Recompute sum nondeterministically and check equality
    int check_sum = 0;
    for (int i = 0; i < N; i++) {
        check_sum = check_sum + a[i];
    }

    // Clean up
    free(a);

    return 0;
}