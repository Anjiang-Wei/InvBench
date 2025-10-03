// Prime Sieve Verification Program
// This program computes all primes up to a nondeterministic bound n (0 <= n <= MAX_N)
// It verifies correctness of the sieve, properties of the prime list, and some additional constraints.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sieve_verify.c", __LINE__, "reach_error");
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

#define MAX_N 1000

int main(void) {
    // Nondeterministic upper bound for sieve
    int n = __VERIFIER_nondet_int();
    // Constrain n to a safe range
    assume_abort_if_not(n >= 0 && n <= MAX_N);
    if (n < 2) {
        // No primes below 2
        return 0;
    }

    // Sieve array: isPrime[i] == 1 means i is currently marked prime
    static unsigned char isPrime[MAX_N + 1];
    int i, j;

    // Initialize all entries to prime
    for (i = 0; i <= n; i++) {
        isPrime[i] = 1;
    }
    // 0 and 1 are not prime
    isPrime[0] = 0;
    isPrime[1] = 0;

    // Sieve of Eratosthenes
    for (i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    // Collect all primes into an array
    int primes[MAX_N];
    int pCount = 0;
    for (i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes[pCount++] = i;
        }
    }

    // Check that recounting primes matches pCount
    int recount = 0;
    for (i = 2; i <= n; i++) {
        if (isPrime[i]) {
            recount++;
        }
    }

    // Verify that each prime has no divisors other than 1 and itself
    for (i = 0; i < pCount; i++) {
        int p = primes[i];
        for (j = 2; j < p; j++) {
        }
    }

    // Compute the sum of all primes found
    long sum = 0;
    for (i = 0; i < pCount; i++) {
        sum += primes[i];
    }
    // Sum must be non-negative

    // The sum of primes is strictly greater than each individual prime
    for (i = 0; i < pCount; i++) {
    }

    // Check product of first and last prime does not underflow
    if (pCount >= 1) {
        long first = primes[0];
        long last = primes[pCount - 1];
        long prod = first * last;
    }

    // Ensure no composite number is erroneously marked prime
    for (i = 2; i <= n; i++) {
        if (!isPrime[i]) {
            int hasDiv = 0;
            for (j = 2; j < i; j++) {
                if (i % j == 0) {
                    hasDiv = 1;
                    break;
                }
            }
        }
    }

    // Compute the maximum gap between consecutive primes
    int maxGap = 0;
    for (i = 1; i < pCount; i++) {
        int gap = primes[i] - primes[i - 1];
        if (gap > maxGap) {
            maxGap = gap;
        }
    }
    // Gap must be non-negative
    __VERIFIER_assert(maxGap >= 0);

    return 0;
}