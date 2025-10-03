#include <assert.h>

extern int __VERIFIER_nondet_int(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/**
 * Checks if a number is prime
 * Returns 1 if the number is prime, 0 otherwise
 */
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

/**
 * Computes the summation of prime numbers within a certain range
 * Validates that the result satisfies certain conditions
 */
int main() {
    int start = __VERIFIER_nondet_int();
    int end = __VERIFIER_nondet_int();

    if (!(start < end && start >= 0)) {
        return 0;
    }

    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            sum += i;
        }
    }

    // Post-condition: For demonstration purposes,
    // assume the sum should be greater than zero when there is an element in the range.
    if (start <= end) {
        __VERIFIER_assert(sum >= 0);
    }

    return 0;
}