#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

// This function checks if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 1 && N < 1000); // Constraint: N should be between 2 and 999

    int *numbers = malloc(sizeof(int) * N);
    assume_abort_if_not(numbers != NULL); // Ensure memory allocation was successful

    int prime_count = 0;

    for (int i = 0; i < N; i++) {
        numbers[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(numbers[i] >= 0 && numbers[i] <= 1000); // Constraint: Numbers should be between 0 and 1000
    }

    for (int i = 0; i < N; i++) {
        if (is_prime(numbers[i])) {
            prime_count++;
        }
    }

    // The assertion to be verified
    __VERIFIER_assert(prime_count <= N);

    free(numbers);
    return 0;
}