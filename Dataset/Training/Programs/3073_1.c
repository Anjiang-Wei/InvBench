#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prime_counter.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
int __VERIFIER_nondet_int();

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
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
    unsigned int limit = __VERIFIER_nondet_int();
    if (limit > 10000) { // Assume limit is reasonable
        return 0;
    }

    unsigned int prime_count = 0;
    unsigned int i = 2; // Start checking from first prime

    while (i <= limit) {
        if (is_prime(i)) {
            prime_count++;
        }
        i++;
    }

    // Ensure the number of primes counted is not more than limit
    __VERIFIER_assert(prime_count <= limit);

    printf("Number of primes up to %u: %u\n", limit, prime_count);
    return 0;
}