#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int is_prime(int n) {
    if (n <= 1) {
        return 0; // 0 and 1 are not prime
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // divisible by a number other than 1 and itself
        }
    }
    return 1; // prime number
}

int main() {
    int N, prime_count = 0;

    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 10); // Assume N is at least 10 for computational significance

    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    __VERIFIER_assert(prime_count <= N - 1);

    return 0;
}