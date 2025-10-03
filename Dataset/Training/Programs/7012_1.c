#include <assert.h>
#include <stdio.h>

// Function to simulate error reaching, similar to the above examples
void reach_error() { assert(0); }

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to return a random integer (simulating nondeterminism)
int __VERIFIER_nondet_int() {
    return rand() % 10; // Random number between 0 and 9 for simplicity
}

// Function to check if a number is prime
int is_prime(int x) {
    if (x <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int limit = 10; // Sets the boundary up to which we are finding primes
    int prime_count = 0;

    // Loop to count the number of prime numbers up to 'limit'
    for (int i = 0; i <= limit; ++i) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    // Our condition is that the number of primes less than or equal to 'limit'
    // will be less than or equal to 'limit' itself
    __VERIFIER_assert(prime_count <= limit);

    printf("Number of primes up to %d is: %d\n", limit, prime_count);

    return 0;
}