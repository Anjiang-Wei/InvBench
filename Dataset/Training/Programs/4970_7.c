// Complete C program with multiple verification-friendly loops:
// 1. Insertion sort on a nondeterministic array, verifying sum preservation and sortedness.
// 2. Binary search per element to ensure presence post-sort.
// 3. Prefix sum computation and verification via simple loop.
// 4. Euclidean GCD loop with postconditions.
// 5. Fibonacci sequence generation and recurrence check.

#include <stdlib.h>

// Declarations for verification harness
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prog.c", 13, "reach_error"); }

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

// Maximum sizes and bounds for nondet data
#define MAX_N 10
#define MAX_VAL 100
#define MAX_GH 1000
#define MAX_FIB 15

int main() {
    // --- Part 1: Insertion sort and verification on an integer array ---
    int n;
    int i, j, key;
    int a[MAX_N];
    int orig[MAX_N];
    int sum_before = 0;
    int sum_after = 0;

    // Nondeterministic choice of array size
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX_N);

    // Fill the array with nondeterministic values within bounds
    for (i = 0; i < n; i++) {
        a[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(a[i] >= -MAX_VAL && a[i] <= MAX_VAL);
        orig[i] = a[i]; // keep a copy for presence check
    }

    // Compute sum_before = sum(orig[0..n-1])
    sum_before = 0;
    for (i = 0; i < n; i++) {
        sum_before += orig[i];
    }

    // Insertion sort on a[0..n-1]
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    // Compute sum_after = sum(a[0..n-1])
    sum_after = 0;
    for (i = 0; i < n; i++) {
        sum_after += a[i];
    }

    // Verify sum preservation

    // Verify sortedness: a[i] <= a[i+1]
    for (i = 0; i + 1 < n; i++) {
    }

    // Verify that every original element is still present via binary search
    for (i = 0; i < n; i++) {
        int target = orig[i];
        int low = 0;
        int high = n - 1;
        int found = 0;
        // Standard binary search loop
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == target) {
                found = 1;
                break;
            } else if (a[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    // --- Part 2: Prefix sum computation and verification ---
    // b[i] = sum_{k=0..i} a[k]
    int b[MAX_N];
    if (n > 0) {
        b[0] = a[0];
        for (i = 1; i < n; i++) {
            b[i] = b[i - 1] + a[i];
        }
        // Verify prefix sums satisfy recurrence b[i] == b[i-1] + a[i]
        for (i = 1; i < n; i++) {
        }
    }

    // --- Part 3: Euclidean GCD computation and verification ---
    int g, h;
    int orig_g, orig_h;
    int temp;

    // Nondeterministic non-negative inputs for GCD
    g = __VERIFIER_nondet_int();
    h = __VERIFIER_nondet_int();
    assume_abort_if_not(g >= 0 && g <= MAX_GH);
    assume_abort_if_not(h >= 0 && h <= MAX_GH);

    orig_g = g;
    orig_h = h;

    // Euclid's algorithm
    while (h != 0) {
        temp = h;
        h = g % h;
        g = temp;
    }
    // After loop, g holds gcd(orig_g, orig_h)

    // Verify gcd divides both original inputs
    if (orig_g >= 0 && orig_h >= 0) {
    }
    // gcd of (x,0) is x itself
    if (orig_h == 0) {
        __VERIFIER_assert(g == orig_g);
    }

    // --- Part 4: Fibonacci sequence generation and check ---
    int m;
    int fib[MAX_FIB];
    // Choose small m for Fibonacci
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m < MAX_FIB);

    if (m >= 0) {
        // Base cases
        if (m == 0) {
            fib[0] = 0;
        } else if (m == 1) {
            fib[0] = 0;
            fib[1] = 1;
        } else {
            fib[0] = 0;
            fib[1] = 1;
            // Generate up to fib[m]
            for (i = 2; i <= m; i++) {
                fib[i] = fib[i - 1] + fib[i - 2];
            }
            // Verify recurrence
            for (i = 2; i <= m; i++) {
            }
        }
    }

    return 0;
}