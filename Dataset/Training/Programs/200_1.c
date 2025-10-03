/*
Prime Number Finder
This program finds and counts prime numbers up to a given number N using a basic method.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "primefinder.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int N, count, num;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 2);

    count = 0;
    num = 2;

    while (num <= N) {
        if (is_prime(num)) {
            count++;
        }
        num++;
    }

    // Verification assertion: Number of primes found is non-negative and less than or equal to N
    __VERIFIER_assert(count >= 0 && count <= N);

    // Print the result
    printf("Number of primes up to %d is: %d\n", N, count);
    return 0;
}