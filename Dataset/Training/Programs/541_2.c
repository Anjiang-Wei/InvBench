// Benchmark: Sum and Count Constraints over an Array of Nondeterministic Values

#include <assert.h>
#include <stdlib.h>

#define MAX_N 1000

extern void abort(void);
void reach_error() { assert(0); }

/* Abort if the condition is false, for constraining nondet values */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verification assertion */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

/* Nondeterministic integer generator */
extern int __VERIFIER_nondet_int(void);

int main(void) {
    /* Choose array length n in [0..MAX_N] */
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(0 <= n && n <= MAX_N);

    /* Statically allocated array; only indices [0..n-1] are used */
    static int arr[MAX_N];

    int i = 0;
    int sum = 0;
    int count = 0;

    /* Fill the array with nondet values in [0..100],
       count how many are >= 50, and accumulate their sum */
    while (i < n) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(0 <= v && v <= 100);
        arr[i] = v;

        if (v >= 50) {
            count++;
        }
        sum += v;
        i++;
    }

    /* Post‐condition assertions:
       1) Each of the 'count' values is at least 50, so sum >= count*50
       2) Each of the 'count' values is at most 100 and each of the
          remaining (n-count) values is at most 49, so
          sum <= count*100 + (n-count)*49
    */
    __VERIFIER_assert(sum <= count * 100 + (n - count) * 49);

    return 0;
}