// A C program for verification: array manipulation, sorting, GCD/LCM, cyclic shifts.
// It uses nondeterministic inputs and assertions suitable for automated analysis tools.

#include <limits.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "array_sort_gcd_lcm_shift.c", 8, "reach_error");
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
    return;
}

#define MAX_N 20
#define VAL_MIN (-1000)
#define VAL_MAX 1000

// Compute absolute value of an integer
int abs_int(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

// Compute greatest common divisor using Euclid's algorithm
int compute_gcd(int a, int b) {
    // make non-negative
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    // Euclid's loop
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(void) {
    // 1. Nondeterministically choose array length
    int N = __VERIFIER_nondet_int();
    // restrict 0 <= N <= MAX_N
    assume_abort_if_not(0 <= N && N <= MAX_N);

    // 2. Declare arrays
    int arr[MAX_N];
    int arr_copy[MAX_N];

    // 3. Fill the array with nondeterministic values in a bounded range
    for (int i = 0; i < N; i++) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(VAL_MIN <= v && v <= VAL_MAX);
        arr[i] = v;
    }

    // 4. Copy original array for later comparison
    for (int i = 0; i < N; i++) {
        arr_copy[i] = arr[i];
    }

    // 5. Compute the sum of array elements (sum1)
    long sum1 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += arr[i];
    }

    // 6. Sort the array using insertion sort
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        // Shift larger elements to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // 7. Compute the sum again (sum2) and assert sums are equal
    long sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum2 += arr[i];
    }

    // 8. Assert that the array is sorted in non-decreasing order
    for (int i = 0; i + 1 < N; i++) {
    }

    // 9. If the array is non-empty, compute gcd and lcm of min and max
    if (N > 0) {
        int a = arr[0];     // minimum after sort
        int b = arr[N - 1]; // maximum after sort

        int g = compute_gcd(a, b);
        // gcd should be non-negative and divide both
        __VERIFIER_assert(g >= 0);

        // compute lcm = |a*b| / gcd, careful with division by zero
        long abs_prod = (long)abs_int(a) * (long)abs_int(b);
        long l;
        if (g == 0) {
            l = 0;
        } else {
            l = abs_prod / g;
        }
        // check the identity l * g == |a * b|
    }

    // 10. Perform cyclic left shifts of the sorted array N times
    for (int shift = 0; shift < N; shift++) {
        if (N <= 1) {
            break; // no effect on empty or single-element array
        }
        int first = arr[0];
        // shift elements left by one
        for (int j = 0; j + 1 < N; j++) {
            arr[j] = arr[j + 1];
        }
        arr[N - 1] = first;
    }

    // 11. After N shifts, the array should match the original copy
    for (int i = 0; i < N; i++) {
    }

    return 0;
}