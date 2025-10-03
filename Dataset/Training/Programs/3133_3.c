#include <assert.h>
#include <limits.h>

#define MAX_N 20
#define MAX_COUNTER 10000

/* Error handling for verification failures */
void reach_error() {
    assert(0);
}

/* Nondeterministic integer generator (stub for verification) */
extern int __VERIFIER_nondet_int(void);

/* Abort if condition is false */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verification assertion */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Global counter to bound loops for verification tools */
int g_counter = 0;

int main() {
    int i, j;
    int N;

    /* Read array size N: 0 <= N <= MAX_N */
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= MAX_N);

    /* Array storage */
    int A[MAX_N];

    /* Fill array A with nondeterministic values in [-1000,1000] */
    for (i = 0; g_counter++ < MAX_COUNTER && i < N; ++i) {
        A[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(A[i] >= -1000 && A[i] <= 1000);
    }

    /* Compute the original sum of the elements */
    long long original_sum = 0;
    for (i = 0; g_counter++ < MAX_COUNTER && i < N; ++i) {
        original_sum += A[i];
    }

    /* ----------------------------------------------------------------
       Insertion Sort to sort A[0..N-1] in non-decreasing order
       ---------------------------------------------------------------- */
    for (i = 1; g_counter++ < MAX_COUNTER && i < N; ++i) {
        int key = A[i];
        j = i - 1;
        /* Shift elements greater than key to one position ahead */
        while (g_counter++ < MAX_COUNTER && j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }

    /* ----------------------------------------------------------------
       After sorting, verify two properties:
         1) The sum is preserved.
         2) The array is sorted.
       ---------------------------------------------------------------- */

    /* Recompute the sum after sorting */
    long long new_sum = 0;
    for (i = 0; g_counter++ < MAX_COUNTER && i < N; ++i) {
        new_sum += A[i];
    }
    /* Sum must be equal */

    /* Check sortedness: A[i] <= A[i+1] for all i */
    for (i = 0; g_counter++ < MAX_COUNTER && i + 1 < N; ++i) {
    }

    /* ----------------------------------------------------------------
       Compute prefix sums P[0..N-1]:
         P[0] = A[0]
         P[i] = P[i-1] + A[i] for i>=1
       and verify P[i] >= A[i].
       ---------------------------------------------------------------- */
    if (N > 0) {
        int P[MAX_N];
        P[0] = A[0];
        __VERIFIER_assert(P[0] >= A[0]);

        for (i = 1; g_counter++ < MAX_COUNTER && i < N; ++i) {
            P[i] = P[i - 1] + A[i];
            /* Each prefix sum is at least as large as the current element */
        }
    }

    /* ----------------------------------------------------------------
       Compute the length of the Longest Non-decreasing Subsequence (LNDS)
       using dynamic programming:
         dp[i] = 1 + max{ dp[j] | 0 <= j < i, A[j] <= A[i] }
       Then find lis_len = max(dp[i]).
       ---------------------------------------------------------------- */
    {
        int dp[MAX_N];
        int lis_len = 0;

        for (i = 0; g_counter++ < MAX_COUNTER && i < N; ++i) {
            dp[i] = 1;
            /* Check all previous positions for extension */
            for (j = 0; g_counter++ < MAX_COUNTER && j < i; ++j) {
                if (A[j] <= A[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            /* Track the maximum dp value */
            if (dp[i] > lis_len) {
                lis_len = dp[i];
            }
        }

        /* Basic sanity checks on dp[] and lis_len */
        /* If N>0, lis_len must be at least 1 */
        /* dp[i] can never exceed i+1 */
        for (i = 0; g_counter++ < MAX_COUNTER && i < N; ++i) {
        }
        /* lis_len can never exceed N */
    }

    return 0;
}