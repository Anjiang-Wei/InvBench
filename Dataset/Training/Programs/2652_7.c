// Extended Euclidean Algorithm with additional computations and verification

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "extended_euclid_plus.c", __LINE__, "reach_error");
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
    // 1) Read two non-negative inputs a0, b0
    int a0 = __VERIFIER_nondet_int();
    int b0 = __VERIFIER_nondet_int();
    assume_abort_if_not(a0 >= 0);
    assume_abort_if_not(b0 >= 0);

    // 2) Prepare for Extended Euclidean Algorithm
    int a = a0;
    int b = b0;
    int x0 = 1, y0 = 0; // coefficients for 'a'
    int x1 = 0, y1 = 1; // coefficients for 'b'
    int q, r;
    int x2, y2;

    // 3) Main loop: perform the Euclidean steps and track Bézout coefficients
    while (b != 0) {
        // Check that values remain non-negative

        q = a / b;
        r = a % b;

        // Update Bézout coefficients
        x2 = x0 - q * x1;
        y2 = y0 - q * y1;

        // Shift for next iteration
        a = b;
        b = r;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    // 'a' is now gcd(a0, b0); (x0, y0) satisfy a0*x0 + b0*y0 == gcd
    int g = a;

    // 4) Final correctness checks for gcd and Bézout identity
    if (b0 != 0) {
    } else {
    }
    __VERIFIER_assert(a0 * x0 + b0 * y0 == g);

    // 5) Count the divisors of a0
    int div_count = 0;
    int i = 1;
    while (i <= a0) {
        if (a0 % i == 0) {
            div_count++;
        }
        i++;
    }
    // A non-zero natural number has at least one divisor (itself)

    // 6) Sum the divisors of g
    int sum_div = 0;
    for (i = 1; i <= g; i++) {
        if (g % i == 0) {
            sum_div += i;
        }
    }
    // If g > 0, then 1 and g divide it, so sum_div >= g + 1
    if (g > 0) {
    } else {
        // g == 0 only if a0 == b0 == 0, then sum_div == 0
    }

    // 7) Compute LCM(a0, b0) using gcd
    long long lcm = 0;
    if (g != 0) {
        // avoid intermediate overflow
        lcm = ((long long)a0 / g) * b0;
        // LCM of two non-negative numbers is at least the max of them
    }

// 8) Bubble sort a small nondeterministic array and verify it is sorted
#define MAXN 5
    int arr[MAXN];
    // Initialize with nondet values in [0,99]
    for (i = 0; i < MAXN; i++) {
        int v = __VERIFIER_nondet_int();
        arr[i] = v % 100;
        assume_abort_if_not(arr[i] >= 0);
        assume_abort_if_not(arr[i] < 100);
    }

    // Bubble sort
    int swapped;
    do {
        swapped = 0;
        for (i = 0; i + 1 < MAXN; i++) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped);

    // Verify sorted order
    for (i = 0; i + 1 < MAXN; i++) {
    }

    return 0;
}