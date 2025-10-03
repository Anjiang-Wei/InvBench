#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

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

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// This program calculates the sum of prime numbers in an array
int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 1000); // Assume N is within reasonable bounds

    int *array = (int *)malloc(sizeof(int) * N);
    if (!array) {
        return 1; // Check for allocation failure
    }

    // Initialize the array with some non-deterministic values
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    long long sum_of_primes = 0;

    // Calculate the sum of prime numbers
    for (int i = 0; i < N; i++) {
        if (is_prime(array[i])) {
            sum_of_primes += array[i];
        }
    }

    // Verify that sum_of_primes has a plausible value
    __VERIFIER_assert(sum_of_primes >= 0);

    free(array); // Clean up allocated memory
    return 0;
}