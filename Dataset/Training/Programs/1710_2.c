/*
 * Program to compute Fibonacci numbers using iterative method
 * while asserting checks on the calculated Fibonacci property
 */

#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci.c", 6, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int i;
    unsigned long long fib_curr = 0, fib_prev = 1, fib_next;
    unsigned long long sum = 0;

    // Set basic assertions on first two Fibonacci numbers
    __VERIFIER_assert(fib_prev == 1);

    for (i = 0; i < n; i++) {
        // Compute the next Fibonacci number
        fib_next = fib_curr + fib_prev;
        sum += fib_curr;

        // Update previous two Fibonacci numbers
        fib_prev = fib_curr;
        fib_curr = fib_next;

        // Assert property that consecutive sum is equal to next Fibonacci number
    }

    // Print the resulting Fibonacci number
    printf("Fibonacci number at position %u is %llu\n", n, fib_curr);

    return 0;
}