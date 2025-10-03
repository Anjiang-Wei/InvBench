/* A simple C program that computes Fibonacci numbers using a loop.
   This program demonstrates a pattern similar to the given examples
   by applying a simple mathematical computation and using verification
   tools to ensure constraints are met.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 4, "reach_error"); }
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

#define MAX_SIZE 50

int fibonacci(int n) {
    int fib[MAX_SIZE];
    fib[0] = 0;
    fib[1] = 1;

    int i;
    for (i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < MAX_SIZE);

    int result = fibonacci(n);
    __VERIFIER_assert(result >= 0); // Assert that Fibonacci numbers are non-negative

    printf("Fibonacci number at position %d is %d\n", n, result);
    return 0;
}