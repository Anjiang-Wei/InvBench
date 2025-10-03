#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

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
    int upper_limit = __VERIFIER_nondet_int();

    // Assume a positive upper limit for the range
    if (upper_limit <= 1) {
        return 0;
    }

    int prime_counter = 0;

    for (int num = 2; num <= upper_limit; num++) {
        if (is_prime(num)) {
            prime_counter++;
        }
    }

    // Calculate an artificial invariant related to the number of primes
    // This asserts that a basic condition holds for a valid range
    __VERIFIER_assert(prime_counter >= 0);

    // Check some properties we expect (e.g., number of primes is less than upper limit)

    return 0;
}