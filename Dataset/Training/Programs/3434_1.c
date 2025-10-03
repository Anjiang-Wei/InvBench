// SPDX-License-Identifier: Apache-2.0

#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-verify.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Ensure n is a small positive integer

    long long sum = 0;
    int i = 0;

    while (i <= n) {
        int fib = fibonacci(i);
        __VERIFIER_assert(fib >= 0); // Fibonacci numbers should be non-negative
        sum += fib;
        i++;
    }

    // Ensure the sum of first n Fibonacci numbers is non-negative
    return 0;
}