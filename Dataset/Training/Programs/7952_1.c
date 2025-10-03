#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "loop_computation.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 1 || N > 100) {
        return 1; // Non-trivial constraint on N
    }

    int count = 0;
    int sum_of_primes = 0;

    for (int i = 2; i <= N; i++) {
        if (is_prime(i)) {
            sum_of_primes += i;
            count++;
        }
    }

    // Checking a condition related to prime number summation
    __VERIFIER_assert(sum_of_primes > N || count < N); // It's expected that sum of primes is more than N if count reaches N (though count will never reach N)

    // Printing for validation (not needed for verification tools, but useful for confirmation)
    printf("Number of Primes: %d\n", count);
    printf("Sum of Primes: %d\n", sum_of_primes);

    return 0;
}