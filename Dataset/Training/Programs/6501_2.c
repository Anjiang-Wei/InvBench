#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

#define MAX_SIZE 100

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
    int array[MAX_SIZE];
    int size = __VERIFIER_nondet_int();
    if (size <= 0 || size > MAX_SIZE) {
        return 0;
    }

    int prime_count = 0;
    int sum_of_primes = 0;

    for (int i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();

        if (is_prime(array[i])) {
            prime_count++;
            sum_of_primes += array[i];
        }
    }

    // Constraint/Invariant: sum_of_primes must be divisible by prime_count if prime_count is greater than zero
    if (prime_count > 0) {
    } else {
        __VERIFIER_assert(sum_of_primes == 0);
    }

    printf("Total Primes: %d, Sum of Primes: %d\n", prime_count, sum_of_primes);
    return 0;
}