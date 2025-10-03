#include <stdio.h>
#include <stdlib.h>

// Assertion and verification helpers
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "lcg.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Linear Congruential Generator parameters
#define MODULUS 2147483648 // 2^31
#define MULTIPLIER 1103515245
#define INCREMENT 12345

// Function to generate a pseudo-random number using LCG
long long lcg(long long seed) {
    return (MULTIPLIER * seed + INCREMENT) % MODULUS;
}

int main() {
    long long seed;
    long long next;
    int iterations, i;

    // Get seed and iterations from a non-deterministic source
    seed = __VERIFIER_nondet_int();
    assume_abort_if_not(seed >= 0 && seed < MODULUS);

    iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(iterations > 0 && iterations <= 100);

    next = seed;

    // Run LCG for a number of iterations
    for (i = 0; i < iterations; i++) {
        long long prev = next;
        next = lcg(next);

        // Assert the LCG invariants
        __VERIFIER_assert(next >= 0 && next < MODULUS);
    }

    // Terminate program
    return 0;
}