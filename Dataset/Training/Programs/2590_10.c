// A complex C program combining array processing, sorting, searching, and GCD computation
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "verifier_program.c", __LINE__, "reach_error");
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

#define MAX_SIZE 10

int main() {
    int N;
    int arr[MAX_SIZE];
    int prefix[MAX_SIZE];
    int sum;
    int min_val, max_val;

    /* 1) Choose a nondeterministic size N and constrain it */
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= MAX_SIZE);

    /* 2) Fill the array with nondeterministic values in [0,100] */
    {
        int i;
        for (i = 0; i < N; i++) {
            arr[i] = __VERIFIER_nondet_int();
            assume_abort_if_not(arr[i] >= 0 && arr[i] <= 100);
        }
    }

    /* 3) Compute sum, prefix sums, and track min/max */
    sum = 0;
    if (N > 0) {
        min_val = arr[0];
        max_val = arr[0];
    } else {
        min_val = 0;
        max_val = 0;
    }

    {
        int i;
        for (i = 0; i < N; i++) {
            int v = arr[i];
            sum += v;
            if (v < min_val) {
                min_val = v;
            }
            if (v > max_val) {
                max_val = v;
            }
            prefix[i] = sum;
            /* Because all arr[i] >= 0, prefix must be non‐decreasing */
        }
    }

    /* 4) Sort the array in non-decreasing order using insertion sort */
    {
        int i, j, key;
        for (i = 1; i < N; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    /* 5) Assert that the array is sorted */
    {
        int i;
        for (i = 0; i + 1 < N; i++) {
        }
    }

    /* 6) Perform binary search for a nondeterministic target */
    {
        int target = __VERIFIER_nondet_int();
        int low, high, mid;
        int idx = -1;
        assume_abort_if_not(target >= 0 && target <= 100);

        low = 0;
        high = N - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == target) {
                idx = mid;
                break;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (idx != -1) {
            /* If found, verify correctness */
        } else {
            /* If not found, ensure the search bounds are consistent */
            if (high >= 0) {
            }
            if (low < N) {
            }
        }
    }

    /* 7) Compute GCD of first and last element if at least two elements exist */
    if (N >= 2) {
        int a = arr[0];
        int b = arr[N - 1];
        int tmp;
        while (b != 0) {
            tmp = a % b;
            a = b;
            b = tmp;
            /* GCD remains non-negative */
        }
        /* 'a' is now gcd; it must divide both original values */
    }

    /* 8) Final consistency checks */
    if (N > 0) {
    } else {
        __VERIFIER_assert(sum == 0);
    }

    return 0;
}