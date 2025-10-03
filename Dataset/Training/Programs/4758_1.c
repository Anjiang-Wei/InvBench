#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

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
    int limit = __VERIFIER_nondet_int();
    if (limit < 0 || limit > 50) {
        // Assume a reasonable limit for this program
        limit = 50;
    }

    int sum_of_primes = 0;
    int count = 0;

    for (int i = 2; i < limit; i++) {
        if (is_prime(i)) {
            sum_of_primes += i;
            count++;
        }
    }

    __VERIFIER_assert(sum_of_primes >= 0); // Sum should be non-negative
    __VERIFIER_assert(count <= limit);     // The count should not exceed the limit

    printf("Sum of primes below %d is %d\n", limit, sum_of_primes);
    return 0;
}