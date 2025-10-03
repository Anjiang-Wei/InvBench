#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

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

int main(void) {
    unsigned int count = 0;
    unsigned int limit = 10; // Small limit for demonstration purposes
    unsigned int primes_count = 0;

    while (count < limit) {
        unsigned int number = __VERIFIER_nondet_uint();
        if (is_prime(number)) {
            primes_count++;
        }
        count++;
    }

    __VERIFIER_assert(primes_count <= limit);
    printf("Number of prime numbers found: %u\n", primes_count);

    return 0;
}