#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prime-counter.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int is_prime(int num) {
    if (num <= 1) {
        return 0; // Not prime
    }
    if (num <= 3) {
        return 1; // 2 and 3 are prime
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
    int max_num = __VERIFIER_nondet_int();
    assume_abort_if_not(max_num >= 0); // Max number to check must be non-negative

    int prime_count = 0;
    int i = 1;

    while (i <= max_num) {
        if (is_prime(i)) {
            prime_count++;
        }
        i++;
    }

    __VERIFIER_assert(prime_count >= 0);
    printf("Number of primes up to %d is: %d\n", max_num, prime_count);

    return 0;
}