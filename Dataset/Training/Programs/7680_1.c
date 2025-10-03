#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 1000);

    int *prime_flags = (int *)malloc(sizeof(int) * (N + 1));
    if (prime_flags == NULL) {
        return 1;
    }

    // Initialize the array
    for (int i = 0; i <= N; i++) {
        prime_flags[i] = 1; // Assume all numbers are prime initially
    }
    prime_flags[0] = prime_flags[1] = 0; // 0 and 1 are not prime numbers

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= N; i++) {
        if (prime_flags[i]) { // If i is a prime
            for (int j = i * i; j <= N; j += i) {
                prime_flags[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }

    int prime_count = 0;
    for (int i = 0; i <= N; i++) {
        if (prime_flags[i]) {
            prime_count++;
        }
    }

    // Verify the number of primes found
    __VERIFIER_assert(prime_count >= 0 && prime_count <= N);

    printf("Number of prime numbers up to %d is: %d\n", N, prime_count);

    free(prime_flags);
    return 0;
}