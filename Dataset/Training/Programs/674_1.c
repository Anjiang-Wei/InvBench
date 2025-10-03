/*
Fibonacci Series Verification
Computes the Fibonacci sequence and verifies the properties of the Fibonacci numbers.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

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

unsigned int fibonacci(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int fib = 0;

    unsigned int i = 2;
    while (i <= n) {
        fib = a + b;
        a = b;
        b = fib;
        i++;
    }
    return fib;
}

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 10); // Limit the range for verification purposes

    unsigned int fib_n = fibonacci(n);
    unsigned int fib_n_1 = fibonacci(n - 1);
    unsigned int fib_n_2 = fibonacci(n - 2);

    // Verify the property of the Fibonacci sequence: F(n) = F(n-1) + F(n-2)
    if (n >= 2) {
        __VERIFIER_assert(fib_n == fib_n_1 + fib_n_2);
    }

    printf("F(%u) = %u\n", n, fib_n);
    return 0;
}