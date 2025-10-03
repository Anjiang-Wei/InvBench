#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int is_prime(int n) {
    if (n <= 1) {
        return 0; // zero and one are not prime
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 1);
    assume_abort_if_not(N <= 100);

    int prime_count = 0;
    int *arr = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] > 0); // array elements are positive integers
    }

    for (int i = 0; i < N; i++) {
        if (is_prime(arr[i])) {
            prime_count++;
        }
    }

    // Verify that the number of primes found is reasonable given the max size of N
    __VERIFIER_assert(prime_count >= 0 && prime_count <= N);

    free(arr);
    return 0;
}