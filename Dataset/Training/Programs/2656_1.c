// New C Program Example
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to check for prime numbers in an array
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int(); // Get a nondeterministic integer
    if (N < 2) {
        return 1; // Ensure meaningful computations
    }
    assume_abort_if_not(N <= 100);

    int *a = malloc(sizeof(int) * N);
    int i, j, count = 0;

    for (i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int() % 100; // Populate array with numbers < 100
    }

    for (i = 0; i < N; i++) {
        int is_prime = 1;
        if (a[i] < 2) {
            is_prime = 0; // Numbers less than 2 are not prime
        }
        for (j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            count++;
        }
    }

    // Assert that number of primes found is less than or equal to N
    __VERIFIER_assert(count <= N);

    // Frees the allocated memory
    free(a);

    return 0;
}