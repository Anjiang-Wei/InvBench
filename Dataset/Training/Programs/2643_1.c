// This C program includes meaningful computational logic with verifiable properties
// SPDX-FileCopyrightText: 2023 Your Name
// SPDX-License-Identifier: Apache-2.0

#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
    if (n <= 3) {
        return 1; // 2 and 3 are prime numbers
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int x = __VERIFIER_nondet_int();
    if (x <= 0) {
        return 0; // Constraint x to be positive to have meaningful computation
    }

    __VERIFIER_assert(x > 0); // Ensure that x is a positive integer

    int sum_of_primes = 0;
    int found_primes = 0;

    for (int i = 2; i <= x; i++) {
        if (is_prime(i)) {
            sum_of_primes += i;
            found_primes++;
        }
    }

    printf("Total prime numbers up to %d is: %d\n", x, found_primes);

    return 0;
}