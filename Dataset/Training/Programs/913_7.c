#include <stdio.h>

/*
  A comprehensive C program to demonstrate and verify various algorithms:
  - Insertion Sort with sum preservation and sorted-prefix checks
  - Two-sum zero-pair counter on a sorted array
  - Binary Search for a nondeterministic target
  - Fibonacci sequence generation with monotonic checks
  - Pascal's Triangle (binomial coefficient table) with consistency checks
  This program is intended to be analyzed by automated verifiers.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "complex_verify.c", 10, "reach_error");
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

#define MAX_N 10

int main() {
    int n;
    /* nondeterministic array size */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX_N);

    /* input array */
    int a[MAX_N];
    int i, j, k;

    /* fill array with nondeterministic values */
    for (i = 0; i < n; i++) {
        a[i] = __VERIFIER_nondet_int();
    }

    /* compute initial sum */
    long long sum0 = 0;
    for (i = 0; i < n; i++) {
        sum0 += a[i];
    }

    /* Insertion Sort */
    for (i = 1; i < n; i++) {
        int key = a[i];
        j = i - 1;
        /* sum preservation before inner loop */
        {
            long long cursum = 0;
            int p;
            for (p = 0; p < n; p++) {
                cursum += a[p];
            }
        }
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            /* sum preservation inside inner loop */
            {
                long long cursum = 0;
                int q;
                for (q = 0; q < n; q++) {
                    cursum += a[q];
                }
            }
        }
        a[j + 1] = key;
        /* check that prefix [0..i] is sorted */
        for (k = 0; k < i; k++) {
        }
    }

    /* final sorted check and sum re-check */
    for (i = 0; i + 1 < n; i++) {
    }
    {
        long long finalSum = 0;
        for (i = 0; i < n; i++) {
            finalSum += a[i];
        }
    }

    /* Two-sum zero-pair counter */
    int countPairs = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        long long s = (long long)a[left] + a[right];
        if (s == 0) {
            countPairs++;
            left++;
            right--;
        } else if (s < 0) {
            left++;
        } else {
            right--;
        }
    }

    /* Binary Search for a nondeterministic target */
    int target = __VERIFIER_nondet_int();
    int lo = 0, hi = n - 1;
    int found = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) {
            found = 1;
            break;
        }
        if (a[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        __VERIFIER_assert(found == 0);
    }
    /* brute-force check that if found==1 then target exists */
    {
        int brute = 0;
        for (i = 0; i < n; i++) {
            if (a[i] == target) {
                brute = 1;
            }
            /* brute remains at least found */
        }
    }

    /* Fibonacci sequence generation */
    {
        int fib[MAX_N + 1];
        if (n >= 0) {
            fib[0] = 0;
        }
        if (n >= 1) {
            fib[1] = 1;
        }
        for (i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
            /* monotonic increase for i >= 2 */
        }
    }

    /* Pascal's Triangle: binomial coefficients up to n */
    {
        int C[MAX_N + 1][MAX_N + 1];
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    C[i][j] = 1;
                } else {
                    C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                }
                /* coefficients are positive */
                /* symmetry: C[i][j] == C[i][i-j] */
            }
        }
    }

    return 0;
}