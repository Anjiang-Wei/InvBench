/*
 * Custom C program for verification purposes
 * This program calculates the factorial of a given number and checks a property
 * related to the sum of numbers from 1 to the given number.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Verification Error\n");
    abort();
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int find_factorial(int x) {
    if (x < 0) {
        return -1; // Negative factorials don't exist
    }
    int fact = 1;
    for (int i = 2; i <= x; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int N = __VERIFIER_nondet_int();

    // Limit N for practical purposes
    assume_abort_if_not(N >= 0 && N <= 12);

    int factorial = find_factorial(N);

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    // We expect sum of 1 to N to be equal to N * (N + 1) / 2
    __VERIFIER_assert(sum == N * (N + 1) / 2);

    // Output result for inspection purpose (not usually needed in verification)
    printf("Factorial of %d is %d\n", N, factorial);
    printf("Sum from 1 to %d is %d\n", N, sum);

    return 0;
}