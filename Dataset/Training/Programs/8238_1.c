#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

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

int main() {
    int x = __VERIFIER_nondet_int();
    int prime_count = 0;

    // Let's assume the nondeterministic number x is reasonably bounded
    if (x < 0 || x > 1000) {
        return 0;
    }

    for (int i = 2; i <= x; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    // Ensure prime_count is non-negative and does not exceed x
    __VERIFIER_assert(prime_count >= 0 && prime_count <= x);

    printf("The number of prime numbers less than or equal to %d is %d\n", x, prime_count);

    return 0;
}