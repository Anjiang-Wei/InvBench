#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci_verification.c", 11, "reach_error"); }

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

unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 20);

    unsigned long long a = 0, b = 1;
    unsigned long long fib;

    for (unsigned int i = 0; i < n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }

    // Check a property about Fibonacci numbers: fib(n) is correctly computed
    if (n == 0) {
    } else if (n == 1) {
        __VERIFIER_assert(a == 1);
    } else {
    }

    // Print Fibonacci number
    printf("Fib(%u) = %llu\n", n, fib);

    return 0;
}