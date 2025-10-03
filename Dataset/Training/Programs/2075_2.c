extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int();

#define N 5

int main() {
    int a[N];
    int i;

    /* Fill the array with nondeterministic integers */
    for (i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int();
    }

    /* If any entry is negative, exit early (we only reason about non-negative arrays) */
    for (i = 0; i < N; i++) {
        if (a[i] < 0) {
            return 0;
        }
    }

    /* Compute sum and maximum */
    long long sum = 0;
    int max = a[0];
    for (i = 0; i < N; i++) {
        int v = a[i];
        sum += v;
        if (v > max) {
            max = v;
        }
    }

    /*
     * For a non-negative array of length N:
     *   max <= sum            (sum covers at least the largest element)
     *   sum <= max * N        (all N elements are ≤ max)
     */
    __VERIFIER_assert((long long)max * N >= sum);

    return 0;
}