/*
 * Prime Numbers Verification Program
 * This program verifies whether a sequence of numbers are prime or not.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prime_verify.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
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
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 100); // Limit the size to prevent excessive resource usage

    int *numbers = (int *)malloc(sizeof(int) * N);
    if (!numbers) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        numbers[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(numbers[i] >= 0); // Let's consider only non-negative numbers
    }

    int prime_count = 0;
    for (int i = 0; i < N; i++) {
        if (is_prime(numbers[i])) {
            prime_count++;
        }
    }

    __VERIFIER_assert(prime_count <= N);

    free(numbers);
    return 0;
}