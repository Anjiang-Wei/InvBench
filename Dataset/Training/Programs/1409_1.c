// A C program suitable for automated verification:
// It checks the well‐known identity: sum_{i=1..N} i^3 = (sum_{i=1..N} i)^2

#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    // nondeterministic choice of N
    int N = __VERIFIER_nondet_int();
    // restrict N to a reasonable range
    assume_abort_if_not(N >= 0 && N <= 10000);

    long long sum = 0;
    long long sum_cubes = 0;

    // compute sum i and sum of cubes i^3
    for (int i = 1; i <= N; i++) {
        sum += i;
        sum_cubes += (long long)i * i * i;
    }

    // verify the identity: sum_{i=1..N} i^3 == (sum_{i=1..N} i)^2
    __VERIFIER_assert(sum_cubes == sum * sum);

    return 0;
}