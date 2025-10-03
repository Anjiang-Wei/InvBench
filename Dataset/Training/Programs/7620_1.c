#include <stdio.h>
#include <stdlib.h>

// Function to reach the error state
void reach_error() {
    printf("ERROR\n");
    exit(1);
}

// Assertion function, calls reach_error if condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

// Nondeterministic integer generation (simulated here for testing)
int __VERIFIER_nondet_int(void) {
    return rand() % 20; // Return a random integer between 0 and 19
}

// Hypothesize function to check if a number is prime (for this demo, not full prime logic)
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int counter = 0;
int main() {
    int n = __VERIFIER_nondet_int();
    int prime_count = 0;
    int i = 2; // Start checking from the first prime number

    // At most 50 iterations allowed to prevent infinite execution in a verification context
    while (counter++ < 50) {
        if (i > n) {
            break;
        }

        if (is_prime(i)) {
            prime_count++;
        }

        i++; // Check the next number
    }

    // The invariants are that the prime_count should be less than or equal to n
    // It means there can't be more prime numbers than the value of n we started with
    __VERIFIER_assert(prime_count <= n);

    printf("Number of primes less than or equal to %d is %d\n", n, prime_count);
    return 0;
}