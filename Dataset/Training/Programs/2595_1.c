#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 1000); // ensuring n is within a reasonable range

    int primes_count = 0;
    int non_primes_count = 0;

    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            primes_count++;
        } else {
            non_primes_count++;
        }
    }

    // Verifying the sum of primes_count and non_primes_count
    // should be exactly equal to n - 1 (since we start from 2)
    __VERIFIER_assert(primes_count + non_primes_count == n - 1);

    // Print statement to confirm successful execution (not typical for verification, but useful for debugging)
    printf("Number of primes between 2 and %d: %d\n", n, primes_count);
    printf("Number of non-primes between 2 and %d: %d\n", n, non_primes_count);

    return 0;
}