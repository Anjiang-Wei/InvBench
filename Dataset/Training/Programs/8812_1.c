#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 1 && N <= 100);

    int prime_count = 0;
    int non_prime_count = 0;
    int current = 2;

    while (current <= N) {
        if (is_prime(current)) {
            prime_count++;
        } else {
            non_prime_count++;
        }
        current++;
    }

    // We should have either primes or nonprimes but not negative counts
    __VERIFIER_assert(prime_count + non_prime_count == N - 1);

    printf("Number of primes less than or equal to %d is %d\n", N, prime_count);
    printf("Number of non-prime numbers less than or equal to %d is %d\n", N, non_prime_count);

    return 0;
}