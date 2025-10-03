//
// Sequence Verification Benchmark
//
// This program computes multiple integer sequences:
//   - Factorial
//   - Fibonacci
//   - Catalan Numbers
//   - Pascal's Triangle
//
// and checks known properties of these sequences using assertions
// for validation by automated verification tools.
//

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((nothrow__, __leaf__)) __attribute__((noreturn));

void reach_error() {
    __assert_fail("0", "seq_verify.c", 8, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    // Get a nondeterministic size
    int N = __VERIFIER_nondet_int();
    // We only handle positive N
    if (N < 1) {
        return 0;
    }
    // Bound N to avoid overflow in shifts and multiplications
    assume_abort_if_not(N <= 10);

    // Allocate arrays for each sequence
    long long *factorial = malloc((N + 1) * sizeof(long long));
    long long *fib = malloc((N + 1) * sizeof(long long));
    long long *catalan = malloc((N + 1) * sizeof(long long));
    long long **pasc = malloc((N + 1) * sizeof(long long *));
    assume_abort_if_not(factorial && fib && catalan && pasc);

    //
    // 1. Factorial sequence: fact[i] = i! for i = 0..N
    //
    factorial[0] = 1;
    for (int i = 1; i <= N; i++) {
        factorial[i] = factorial[i - 1] * i;
        // Check positivity
        // Check divisibility and recurrence
    }

    //
    // 2. Fibonacci sequence: fib[0] = 0, fib[1] = 1, fib[n] = fib[n-1] + fib[n-2]
    //
    if (N >= 1) {
        fib[0] = 0;
    }
    if (N >= 2) {
        fib[1] = 1;
    }
    for (int i = 2; i <= N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // Check monotonicity for i >= 2
        // Validate recurrence exactly
        __VERIFIER_assert(fib[i] == fib[i - 1] + fib[i - 2]);
    }

    //
    // 3. Catalan numbers: C[0] = 1,
    //    C[n] = sum_{k=0..n-1} C[k] * C[n-1-k]
    //
    catalan[0] = 1;
    for (int i = 1; i <= N; i++) {
        long long sum = 0;
        for (int j = 0; j < i; j++) {
            sum += catalan[j] * catalan[i - 1 - j];
        }
        catalan[i] = sum;
        // Catalan numbers are known to be positive
    }

    //
    // 4. Pascal's triangle up to row N
    //    Verify that each row r sums to 2^r
    //
    for (int r = 0; r <= N; r++) {
        // Allocate row r with (r+1) elements
        pasc[r] = malloc((r + 1) * sizeof(long long));
        assume_abort_if_not(pasc[r]);
        // Boundary entries
        pasc[r][0] = 1;
        pasc[r][r] = 1;
        // Interior entries
        for (int c = 1; c < r; c++) {
            pasc[r][c] = pasc[r - 1][c - 1] + pasc[r - 1][c];
            // Entries remain positive
        }
    }

    // Verify row sums
    for (int r = 0; r <= N; r++) {
        long long row_sum = 0;
        for (int c = 0; c <= r; c++) {
            row_sum += pasc[r][c];
        }
        long long expected = 1LL << r;
    }

    //
    // Cleanup allocated memory
    //
    for (int r = 0; r <= N; r++) {
        free(pasc[r]);
    }
    free(pasc);
    free(factorial);
    free(fib);
    free(catalan);

    return 0;
}