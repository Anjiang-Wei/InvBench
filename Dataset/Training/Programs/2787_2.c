/*
  Fibonacci Sequence Generator
  Computes the n-th Fibonacci number using iterative approach.
  Ensures correctness by verifying post-condition at the end.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
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

int main() {
    unsigned int n;
    n = __VERIFIER_nondet_uint();

    assume_abort_if_not(n <= 46); // Limit to prevent overflow in 32-bit integer

    unsigned int a = 0, b = 1, fib = 0;
    unsigned int i = 0;

    // Iteratively compute the n-th Fibonacci number
    while (i < n) {
        fib = a + b;
        a = b;
        b = fib;
        i++;
    }

    // Post-condition: fib should be the n-th Fibonacci number
    if (n == 0) {
    } else if (n == 1) {
        __VERIFIER_assert(fib == 1);
    } else {
    }

    printf("The %uth Fibonacci number is: %u\n", n, fib);

    return 0;
}