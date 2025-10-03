/*
 * Prime Number Check and Counting Program
 * This program calculates the number of prime numbers less than or equal to a given number N.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prime_count.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    if (num <= 3) {
        return 1;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 1000);

    int prime_count = 0;
    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    // Verification assertion: Verify that the count of primes is non-negative
    __VERIFIER_assert(prime_count >= 0);

    printf("Number of prime numbers <= %d: %d\n", N, prime_count);
    return 0;
}