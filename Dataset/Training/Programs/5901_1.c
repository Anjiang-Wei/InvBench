#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

// Helper function to check if a number is a prime
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
    int n, counter = 0;
    long long sum_of_primes = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 10 && n <= 100);

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            sum_of_primes += i;
            counter++;
        }
    }

    __VERIFIER_assert(counter > 0);
    printf("The sum of primes up to %d is %lld.\n", n, sum_of_primes);

    return 0;
}