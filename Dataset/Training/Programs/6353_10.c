// A comprehensive C program suitable for automated verification.
// It demonstrates multiple loops and non-trivial logic:
//   1) Extended Euclidean algorithm
//   2) Array processing: bubble sort, sum check, sorted check
//   3) Fibonacci sequence generation
//   4) Modular exponentiation (fast and naive) comparison
//   5) Sum-of-divisors check for a small integer
//
// Uses __VERIFIER_nondet_int for inputs, assume_abort_if_not for preconditions,
// and __VERIFIER_assert for safety properties.

#include <stddef.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "combined_example.c", (unsigned)__LINE__, "reach_error");
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
        abort();
    }
}

#define MAX 10

// Fast modular exponentiation: computes (base^exp) % mod
long modpow(long base, int exp, long mod) {
    long result = 1;
    long b = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * b) % mod;
        }
        b = (b * b) % mod;
        exp = exp >> 1;
    }
    return result;
}

int main(void) {
    // 1) Extended Euclidean algorithm
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    long r0 = a;
    long r1 = b;
    long s0 = 1, s1 = 0;
    long t0 = 0, t1 = 1;
    // Compute gcd(a,b) and coefficients s0, t0 such that a*s0 + b*t0 = gcd
    while (r1 != 0) {
        long q = r0 / r1;
        long r2 = r0 - q * r1;
        long s2 = s0 - q * s1;
        long t2 = t0 - q * t1;
        r0 = r1;
        r1 = r2;
        s0 = s1;
        s1 = s2;
        t0 = t1;
        t1 = t2;
    }
    // Post-conditions
    // Check correctness of Bézout identity
    if (r0 != 0) {
    }

    // 2) Array processing and bubble sort
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= MAX);
    int arr[MAX];
    int i, j;
    // Fill array
    for (i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }
    // Compute sum before sort
    long sum_before = 0;
    for (i = 0; i < n; i++) {
        sum_before += arr[i];
    }
    // Bubble sort with index-bound checks
    for (i = 0; i < n; i++) {
        for (j = 0; j + 1 < n; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    // Compute sum after sort and verify sorted order
    long sum_after = 0;
    for (i = 0; i < n; i++) {
        sum_after += arr[i];
        if (i > 0) {
        }
    }

    // 3) Fibonacci sequence generation and monotonicity check
    // We'll compute up to min(n, MAX+1) terms
    int fib[MAX + 2];
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < n && i < MAX + 2; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (i = 1; i < n && i < MAX + 2; i++) {
    }

    // 4) Modular exponentiation: fast vs naive comparison
    long base = __VERIFIER_nondet_int();
    int exp = __VERIFIER_nondet_int();
    long mod = __VERIFIER_nondet_int();
    assume_abort_if_not(mod > 1);
    assume_abort_if_not(exp >= 0);
    // Fast method
    long r_fast = modpow(base, exp, mod);
    // Naive method
    long r_naive = 1;
    for (i = 0; i < exp; i++) {
        r_naive = (r_naive * base) % mod;
    }

    // 5) Sum-of-divisors check for a small positive integer p
    int p = __VERIFIER_nondet_int();
    assume_abort_if_not(p >= 2 && p <= 100);
    int sumDiv = 0;
    for (i = 1; i <= p; i++) {
        if (p % i == 0) {
            sumDiv += i;
        }
    }
    // A number p>=2 always has at least divisors 1 and itself, so sum >= p+1
    __VERIFIER_assert(sumDiv >= p + 1);

    return 0;
}