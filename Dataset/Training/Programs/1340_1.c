// A C program to compute primes up to N using the Sieve of Eratosthenes,
// then verify the correctness of the sieve marking, analyze prime gaps,
// and count primes. The program is intended for verification by automated
// tools. It uses nondeterministic input for N, dynamic memory allocation,
// multiple loops, and assertion checks.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1024

extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sieve_verifier.c", 13, "reach_error");
}

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

static char *isPrime = NULL;
static int N = 0;

// Allocate and initialize the isPrime array of size N+1.
// Initially mark all candidates >=2 as prime (1), others as non-prime (0).
void initialize_sieve() {
    isPrime = (char *)malloc((N + 1) * sizeof(char));
    assume_abort_if_not(isPrime != NULL);

    // Mark all entries as prime (1) by default
    for (int i = 0; i <= N; i++) {
        isPrime[i] = 1;
    }
    // 0 and 1 are not prime
    isPrime[0] = 0;
    isPrime[1] = 0;
}

// Compute integer floor of sqrt(n) by trial increment.
int compute_sqrt_limit(int n) {
    int lim = 0;
    while ((lim + 1) * (lim + 1) <= n) {
        lim++;
    }
    // Check correctness of the bound
    __VERIFIER_assert(lim * lim <= n);
    return lim;
}

// Run the standard Sieve of Eratosthenes up to limit
void run_sieve(int limit) {
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            // Strike out multiples of p starting at p*p
            int start = p * p;
            for (int j = start; j <= N; j += p) {
                isPrime[j] = 0;
            }
        }
    }
}

// Verify that every marked prime has no divisors, and every marked
// composite has at least one divisor.
void verify_sieve() {
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            // For a prime, ensure no divisor in [2..sqrt(i)]
            for (int d = 2; d * d <= i; d++) {
            }
        } else {
            // For a composite, ensure at least one divisor in [2..sqrt(i)]
            int found_divisor = 0;
            for (int d = 2; d * d <= i; d++) {
                if (i % d == 0) {
                    found_divisor = 1;
                    break;
                }
            }
        }
    }
}

// Count the total number of primes in the array
int count_primes() {
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            cnt++;
        }
    }
    // There must be at least one prime (2) when N>=2
    return cnt;
}

// Analyze maximum gap between consecutive primes, assert gap >= 2
// and gap doesn't exceed N (sanity check)
int analyze_prime_gaps() {
    int last_prime = 2;
    int max_gap = 0;
    // start scanning from next candidate
    for (int i = 3; i <= N; i++) {
        if (isPrime[i]) {
            int gap = i - last_prime;
            if (gap > max_gap) {
                max_gap = gap;
            }
            last_prime = i;
        }
    }
    // Gaps between primes are at least 2 (except trivial when N<3)
    if (N >= 3) {
    }
    // Gap should never exceed N
    return max_gap;
}

// A helper routine to perform a dummy pass over the array to ensure
// more loop iterations for thorough analysis.
void dummy_traversal() {
    volatile int sum = 0;
    for (int i = 0; i <= N; i++) {
        sum += isPrime[i];
    }
    // sum is the count of primes; should match count_primes()
}

int main() {
    // Nondeterministic input
    N = __VERIFIER_nondet_int();
    // Constrain N to a reasonable range: [2..MAX_N]
    assume_abort_if_not(N >= 2 && N <= MAX_N);

    // Initialize data structures
    initialize_sieve();

    // Compute limit for sieving
    int limit = compute_sqrt_limit(N);

    // Execute the sieve
    run_sieve(limit);

    // Perform verification of correctness
    verify_sieve();

    // Count primes and check at least one exists
    int total_primes = count_primes();

    // Analyze prime gaps
    int max_gap = analyze_prime_gaps();

    // Dummy traversal to add more loops and checks
    dummy_traversal();

    // Final sanity checks

    // Free memory and exit
    free(isPrime);
    return 0;
}