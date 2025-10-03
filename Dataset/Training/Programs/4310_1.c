#include <assert.h>
#include <stdlib.h>
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int M = __VERIFIER_nondet_int();
    if (M <= 0) {
        return 1;
    }
    assume_abort_if_not(M < 2147483647 / sizeof(int));

    int *primeFlags = malloc(sizeof(int) * (M + 1));
    for (int i = 0; i <= M; i++) {
        primeFlags[i] = 1; // Assume all numbers are prime initially
    }
    primeFlags[0] = 0; // 0 is not prime
    primeFlags[1] = 0; // 1 is not prime

    for (int p = 2; p * p <= M; p++) {
        if (primeFlags[p]) {
            for (int j = p * p; j <= M; j += p) {
                primeFlags[j] = 0; // Mark all multiples of p as non-prime
            }
        }
    }

    int numPrimes = 0;
    for (int i = 0; i <= M; i++) {
        if (primeFlags[i]) {
            numPrimes++; // Count number of primes found
        }
    }

    __VERIFIER_assert(numPrimes <= M);
    free(primeFlags);
    return 0;
}