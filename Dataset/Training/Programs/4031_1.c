#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
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

// Function prototypes
int is_prime(int n);
long long compute_factorial(int n);

int main() {
    int N = __VERIFIER_nondet_int();

    // Constraint to ensure N is between 1 and 12
    if (N < 1 || N > 12) {
        return 1;
    }

    assume_abort_if_not(N >= 1 && N <= 12);

    // Initialize an array
    int *array = (int *)malloc(sizeof(int) * N);
    if (array == NULL) {
        return 1; // Memory allocation check
    }

    // Populate the array with non-deterministic values
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 1);
    }

    long long factorial_sum = 0; // Sum of factorials of prime numbers

    // Loop through the array and compute factorial of prime numbers
    for (int i = 0; i < N; i++) {
        if (is_prime(array[i])) {
            factorial_sum += compute_factorial(array[i]);
        }
    }

    // Verify the property
    __VERIFIER_assert(factorial_sum >= 0);

    free(array); // Free allocated memory
    return 0;
}

// Function to check if a number is prime
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

// Function to compute factorial of a number
long long compute_factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}