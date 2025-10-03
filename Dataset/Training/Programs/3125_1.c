#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 1000);

    int *arr = (int *)malloc(sizeof(int) * N);
    if (!arr) {
        abort(); // handle allocation failure
    }

    int i, j, countPrimes = 0;

    // Initialize the array
    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int() % 100; // Limit numbers to range [0, 99] for simplicity
        if (arr[i] < 2) {
            continue; // 0 and 1 are not prime numbers
        }

        // Assume arr[i] is prime initially
        int isPrime = 1;

        // Check if arr[i] is prime
        for (j = 2; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            countPrimes++;
        }
    }

    // Our property: Number of primes found should be less than or equal to N
    __VERIFIER_assert(countPrimes <= N);

    free(arr);
    return 0;
}