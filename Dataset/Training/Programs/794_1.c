#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 7, "reach_error"); }
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

// Function to calculate the Fibonacci sequence up to a limit
void calculate_fibonacci(int *fib, int limit) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < limit; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to check if a number is prime
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
    assume_abort_if_not(N > 0 && N < 50);

    int *fib = malloc(sizeof(int) * N);
    calculate_fibonacci(fib, N);

    int prime_count = 0;
    for (int i = 0; i < N; i++) {
        if (is_prime(fib[i])) {
            prime_count++;
        }
    }

    __VERIFIER_assert(prime_count <= N);

    free(fib);
    return 0;
}