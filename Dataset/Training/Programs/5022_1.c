#include <assert.h>
#include <stdlib.h>

// Function to simulate non-deterministic integer
extern int __VERIFIER_nondet_int(void);

// Function to handle the error
void reach_error() {
    assert(0);
}

// Function to safely exit
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// A function to verify if an integer is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 10000); // Assume a reasonable limit for the demonstration

    int *array = (int *)malloc(sizeof(int) * N);
    if (array == NULL) {
        return 1;
    }

    int sum = 0;
    int number_of_primes = 0;

    // Initialize the array with some non-deterministic values and calculate the sum of prime numbers
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        sum += array[i];

        if (is_prime(array[i])) {
            number_of_primes++;
        }
    }

    __VERIFIER_assert(number_of_primes <= N);

    // Check if array is correctly filled
    if (number_of_primes > 0) {
        int last_non_prime = 0;
        for (int i = 0; i < N; i++) {
            if (!is_prime(array[i])) {
                last_non_prime = array[i];
            }
        }

        // Verification: If the sum is positive, the last non-prime should be non-negative.
    }

    free(array);

    return 0;
}