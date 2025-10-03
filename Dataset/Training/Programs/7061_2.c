/*
 * A program that calculates Fibonacci numbers to demonstrate a verification example.
 * The program will compute the Nth Fibonacci number using a loop and verify the result
 * according to the properties of Fibonacci numbers.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Reached error\n");
    abort();
}
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int N = __VERIFIER_nondet_int();

    // Assume N is a positive integer
    assume_abort_if_not(N >= 0);

    int a = 0, b = 1, temp;
    int i = 0;

    // Calculate Nth Fibonacci number
    while (i < N) {
        temp = a;
        a = b;
        b = temp + b;
        i++;
    }

    // Verify properties of the Fibonacci sequence
    // Fibonacci sequence must be non-decreasing
    if (N > 1) {
        __VERIFIER_assert(b > a);
    }

    printf("The %dth Fibonacci number is %d\n", N, a);
    return 0;
}