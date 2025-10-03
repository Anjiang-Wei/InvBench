#include <assert.h>
#include <stdio.h>

// Function to indicate a reaching error, to be used in verification.
void reach_error() { assert(0); }

// Function for deterministic assertion; used as part of the verification.
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate non-deterministic int generation for verification.
extern int __VERIFIER_nondet_int(void);

// A prime sum program: Checks the sum of the prime numbers within a given range.
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = __VERIFIER_nondet_int(); // Upper bound for the calculation
    // Boundary check to make sure n is within reasonable range, e.g., [0, 100]
    if (n < 0 || n > 100) {
        return 0;
    }

    int sum_primes = 0;
    int num = 1; // Start checking from number 1

    // Loop through numbers up to n to find and sum primes
    while (num <= n) {
        if (is_prime(num)) {
            sum_primes += num;
        }
        num++;
    }

    // Verification: Ensure the sum of primes is non-negative (always true)
    __VERIFIER_assert(sum_primes >= 0);

    printf("Sum of primes up to %d is: %d\n", n, sum_primes);

    return 0;
}