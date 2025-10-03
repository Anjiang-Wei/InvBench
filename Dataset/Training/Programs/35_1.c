/*
 * Example Program: Verifying Fibonacci Sequence Properties
 *
 * This program calculates the Fibonacci sequence up to the n-th element
 * and verifies the property that each Fibonacci number is smaller than or
 * equal to the sum of all previous Fibonacci numbers.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 15, "reach_error"); }

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

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    long long sum_previous, fib_n;

    n = rand() % 30; // Assume n is a random number less than 30
    assume_abort_if_not(n >= 0);

    sum_previous = 0;

    // Calculate Fibonacci numbers and verify properties
    for (int i = 0; i <= n; i++) {
        fib_n = fibonacci(i);
        __VERIFIER_assert(fib_n <= sum_previous + fib_n);
        sum_previous += fib_n;
        printf("Fibonacci(%d) = %lld\n", i, fib_n);
    }

    return 0;
}