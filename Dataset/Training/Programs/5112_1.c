#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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
    return;
}

unsigned int fibonacci(unsigned int n) {
    if (n <= 1) {
        return n;
    }
    unsigned int a = 0, b = 1, fib = 0;
    for (unsigned int i = 2; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    unsigned int n = __VERIFIER_nondet_int();

    // Ensure n is within a reasonable range to compute Fibonacci numbers
    assume_abort_if_not(n >= 0 && n <= 47);

    unsigned int fib_n = fibonacci(n);

    // Check the 10th Fibonacci using a known expected value
    unsigned int expected_fib_10 = 55;
    if (n == 10) {
        __VERIFIER_assert(fib_n == expected_fib_10);
    }

    printf("Fibonacci(%u) = %u\n", n, fib_n);

    return 0;
}