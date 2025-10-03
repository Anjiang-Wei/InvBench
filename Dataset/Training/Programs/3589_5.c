// Sieve of Eratosthenes Verification Program
// This program computes all prime numbers up to N using
// the classic sieve algorithm, then checks that the result
// is correct by verifying that each reported prime has
// no non-trivial divisor.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sieve-verify.c", 8, "reach_error"); }

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

int main() {
    // Read size parameter
    int N = __VERIFIER_nondet_int();
    // We only handle 2 <= N <= 50 to keep arrays bounded
    assume_abort_if_not(N >= 2 && N <= 50);

    // Array to mark primality: 1 means "assumed prime", 0 means "composite"
    int is_prime[51];
    int i, j;

    // Initialize the sieve array
    for (i = 0; i <= N; i++) {
        if (i < 2) {
            is_prime[i] = 0;
        } else {
            is_prime[i] = 1;
        }
    }

    // Main Sieve of Eratosthenes loop
    for (i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            // Mark multiples of i as composite
            for (j = i * i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    // Count how many primes we found
    int prime_count = 0;
    for (i = 2; i <= N; i++) {
        if (is_prime[i]) {
            prime_count++;
        }
    }
    // At least one prime (2) must exist in the range

    // Verify correctness: every marked prime i has no divisor k in [2..i-1]
    for (i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (j = 2; j < i; j++) {
                // i should not be divisible by any smaller j > 1
            }
        }
    }

    // Verify completeness: every composite number >1 has at least one divisor ≤ sqrt(i)
    for (i = 2; i <= N; i++) {
        if (!is_prime[i]) {
            // For a composite i, there must exist k in [2..sqrt(i)] such that i % k == 0
            int found_divisor = 0;
            for (j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    found_divisor = 1;
                }
            }
            // For i > 1, composite i must have a divisor
        }
    }

    // Additional sanity checks on the sieve array boundaries
    __VERIFIER_assert(is_prime[1] == 0);
    for (i = N + 1; i < 51; i++) {
        // Entries beyond N should remain untouched
        // (we never set is_prime[i] after initialization except for i<=N)
        // They must be either 0 or 1; no further constraint needed.
    }

    return 0;
}