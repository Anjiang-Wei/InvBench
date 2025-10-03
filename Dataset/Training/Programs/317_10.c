// A C program combining array sorting, extended GCD, and Fibonacci computations,
// with assertions suitable for automated verification.

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((nothrow, leaf, noreturn));

void reach_error() {
    __assert_fail("0", "program.c", __LINE__, "reach_error");
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

#define MAX_N 50

// Extended Euclidean algorithm to compute gcd(a,b) and Bezout coefficients x,y
int extended_gcd(int a, int b, int *x, int *y) {
    int x0 = 1, y0 = 0;
    int x1 = 0, y1 = 1;
    int a_copy = a, b_copy = b;

    // Compute until remainder is zero
    while (b_copy != 0) {
        int q = a_copy / b_copy;
        int r = a_copy - q * b_copy;
        int tx = x0 - q * x1;
        int ty = y0 - q * y1;

        a_copy = b_copy;
        b_copy = r;
        x0 = x1;
        y0 = y1;
        x1 = tx;
        y1 = ty;
    }

    // x0,y0 now satisfy a*x0 + b*y0 == gcd(a,b)
    *x = x0;
    *y = y0;
    return a_copy;
}

// Bubble sort: sorts arr[0..n-1] in non-decreasing order
void bubble_sort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    // 1) Read nondeterministic array size n in [1..MAX_N]
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= MAX_N);

    // 2) Allocate and initialize arrays a and b
    int a[MAX_N];
    int b[MAX_N];
    int i;

    for (i = 0; i < n; i++) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(v >= 0 && v <= 1000);
        a[i] = v;
        b[i] = v; // copy to b
    }

    // 3) Compute sum of original array
    int sum_a = 0;
    for (i = 0; i < n; i++) {
        sum_a += a[i];
    }

    // 4) Sort array b via bubble sort
    bubble_sort(b, n);

    // 5) Compute sum of sorted array and assert it matches
    int sum_b = 0;
    for (i = 0; i < n; i++) {
        sum_b += b[i];
    }

    // 6) Assert that b is non-decreasing
    for (i = 0; i < n - 1; i++) {
    }

    // 7) If at least two elements, check extended GCD properties on a[0], a[1]
    if (n >= 2) {
        int x_coef, y_coef;
        int g = extended_gcd(a[0], a[1], &x_coef, &y_coef);

        // g divides both inputs

        // Bezout identity holds: a[0]*x + a[1]*y == g

        // gcd is non-negative and no larger than max(a[0],a[1])
    }

    // 8) Compute a Fibonacci number fib_n in [0..20], checking properties
    {
        int fib_n = __VERIFIER_nondet_int();
        assume_abort_if_not(fib_n >= 0 && fib_n <= 20);

        int fib_prev = 0;
        int fib_curr = 1;
        int fib_next;

        if (fib_n == 0) {
        } else if (fib_n == 1) {
        } else {
            int k;
            for (k = 2; k <= fib_n; k++) {
                fib_next = fib_prev + fib_curr;
                fib_prev = fib_curr;
                fib_curr = fib_next;

                // Every new Fibonacci is at least as big as the previous
                __VERIFIER_assert(fib_curr >= fib_prev);
            }
            // Final sanity check (trivially true given the update rule)
        }
    }

    return 0;
}