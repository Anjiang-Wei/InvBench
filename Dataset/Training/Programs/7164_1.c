#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prime_check.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int is_prime_number(int n) {
    if (n < 2) {
        return 0; // numbers less than 2 are not prime
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // if divisible, not prime
        }
    }
    return 1; // if no divisors, prime
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 2) {
        return 0; // quickly return for invalid input values
    }

    int prime_count = 0;
    int max_check = (n > 50) ? 50 : n; // limit arbitrary to 50 for feasible computation

    for (int i = 2; i <= max_check; i++) {
        if (is_prime_number(i)) {
            prime_count++;
        }
    }

    // Let's verify if we counted some known number of primes correctly
    // For smaller n values, can be verified using known number of primes
    int known_primes_up_to_10 = 4; // 2, 3, 5, 7
    if (max_check >= 10) {
        __VERIFIER_assert(prime_count >= known_primes_up_to_10);
    }

    return 0;
}