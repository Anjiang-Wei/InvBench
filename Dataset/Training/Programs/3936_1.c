#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "custom_c_program.c", 6, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int __VERIFIER_nondet_int() {
    return rand();
}

static int is_prime(int num) {
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
    int max_size = 1000;
    assume_abort_if_not(n <= max_size);

    int prime_counter = 0;
    int composite_counter = 0;

    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            prime_counter++;
        } else {
            composite_counter++;
        }
    }

    // Check that the number of primes + number of composites equals n
    __VERIFIER_assert(prime_counter + composite_counter == n);

    printf("Primes: %d, Composites: %d\n", prime_counter, composite_counter);

    return 0;
}