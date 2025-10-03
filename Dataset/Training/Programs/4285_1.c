/*
Fibonacci Sequence Verification
This program computes Fibonacci numbers iteratively and verifies a mathematical property.
The property states that the nth Fibonacci number can be expressed as:
F(n) = F(n-1) + F(n-2) for n >= 2
The program uses assertions to verify this property.
*/

#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
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
    unsigned int a = 0, b = 1, c;
    for (unsigned int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return (n == 0) ? 0 : b;
}

int main() {
    unsigned int n;
    n = 10; // Example input, can replace with a nondet function if needed

    unsigned int fib_n_1, fib_n_2, fib_n;
    assume_abort_if_not(n >= 2);

    fib_n_1 = fibonacci(n - 1);
    fib_n_2 = fibonacci(n - 2);
    fib_n = fibonacci(n);

    __VERIFIER_assert(fib_n == fib_n_1 + fib_n_2);

    printf("F(%u) = %u, F(%u) = %u, F(%u) = %u\n", n, fib_n, n - 1, fib_n_1, n - 2, fib_n_2);
    return 0;
}