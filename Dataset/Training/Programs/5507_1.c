/*
 * Example Program based on learned patterns and structures.
 * This program calculates the Fibonacci sequence and verifies a property.
 * Author: OpenAI
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_fib.c", 10, "reach_error"); }

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
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);

    // Initialize Fibonacci sequence
    long long fib1 = 0, fib2 = 1, current;
    int i;

    if (n == 0) {
        current = fib1;
    } else if (n == 1) {
        current = fib2;
    } else {
        for (i = 2; i <= n; i++) {
            current = fib1 + fib2;
            fib1 = fib2;
            fib2 = current;
        }
    }

    // Simple property check: The Fibonacci number should be non-negative
    __VERIFIER_assert(current >= 0);

    // Output the nth Fibonacci number
    printf("Fibonacci(%d) = %lld\n", n, current);

    return 0;
}