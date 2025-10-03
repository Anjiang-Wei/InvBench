/*
Fibonacci Sequence Verification
This program computes the first 'n' Fibonacci numbers and verifies a condition at each step.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }

extern void abort(void);
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
void *malloc(unsigned int size);

const int MAX_FIB = 47; // Maximum number of Fibonacci numbers to compute

int main() {
    int n = __VERIFIER_nondet_int();

    if (n < 0 || n > MAX_FIB) {
        return 0;
    }

    int *fib = (int *)malloc(sizeof(int) * (n + 1));
    if (n >= 0) {
        fib[0] = 0;
    }
    if (n >= 1) {
        fib[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        // Check the condition at each step; every Fibonacci number should be non-negative
        __VERIFIER_assert(fib[i] >= 0);
    }

    // Additional logic (e.g., printing the Fibonacci sequence)
    for (int i = 0; i <= n; i++) {
        printf("Fib[%d] = %d\n", i, fib[i]);
    }

    free(fib);
    return 0;
}