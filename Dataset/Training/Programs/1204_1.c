#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int x = __VERIFIER_nondet_int();
    if (x < 1) {
        return 0; // Early exit if x is less than 1
    }

    int primes_found = 0;

    // Find the number of prime numbers less than or equal to x
    for (int i = 1; i <= x; i++) {
        if (is_prime(i)) {
            primes_found++;
        }
    }

    // Verify that the number of primes found is always less than or equal to x
    __VERIFIER_assert(primes_found <= x);

    return 0;
}