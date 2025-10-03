#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// New C program based on patterns learned from example programs
int main() {
    int n = __VERIFIER_nondet_int();

    // Assume n is non-negative and within a specific range to ensure meaningful computation
    assume_abort_if_not(n >= 1 && n <= 100);

    int result = 1;
    int i = 2; // Start from 2

    // Simple loop to find the smallest factor of n greater than 1, or determine that it is prime
    while (i <= n / 2) {
        if (n % i == 0) {
            result = i;
            break; // Found a factor
        }
        i++;
    }

    if (result == 1) {
        result = n; // If no factor found, n is prime
    }

    printf("The smallest factor of %d greater than 1 is %d\n", n, result);

    // Verify that result is a divisor of n
    __VERIFIER_assert(n % result == 0);

    return 0;
}