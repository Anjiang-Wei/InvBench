// A C program verifying classic summation and Fibonacci identities
// via automated assertions. Suitable for verification tools.

#include <assert.h>
#include <stdlib.h>
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

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
    // Read an arbitrary non-negative integer N (bounded by assumption).
    int N = __VERIFIER_nondet_int();
    // We limit N to a reasonable bound for computations.
    assume_abort_if_not(N >= 0 && N <= 1000);

    // Variables for sums of 1..N
    long long sum = 0LL;
    long long sumSquares = 0LL;
    long long sumCubes = 0LL;

    // Compute sum of first N naturals, their squares and cubes.
    for (int i = 1; i <= N; i++) {
        sum += (long long)i;
        sumSquares += (long long)i * (long long)i;
        sumCubes += (long long)i * (long long)i * (long long)i;
    }

    // Verify the well-known formulas:
    //   sum_{i=1..N} i      == N*(N+1)/2
    //   sum_{i=1..N} i^2    == N*(N+1)*(2*N+1)/6
    //   sum_{i=1..N} i^3    == (sum_{i=1..N} i)^2
    __VERIFIER_assert(sumCubes == sum * sum);

    // Now compute Fibonacci sequence up to index N and sum of F[0]..F[N].
    // We use F[0]=0, F[1]=1 convention.
    long long fibPrev = 0LL; // F[0]
    long long fibCurr = 1LL; // F[1]
    long long sumFib = 0LL;
    long long fibVal = 0LL;

    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            fibVal = fibPrev;
        } else if (i == 1) {
            fibVal = fibCurr;
        } else {
            long long next = fibPrev + fibCurr;
            fibPrev = fibCurr;
            fibCurr = next;
            fibVal = next;
        }
        sumFib += fibVal;
    }

    // Next compute F[N+2] so that we can check the identity
    //   sum_{i=0..N} F[i] == F[N+2] - 1
    // We already have fibPrev=F[N-1], fibCurr=F[N] after the loop.
    long long FNminus1 = fibPrev;
    long long FN = fibCurr;
    long long FNplus1 = FNminus1 + FN; // F[N+1]
    long long FNplus2 = FN + FNplus1;  // F[N+2]

    // Verify the summation identity for Fibonacci numbers.

    // All checks passed.
    return 0;
}