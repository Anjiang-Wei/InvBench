#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to determine if a number is prime
int is_prime(unsigned int n) {
    if (n < 2) {
        return 0;
    }
    for (unsigned int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Main program
int main() {
    unsigned int x, n;
    unsigned int prime_count = 0;

    x = __VERIFIER_nondet_uint();
    assume_abort_if_not(x >= 2 && x <= 100);

    n = 0;
    while (n < x) {
        if (is_prime(n)) {
            prime_count++;
        }
        n++;
    }

    __VERIFIER_assert(prime_count >= 0 && prime_count <= x);

    printf("Number of primes less than %u: %u\n", x, prime_count);
    return 0;
}