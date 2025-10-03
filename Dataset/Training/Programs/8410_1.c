#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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

int is_prime(int number) {
    if (number <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 100); // Assuming n is within a sensible range

    int sum = 0;
    int i = 2;
    int primes_count = 0;

    while (i <= n) {
        if (is_prime(i)) {
            sum += i;
            primes_count++;
        }
        i++;
    }

    // Check if sum after the loop maintains some properties with respect to number of primes
    __VERIFIER_assert(sum > 0);          // Sum of primes should be positive
    __VERIFIER_assert(primes_count > 0); // There should be at least one prime

    printf("Sum of primes up to %d is %d\n", n, sum);
    return 0;
}